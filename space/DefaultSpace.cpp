/*
 Bullet Continuous Collision Detection and Physics Library Copyright (c) 2007 Erwin Coumans
 Motor Demo

 This software is provided 'as-is', without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from the use of this software.
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it freely,
 subject to the following restrictions:

 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 */

#include <iostream>

#include <FTGL/ftgl.h>
#include "../video/font/FontDemo1.h"

#include "../neural/Brain.h"

#include "../physics/btBulletDynamicsCommon.h"
#include "../physics/OpenGL/GlutStuff.h"
#include "../physics/OpenGL/GL_ShapeDrawer.h"

#include "../physics/LinearMath/btIDebugDraw.h"

#include "../physics/OpenGL/GLDebugDrawer.h"
#include "DefaultSpace.h"
#include <math.h>

#include "AbstractBody.h"

// LOCAL FUNCTIONS

void vertex(btVector3 &v) {
    glVertex3d(v.getX(), v.getY(), v.getZ());
}

void drawAxes(btTransform &tr) {
    const float fSize = 1.f;

    glBegin(GL_LINES);

    // x
    glColor3f(255.f, 0, 0);
    btVector3 vX = tr * btVector3(fSize, 0, 0);
    vertex(tr.getOrigin());
    vertex(vX);

    // y
    glColor3f(0, 255.f, 0);
    btVector3 vY = tr * btVector3(0, fSize, 0);
    vertex(tr.getOrigin());
    vertex(vY);

    // z
    glColor3f(0, 0, 255.f);
    btVector3 vZ = tr * btVector3(0, 0, fSize);
    vertex(tr.getOrigin());
    vertex(vZ);

    glEnd();
}

void DefaultSpace::onMouseButton(int button, int state, int x, int y) {

    if (!faceContainer.onMouseButton(button, state, x, y)) {
        SpaceProcess::onMouseButton(button, state, x, y);
    }

}

void DefaultSpace::onMouseMove(int x, int y) {

    if (!faceContainer.onMouseMove(x, y)) {
        SpaceProcess::onMouseMove(x, y);
    }

}

void afterPhysics(btDynamicsWorld *world, btScalar timeStep) {
    DefaultSpace* motorDemo = (DefaultSpace*) world->getWorldUserInfo();

    motorDemo->process(timeStep);

}

void DefaultSpace::reshape(int w, int h) {
    AbstractSpace::reshape(w, h);
}

void DefaultSpace::initPhysics() {

    setTexturing(true);
    setShadows(true);

    // Setup the basic world

    m_Time = 0;

    //	m_fMuscleStrength = 0.05f;
    // new SIMD solver for joints clips accumulated impulse, so the new limits for the motor
    // should be (numberOfsolverIterations * oldLimits)
    // currently solver uses 10 iterations, so:

    m_collisionConfiguration = new btDefaultCollisionConfiguration();

    m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);

    btVector3 worldAabbMin(-10000, -10000, -10000);
    btVector3 worldAabbMax(10000, 10000, 10000);
    m_broadphase = new btAxisSweep3(worldAabbMin, worldAabbMax);

    m_solver = new btSequentialImpulseConstraintSolver;

    dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase,
            m_solver, m_collisionConfiguration);

    dynamicsWorld->setInternalTickCallback(afterPhysics, this, true);

    dynamicsWorld->setGravity(btVector3(0,0,0));
    
    clientResetScene();
}

void DefaultSpace::addGround(double x, double y, double z) {
    // Setup a big ground box
    btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(x), btScalar(z), btScalar(y)));
    m_collisionShapes.push_back(groundShape);
    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(btVector3(0, -10, 0));
    localCreateRigidBody(btScalar(0.), groundTransform, groundShape);
    dynamicsWorld->setGravity(btVector3(0,-10,0));
}

void DefaultSpace::addBody(AbstractBody* a) {
    a->init(this);
    bodies.push_back(a);
}

void DefaultSpace::removeBody(AbstractBody* a) {
    bodies.remove(a);
}

void PreStep() {

}

void DefaultSpace::process(btScalar deltaTime) {

    float ms = deltaTime * 1000000.;
    float minFPS = 1000000.f / 60.f;
    if (ms > minFPS)
        ms = minFPS;

    m_Time += ms;

    //
    // set per-frame sinusoidal position targets using angular motor (hacky?)
    //
    AbstractBody* t;
    int r;
#pragma omp parallel for private(r, t)
    for (r = 0; r < bodies.size(); r++) {
        t = bodies[r];
        t->process(deltaTime);
    }

}

