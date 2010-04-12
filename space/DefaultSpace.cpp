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

//Orbital Camera Controller
void DefaultSpace::updateCamera(float dt) {

    //interpolate cameraPosition cameraPositionNext
    if (dt > 0) {
        float dcameraSpeed = dt * cameraSpeed;
        camTarget = (1.0 - dcameraSpeed) * camTarget + (dcameraSpeed) * camTargetNext;
        camDist = (1.0 - dcameraSpeed) * camDist + (dcameraSpeed) * camDistNext;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float rele = m_ele * 0.01745329251994329547; // rads per deg
    float razi = m_azi * 0.01745329251994329547; // rads per deg


    btQuaternion rot(camUp, razi);


    btVector3 eyePos(0, 0, 0);
    eyePos[m_forwardAxis] = -camDist;

    btVector3 forward(eyePos[0], eyePos[1], eyePos[2]);
    if (forward.length2() < SIMD_EPSILON) {
        forward.setValue(1.f, 0.f, 0.f);
    }
    m_cameraRight = (camUp.cross(forward));
    btQuaternion roll(m_cameraRight, -rele);

    eyePos = btMatrix3x3(rot) * btMatrix3x3(roll) * eyePos;

    camPos = eyePos + camTarget;

    if (m_glutScreenWidth == 0 && m_glutScreenHeight == 0)
        return;

    btScalar aspect;
    btVector3 extents;

    if (m_glutScreenWidth > m_glutScreenHeight) {
        aspect = m_glutScreenWidth / (btScalar) m_glutScreenHeight;
        extents.setValue(aspect * 1.0f, 1.0f, 0);
    } else {
        aspect = m_glutScreenHeight / (btScalar) m_glutScreenWidth;
        extents.setValue(1.0f, aspect * 1.f, 0);
    }


    if (m_ortho) {
        glLoadIdentity(); // reset matrix

        extents *= camDist;
        btVector3 lower = camTarget - extents;
        btVector3 upper = camTarget + extents;
        glOrtho(lower.getX(), upper.getX(), lower.getY(), upper.getY(), -1000, 1000);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    } else {
        float near = 1.0;
        float far = 1000;
        if (m_glutScreenWidth > m_glutScreenHeight) {
            glFrustum(-aspect, aspect, -1.0, 1.0, near, far);
        } else {
            glFrustum(-1.0, 1.0, -aspect, aspect, near, far);
        }
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        rayForward = getCameraTargetPosition() - getCameraPosition();
        rayForward.normalize();

        gluLookAt(camPos[0], camPos[1], camPos[2],
                camTarget[0], camTarget[1], camTarget[2],
                camUp[0], camUp[1], camUp[2]);
    }

}


void DefaultSpace::onMouseButton(int button, int state, int x, int y) {


    if (button == 2) {
        if (state == 1) {

            if (touchedBody != NULL) {
                //cout << "zooming to " << touchedBody << "\n";
                
                //void* manager = body->getUserPointer();
                camTargetNext = touchedBody->getWorldTransform().getOrigin();

                btVector3 center;
                btScalar radius;
                touchedBody->getCollisionShape()->getBoundingSphere(center, radius);

                camDistNext = radius*1.3;
                //btVector3 d(0,1,0);
                //m_cameraPositionNext = m_cameraTargetPositionNext + d;
            }


        }
    }

    if (!faceContainer.onMouseButton(button, state, x, y)) {
        if (state == 0) {
            m_mouseButtons |= 1 << button;
        } else {
            m_mouseButtons = 0;
        }

        pointerPixelX = x;
        pointerPixelY = y;

        updateModifierKeys();
        if ((m_modifierKeys & BT_ACTIVE_ALT) && (state == 0)) {
            return;
        }

        //printf("button %i, state %i, x=%i,y=%i\n",button,state,x,y);
        //button 0, state 0 means left mouse down

        btVector3 rayTo = getRayTo(x, y);

        switch (button) {
            case 2:
            {

                //			if (state==0)
                //			{
                //
                //				shootBox(rayTo);
                //			}
                break;
            };
            case 1:
            {


                if (state == 0) {

#if 0
                    //apply an impulse
                    if (dynamicsWorld) {
                        btCollisionWorld::ClosestRayResultCallback rayCallback(camPos, rayTo);
                        dynamicsWorld->rayTest(camPos, rayTo, rayCallback);
                        if (rayCallback.hasHit()) {

                            btRigidBody* body = btRigidBody::upcast(rayCallback.m_collisionObject);
                            if (body) {
                                body->setActivationState(ACTIVE_TAG);
                                btVector3 impulse = rayTo;
                                impulse.normalize();
                                float impulseStrength = 10.f;
                                impulse *= impulseStrength;
                                btVector3 relPos = rayCallback.m_hitPointWorld - body->getCenterOfMassPosition();
                                body->applyImpulse(impulse, relPos);
                            }
                        }
                    }
#endif



                } else {

                }
                break;
            }
            case 0:
            {
                if (state == 0) {


                    //add a point to point constraint for picking
                    if (dynamicsWorld) {

                        btVector3 rayFrom;
                        if (m_ortho) {
                            rayFrom = rayTo;
                            rayFrom.setZ(-100.f);
                        } else {
                            rayFrom = camPos;
                        }

                        btCollisionWorld::ClosestRayResultCallback rayCallback(rayFrom, rayTo);
                        dynamicsWorld->rayTest(rayFrom, rayTo, rayCallback);
                        if (rayCallback.hasHit()) {


                            btRigidBody* body = btRigidBody::upcast(rayCallback.m_collisionObject);
                            if (body) {
                                //other exclusions?
                                if (!(body->isStaticObject() || body->isKinematicObject())) {
                                    pickedBody = body;
                                    pickedBody->setActivationState(DISABLE_DEACTIVATION);


                                    btVector3 pickPos = rayCallback.m_hitPointWorld;
                                    //printf("pickPos=%f,%f,%f\n",pickPos.getX(),pickPos.getY(),pickPos.getZ());


                                    btVector3 localPivot = body->getCenterOfMassTransform().inverse() * pickPos;

                                    btPoint2PointConstraint* p2p = new btPoint2PointConstraint(*body, localPivot);
                                    p2p->m_setting.m_impulseClamp = mousePickClamping;

                                    dynamicsWorld->addConstraint(p2p);
                                    m_pickConstraint = p2p;

                                    //save mouse position for dragging
                                    gOldPickingPos = rayTo;
                                    gHitPos = pickPos;

                                    gOldPickingDist = (pickPos - rayFrom).length();

                                    //very weak constraint for picking
                                    p2p->m_setting.m_tau = 0.1f;
                                }
                            }
                        }
                    }

                } else {

                    if (m_pickConstraint && dynamicsWorld) {
                        dynamicsWorld->removeConstraint(m_pickConstraint);
                        delete m_pickConstraint;
                        //printf("removed constraint %i",gPickingConstraintId);
                        m_pickConstraint = 0;
                        pickedBody->forceActivationState(ACTIVE_TAG);
                        pickedBody->setDeactivationTime(0.f);

                        pickedBody = 0;
                    }


                }

                break;

            }
            default:
            {
            }
        }
    }

}


void DefaultSpace::onMouseMove(int x, int y) {
    if (!faceContainer.onMouseMove(x, y)) {

        if (m_pickConstraint) {
            //move the constraint pivot
            btPoint2PointConstraint* p2p = static_cast<btPoint2PointConstraint*> (m_pickConstraint);
            if (p2p) {
                //keep it at the same picking distance

                btVector3 newRayTo = getRayTo(x, y);
                btVector3 rayFrom;
                btVector3 oldPivotInB = p2p->getPivotInB();
                btVector3 newPivotB;
                if (m_ortho) {
                    newPivotB = oldPivotInB;
                    newPivotB.setX(newRayTo.getX());
                    newPivotB.setY(newRayTo.getY());
                } else {
                    rayFrom = camPos;
                    btVector3 dir = newRayTo - rayFrom;
                    dir.normalize();
                    dir *= gOldPickingDist;

                    newPivotB = rayFrom + dir;
                }



                p2p->setPivotB(newPivotB);
            }

        }

        float dx, dy;
        dx = x - pointerPixelX;
        dy = y - pointerPixelY;

        if (m_mouseButtons & 4) {
            m_azi += dx * 0.2;
            m_azi = fmodf(m_azi, 360.f);
            m_ele += dy * 0.2;
            m_ele = fmodf(m_ele, 180.f);
        }
        if (m_mouseButtons & 2) {
            camDistNext -= dy * 0.2f;
            if (camDistNext < 0.1)
                camDistNext = 0.1;

            //		btVector3 hor = getRayTo(0,0)-getRayTo(1,0);
            //		btVector3 vert = getRayTo(0,0)-getRayTo(0,1);
            //		btScalar multiplierX = 0.01;
            //		btScalar multiplierY = 0.01;
            //		if (m_ortho)
            //		{
            //			multiplierX = 1;
            //			multiplierY = 1;
            //		}
            //
            //
            //		m_cameraTargetPositionNext += hor* dx * multiplierX;
            //		m_cameraTargetPositionNext += vert* dy * multiplierY;
        }

        ///only if ALT key is pressed (Maya style)
        if (m_modifierKeys & BT_ACTIVE_ALT) {

            if (m_mouseButtons & (2 << 2) && m_mouseButtons & 1) {
            } else if (m_mouseButtons & 4) {


            }
        }


        pointerPixelX = x;
        pointerPixelY = y;
        //updateCamera(0);
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

    dynamicsWorld->setGravity(btVector3(0, 0, 0));

    clientResetScene();
}

btRigidBody* DefaultSpace::addGround(float w, float h, float d, float x, float y, float z) {
    // Setup a big ground box
    btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(w), btScalar(h), btScalar(d)));
    m_collisionShapes.push_back(groundShape);
    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(btVector3(x, y, z));
    btRigidBody* groundBody = localCreateRigidBody(btScalar(0.), groundTransform, groundShape);
    dynamicsWorld->setGravity(btVector3(0, -10, 0));
    return groundBody;
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

    updateCamera(deltaTime);

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

    updateCamera(0);

    glFlush();
    glutSwapBuffers();

    updatePointer();
}

