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

void drawFrame(btTransform &tr) {
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



void DefaultSpace::mouseFunc(int button, int state, int x, int y) {

	if (m_dialogDynamicsWorld != NULL) {
		if (!m_dialogDynamicsWorld->mouseFunc(button, state, x, y)) {
			SpaceProcess::mouseFunc(button, state, x, y);
		}
	} else {
		SpaceProcess::mouseFunc(button, state, x, y);
	}
}

void DefaultSpace::mouseMotionFunc(int x, int y) {
	if (m_dialogDynamicsWorld != NULL)
		m_dialogDynamicsWorld->mouseMotionFunc(x, y);

	SpaceProcess::mouseMotionFunc(x, y);
}

void motorPreTickCallback(btDynamicsWorld *world, btScalar timeStep) {
	DefaultSpace* motorDemo = (DefaultSpace*) world->getWorldUserInfo();

	motorDemo->process(timeStep);

}

void DefaultSpace::reshape(int w, int h) {
	if (m_dialogDynamicsWorld)
		m_dialogDynamicsWorld->setScreenSize(w, h);
	AbstractSpace::reshape(w, h);
}

void DefaultSpace::initPhysics() {

	setTexturing(true);
	setShadows(true);

	// Setup the basic world

	m_Time = 0;
	m_fCyclePeriod = 2000.f; // in milliseconds

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

	dynamicsWorld->setInternalTickCallback(motorPreTickCallback, this, true);

	// Setup a big ground box
	{
		btCollisionShape* groundShape = new btBoxShape(btVector3(
				btScalar(200.), btScalar(10.), btScalar(200.)));
		m_collisionShapes.push_back(groundShape);
		btTransform groundTransform;
		groundTransform.setIdentity();
		groundTransform.setOrigin(btVector3(0, -10, 0));
		localCreateRigidBody(btScalar(0.), groundTransform, groundShape);
	}


	//	startOffset.setValue(-2, 0.5, 0);
	//	newSpider(startOffset, 1, 6);

	//init gui
	m_dialogDynamicsWorld = NULL;
	//	{
	//		m_dialogDynamicsWorld = new GL_DialogDynamicsWorld();
	//
	//		//m_dialogDynamicsWorld->createDialog(100,110,200,50);
	//		//m_dialogDynamicsWorld->createDialog(100,00,100,100);
	//		//m_dialogDynamicsWorld->createDialog(0,0,100,100);
	//		GL_DialogWindow* settings = m_dialogDynamicsWorld->createDialog(50, 0,
	//				200, 120, "Settings");
	//		GL_ToggleControl* toggle = m_dialogDynamicsWorld->createToggle(
	//				settings, "Toggle 1");
	//		toggle = m_dialogDynamicsWorld->createToggle(settings, "Toggle 2");
	//		toggle ->m_active = true;
	//		toggle = m_dialogDynamicsWorld->createToggle(settings, "Toggle 3");
	//		GL_SliderControl* slider = m_dialogDynamicsWorld->createSlider(
	//				settings, "Slider");
	//
	//		GL_DialogWindow* dialog = m_dialogDynamicsWorld->createDialog(0, 200,
	//				420, 300, "Help");
	//
	//		GL_TextControl* txt = new GL_TextControl;
	//		dialog->addControl(txt);
	//		txt->m_textLines.push_back("Mouse to move");
	//		txt->m_textLines.push_back("Test 2");
	//		txt->m_textLines.push_back("mouse to interact");
	//		txt->m_textLines.push_back("ALT + mouse to move camera");
	//		txt->m_textLines.push_back("space to reset");
	//		txt->m_textLines.push_back("cursor keys and z,x to navigate");
	//		txt->m_textLines.push_back("i to toggle simulation, s single step");
	//		txt->m_textLines.push_back("q to quit");
	//		txt->m_textLines.push_back(". to shoot box");
	//		txt->m_textLines.push_back("d to toggle deactivation");
	//		txt->m_textLines.push_back("g to toggle mesh animation (ConcaveDemo)");
	//		txt->m_textLines.push_back("h to toggle help text");
	//		txt->m_textLines.push_back("o to toggle orthogonal/perspective view");
	//		//txt->m_textLines.push_back("+- shooting speed = %10.2f",m_ShootBoxInitialSpeed);
	//
	//
	//	}

	clientResetScene();
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
	static FTFont *font = NULL;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//simple dynamics world doesn't handle fixed-time-stepping
	float deltaTime = getDeltaTimeMicroseconds() / 1000000.f;

	if (dynamicsWorld) {
		dynamicsWorld->stepSimulation(deltaTime);
		dynamicsWorld->debugDrawWorld();
	}
	//draw font
	{
		int now = glutGet(GLUT_ELAPSED_TIME);

		float n = (float) now / 20.;
		float t1 = sin(n / 80);
		float t2 = sin(n / 50 + 1);
		float t3 = sin(n / 30 + 2);

		float ambient[4] = { (t1 + 2.0) / 3, (t2 + 2.0) / 3, (t3 + 2.0) / 3,
				0.3 };
		float diffuse[4] = { 1.0, 0.9, 0.9, 1.0 };
		float specular[4] = { 1.0, 0.7, 0.7, 1.0 };
		float position[4] = { 100.0, 100.0, 0.0, 1.0 };

		float front_ambient[4] = { 0.7, 0.7, 0.7, 0.0 };

		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

		glPushMatrix();
		glTranslatef(-0.9, -0.2, -10.0);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT1, GL_POSITION, position);
		glEnable(GL_LIGHT1);
		glPopMatrix();

		if (font == NULL) {
			font = new FTExtrudeFont("media/font/DejaVuSans.ttf");
			font->FaceSize(1);
			font->CharMap(ft_encoding_unicode);
		}

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, front_ambient);
		glColorMaterial(GL_FRONT, GL_DIFFUSE);
		glTranslatef(5.0, 5.0, 20.0);
		glRotatef(n / 1.11, 0.0, 1.0, 0.0);
		glRotatef(0, 1.0, 0.0, 0.0);
		glRotatef(0, 0.0, 0.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		//drawText3D(font[fontindex], "SpaceGraph", 0, 0, 20.0);

		font->Render("CRITTERGOD");
                
		glPopMatrix();

	}

	renderme();

	for (int i = 2; i >= 0; i--) {
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		drawFrame(body->getWorldTransform());
	}

	float ms = getDeltaTimeMicroseconds();
	if (m_dialogDynamicsWorld)
		m_dialogDynamicsWorld->draw(ms / 1000000.f);

	glFlush();
	glutSwapBuffers();

        updateAudio();
}