void DefaultSpace::clientMoveAndDisplay() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //simple dynamics world doesn't handle fixed-time-stepping
    float deltaTime = getDeltaTimeMicroseconds() / 1000000.f;

    if (dynamicsWorld) {
        dynamicsWorld->stepSimulation(deltaTime);
        dynamicsWorld->debugDrawWorld();
    }

    preDraw();

    updateCamera();

    if (dynamicsWorld) {
        if (m_enableshadows) {
            glClear(GL_STENCIL_BUFFER_BIT);
            glEnable(GL_CULL_FACE);
            renderscene(0);

            glDisable(GL_LIGHTING);
            glDepthMask(GL_FALSE);
            glDepthFunc(GL_LEQUAL);
            glEnable(GL_STENCIL_TEST);
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFFL);
            glFrontFace(GL_CCW);
            glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);
            renderscene(1);
            glFrontFace(GL_CW);
            glStencilOp(GL_KEEP, GL_KEEP, GL_DECR);
            renderscene(1);
            glFrontFace(GL_CCW);

            glPolygonMode(GL_FRONT, GL_FILL);
            glPolygonMode(GL_BACK, GL_FILL);
            glShadeModel(GL_SMOOTH);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glEnable(GL_LIGHTING);
            glDepthMask(GL_TRUE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CCW);
            glEnable(GL_CULL_FACE);
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

            glDepthFunc(GL_LEQUAL);
            glStencilFunc(GL_NOTEQUAL, 0, 0xFFFFFFFFL);
            glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
            glDisable(GL_LIGHTING);
            renderscene(2);
            glEnable(GL_LIGHTING);
            glDepthFunc(GL_LESS);
            glDisable(GL_STENCIL_TEST);
            glDisable(GL_CULL_FACE);
        } else {
            glDisable(GL_CULL_FACE);
            renderscene(0);
        }

        //        int xOffset = 10;
        //        int yStart = 20;
        //        int yIncr = 20;
        //        char buf[124];
        //
        //        glDisable(GL_LIGHTING);
        //        glColor3f(0, 0, 0);
        //
        //
        //        glEnable(GL_LIGHTING);

    }

    {
        setOrthographicProjection();

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_COLOR_MATERIAL);

        faceContainer.draw();
    }



    updateCamera();

    glFlush();
    glutSwapBuffers();

}

void DefaultSpace::onKeyboard(unsigned char key, int x, int y) {
    switch (key) {
            //	case '+':
            //	case '=':
            //		m_fCyclePeriod /= 1.1f;
            //		if (m_fCyclePeriod < 1.f)
            //			m_fCyclePeriod = 1.f;
            //		break;
            //	case '-':
            //	case '_':
            //		m_fCyclePeriod *= 1.1f;
            //		break;
            //        //	case '[':
            //        //		m_fMuscleStrength /= 1.1f;
            //        //		break;
            //        //	case ']':
            //        //		m_fMuscleStrength *= 1.1f;
            //        //		break;

        case 'l': stepLeft();
            break;
        case 'r': stepRight();
            break;
        case 'f': stepFront();
            break;
        case 'b': stepBack();
            break;
        case 'z': zoomIn();
            break;
        case 'x': zoomOut();
            break;

        default:
            SpaceProcess::onKeyboard(key, x, y);
    }
}

void DefaultSpace::exitPhysics() {

    int i;

    for (i = 0; i < bodies.size(); i++) {
        AbstractBody* rig = bodies[i];
        delete rig;
    }

    //cleanup in the reverse order of creation/initialization

    //remove the rigidbodies from the dynamics world and delete them

    for (i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--) {
        btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
        btRigidBody* body = btRigidBody::upcast(obj);
        if (body && body->getMotionState()) {
            delete body->getMotionState();
        }
        dynamicsWorld->removeCollisionObject(obj);
        delete obj;
    }

    //delete collision shapes
    for (int j = 0; j < m_collisionShapes.size(); j++) {
        btCollisionShape* shape = m_collisionShapes[j];
        delete shape;
    }

    //delete dynamics world
    delete dynamicsWorld;

    //delete solver
    delete m_solver;

    //delete broadphase
    delete m_broadphase;

    //delete dispatcher
    delete m_dispatcher;

    delete m_collisionConfiguration;
}