void DefaultSpace::updatePointer() {
    float pickDistance = 100.0f;
    btVector3 rayTo = getRayTo(pointerPixelX, pointerPixelY);

    touchedBody = NULL;
    touched = NULL;

    //add a point to point constraint for picking
    if (dynamicsWorld) {

        btVector3 rayFrom;
        if (m_ortho) {
            rayFrom = rayTo;
            rayFrom.setZ(-pickDistance);
        } else {
            rayFrom = camPos;
        }

        btCollisionWorld::ClosestRayResultCallback rayCallback(rayFrom, rayTo);
        dynamicsWorld->rayTest(rayFrom, rayTo, rayCallback);
        if (rayCallback.hasHit()) {


            btRigidBody* body = btRigidBody::upcast(rayCallback.m_collisionObject);
            if (body) {
                touchedBody = body;
                touched = body;
                
                //other exclusions?
                if (!(body->isStaticObject() || body->isKinematicObject())) {
                    pickedBody = body;
                    pickedBody->setActivationState(DISABLE_DEACTIVATION);


                    touchPosWorld = rayCallback.m_hitPointWorld;
                    touchPosLocal = body->getCenterOfMassTransform().inverse() * touchPosWorld;

                    AbstractBody* abody = NULL;
                    //TODO this is a hack to find the AbstractBody that manages a specific part
                    for (unsigned j = 0; j < bodies.size(); j++) {
                        AbstractBody* metaBody = bodies[j];
                        int index = metaBody->indexOfPart(pickedBody);
                        if (index != -1) {
                            abody = metaBody;
                            break;
                        }
                    }

                    if (abody!=NULL) {
                        abody->onTouch(&touchPosWorld, &touchPosLocal);
                        //printf("pickPos=%f,%f,%f\n",touchPosWorld.getX(),touchPosWorld.getY(),touchPosWorld.getZ());
                        //printf("localPiv=%f,%f,%f\n",touchPosLocal.getX(),touchPosLocal.getY(),touchPosLocal.getZ());
                    }

                }
            }
        }
    }

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


        AbstractBody* abody = NULL;

        //TODO this is a hack to find the AbstractBody that manages a specific part
        for (unsigned j = 0; j < bodies.size(); j++) {
            AbstractBody* metaBody = bodies[j];
            int index = metaBody->indexOfShape(shape);
            if (index != -1) {
                shapeColor = metaBody->getColor(shape);
                //shape->setUserPointer(metaBody);
                abody = metaBody;
                break;
            }
        }

        switch (pass) {
            case 0:
                m_shapeDrawer->drawOpenGL(m, shape, abody, shapeColor, getDebugMode(), aabbMin, aabbMax);
                break;
            case 1:
                m_shapeDrawer->drawShadow(m, m_sundirection * rot, shape, aabbMin, aabbMax);
                break;
            case 2:
                m_shapeDrawer->drawOpenGL(m, shape, abody, shapeColor * 0.3, 0, aabbMin, aabbMax);
                break;
        }


    }

    for (unsigned b = 0; b < bodies.size(); b++) {
        bodies[b]->draw();
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


//Orbital Camera Controller
//void DefaultSpace::updateCamera(float dt) {
//
//    //interpolate cameraPosition cameraPositionNext
//    if (dt > 0) {
//        float dcameraSpeed = dt * cameraSpeed;
//        camTarget = (1.0 - dcameraSpeed) * camTarget + (dcameraSpeed) * camTargetNext;
//        camDist = (1.0 - dcameraSpeed) * camDist + (dcameraSpeed) * camDistNext;
//    }
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    float rele = m_ele * 0.01745329251994329547; // rads per deg
//    float razi = m_azi * 0.01745329251994329547; // rads per deg
//
//
//    btQuaternion rot(camUp, razi);
//
//
//    btVector3 eyePos(0, 0, 0);
//    eyePos[m_forwardAxis] = -camDist;
//
//    btVector3 forward(eyePos[0], eyePos[1], eyePos[2]);
//    if (forward.length2() < SIMD_EPSILON) {
//        forward.setValue(1.f, 0.f, 0.f);
//    }
//    m_cameraRight = (camUp.cross(forward));
//    btQuaternion roll(m_cameraRight, -rele);
//
//    eyePos = btMatrix3x3(rot) * btMatrix3x3(roll) * eyePos;
//
//    camPos = eyePos + camTarget;
//
//    if (m_glutScreenWidth == 0 && m_glutScreenHeight == 0)
//        return;
//
//    btScalar aspect;
//    btVector3 extents;
//
//    if (m_glutScreenWidth > m_glutScreenHeight) {
//        aspect = m_glutScreenWidth / (btScalar) m_glutScreenHeight;
//        extents.setValue(aspect * 1.0f, 1.0f, 0);
//    } else {
//        aspect = m_glutScreenHeight / (btScalar) m_glutScreenWidth;
//        extents.setValue(1.0f, aspect * 1.f, 0);
//    }
//
//
//    if (m_ortho) {
//        glLoadIdentity(); // reset matrix
//
//        extents *= camDist;
//        btVector3 lower = camTarget - extents;
//        btVector3 upper = camTarget + extents;
//        glOrtho(lower.getX(), upper.getX(), lower.getY(), upper.getY(), -1000, 1000);
//
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//    } else {
//        if (m_glutScreenWidth > m_glutScreenHeight) {
//            glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 10000.0);
//        } else {
//            glFrustum(-1.0, 1.0, -aspect, aspect, 1.0, 10000.0);
//        }
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//
//        rayForward = getCameraTargetPosition() - getCameraPosition();
//        rayForward.normalize();
//
//        gluLookAt(camPos[0], camPos[1], camPos[2],
//                camTarget[0], camTarget[1], camTarget[2],
//                camUp[0], camUp[1], camUp[2]);
//    }
//
//}