void DefaultSpace::updateAudio() {
//    audio->pointGenerators->clear();
//    double f = 100 + float(rand()%100);
//    audio->pointGenerators->push_back(new PointGenerator(f));
}

void DefaultSpace::displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderme();

	if (dynamicsWorld)
		dynamicsWorld->debugDrawWorld();

	float ms = getDeltaTimeMicroseconds();
	if (m_dialogDynamicsWorld != NULL)
		m_dialogDynamicsWorld->draw(ms / 1000000.f);

	glFlush();
	glutSwapBuffers();
}

void DefaultSpace::keyboardCallback(unsigned char key, int x, int y) {
	switch (key) {
	case '+':
	case '=':
		m_fCyclePeriod /= 1.1f;
		if (m_fCyclePeriod < 1.f)
			m_fCyclePeriod = 1.f;
		break;
	case '-':
	case '_':
		m_fCyclePeriod *= 1.1f;
		break;
		//	case '[':
		//		m_fMuscleStrength /= 1.1f;
		//		break;
		//	case ']':
		//		m_fMuscleStrength *= 1.1f;
		//		break;
	default:
		SpaceProcess::keyboardCallback(key, x, y);
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

void DefaultSpace::renderme() {
	init();

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

		int xOffset = 10;
		int yStart = 20;
		int yIncr = 20;
		char buf[124];

		glDisable(GL_LIGHTING);
		glColor3f(0, 0, 0);

		if ((m_debugMode & btIDebugDraw::DBG_NoHelpText) == 0) {
			//			setOrthographicProjection();
			//
			//			showProfileInfo(xOffset,yStart,yIncr);
			//
			//#ifdef USE_QUICKPROF
			//
			//
			//			if ( getDebugMode() & btIDebugDraw::DBG_ProfileTimings)
			//			{
			//				static int counter = 0;
			//				counter++;
			//				std::map<std::string, hidden::ProfileBlock*>::iterator iter;
			//				for (iter = btProfiler::mProfileBlocks.begin(); iter != btProfiler::mProfileBlocks.end(); ++iter)
			//				{
			//					char blockTime[128];
			//					sprintf(blockTime, "%s: %lf",&((*iter).first[0]),btProfiler::getBlockTime((*iter).first, btProfiler::BLOCK_CYCLE_SECONDS));//BLOCK_TOTAL_PERCENT));
			//					glRasterPos3f(xOffset,yStart,0);
			//					GLDebugDrawString(BMF_GetFont(BMF_kHelvetica10),blockTime);
			//					yStart += yIncr;
			//
			//				}
			//
			//			}
			//#endif //USE_QUICKPROF
			//			resetPerspectiveProjection();
		}

		glEnable(GL_LIGHTING);

	}

	updateCamera();
}

void DefaultSpace::renderscene(int pass) {

	btScalar m[16];
	btMatrix3x3 rot;
	rot.setIdentity();
	const unsigned numObjects = dynamicsWorld->getNumCollisionObjects();
	btVector3 wireColor(1, 0, 0);

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
		btCollisionObject* colObj =	dynamicsWorld->getCollisionObjectArray()[i];
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
			if (index!=-1) {
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