void DefaultSpace::renderscene(int pass) {

    btScalar m[16];
    btMatrix3x3 rot;
    rot.setIdentity();
    const unsigned numObjects = dynamicsWorld->getNumCollisionObjects();

    //	for (unsigned i = 0; i < bodies.size(); i++) {
    //		AbstractBody* metaBody = bodies[i];
    //
    //		for (unsigned p = 0; p < metaBody->bodies.size(); p++) {
    //			//btCollisionObject* colObj = metaBody->shapes[p];
    //
    //			//btCollisionObject* colObj = m_dynamicsWorld->getCollisionObjectArray();
    //			btRigidBody* body = btRigidBody::upcast(metaBody->bodies[p]);
    //
    //
    //		}
    //	}

    for (unsigned int i = 0; i < numObjects; i++) {
        btCollisionObject* colObj = dynamicsWorld->getCollisionObjectArray()[i];
        btRigidBody* body = btRigidBody::upcast(colObj);
        btCollisionShape* shape = body->getCollisionShape();

        if (body && body->getMotionState()) {
            btDefaultMotionState* myMotionState =
                    (btDefaultMotionState*) body->getMotionState();
            myMotionState->m_graphicsWorldTrans.getOpenGLMatrix(m);
            rot = myMotionState->m_graphicsWorldTrans.getBasis();
        } else {
            colObj->getWorldTransform().getOpenGLMatrix(m);
            rot = colObj->getWorldTransform().getBasis();
        }
        //		btVector3 wireColor(1.f,1.0f,0.5f); //wants deactivation
        //		if(i&1) wireColor=btVector3(0.f,0.0f,1.f);
        //		///color differently for active, sleeping, wantsdeactivation states
        //		if (colObj->getActivationState() == 1) //active
        //		{
        //			if (i & 1)
        //			{
        //				wireColor += btVector3 (1.f,0.f,0.f);
        //			}
        //			else
        //			{
        //				wireColor += btVector3 (.5f,0.f,0.f);
        //			}
        //		}
        //		if(colObj->getActivationState()==2) //ISLAND_SLEEPING
        //		{
        //			if(i&1)
        //			{
        //				wireColor += btVector3 (0.f,1.f, 0.f);
        //			}
        //			else
        //			{
        //				wireColor += btVector3 (0.f,0.5f,0.f);
        //			}
        //		}

        btVector3 aabbMin, aabbMax;
        dynamicsWorld->getBroadphase()->getBroadphaseAabb(aabbMin,
                aabbMax);

        aabbMin
                -= btVector3(BT_LARGE_FLOAT, BT_LARGE_FLOAT, BT_LARGE_FLOAT);
        aabbMax
                += btVector3(BT_LARGE_FLOAT, BT_LARGE_FLOAT, BT_LARGE_FLOAT);
        //		printf("aabbMin=(%f,%f,%f)\n",aabbMin.getX(),aabbMin.getY(),aabbMin.getZ());
        //		printf("aabbMax=(%f,%f,%f)\n",aabbMax.getX(),aabbMax.getY(),aabbMax.getZ());
        //		m_dynamicsWorld->getDebugDrawer()->drawAabb(aabbMin,aabbMax,btVector3(1,1,1));

        btVector3 shapeColor(0.75, 0.75, 0.75);

        //TODO this is a hack to find the AbstractBody that manages a specific part
        for (unsigned j = 0; j < bodies.size(); j++) {
            AbstractBody* metaBody = bodies[j];
            int index = metaBody->indexOfShape(shape);
            if (index != -1) {
                shapeColor = metaBody->getColor(shape);
                break;
            }
        }

        switch (pass) {
            case 0:
                m_shapeDrawer->drawOpenGL(m, shape,
                        shapeColor, getDebugMode(), aabbMin, aabbMax);
                break;
            case 1:
                m_shapeDrawer->drawShadow(m, m_sundirection * rot,
                        shape, aabbMin, aabbMax);
                break;
            case 2:
                m_shapeDrawer->drawOpenGL(m, shape,
                        shapeColor * 0.3, 0, aabbMin, aabbMax);
                break;
        }

    }
}

void DefaultSpace::draw() {
    //	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //
    //	renderme();
    //
    //	if (dynamicsWorld)
    //		dynamicsWorld->debugDrawWorld();
    //
    //	float ms = getDeltaTimeMicroseconds();
    //	if (m_dialogDynamicsWorld != NULL)
    //		m_dialogDynamicsWorld->draw(ms / 1000000.f);
    //
    //	glFlush();
    //	glutSwapBuffers();
}

Container* DefaultSpace::getFace() {
    return &faceContainer;
}