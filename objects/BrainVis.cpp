///*
// * BrainVis.cpp
// *
// *  Created on: Jan 21, 2010
// *      Author: seh
// */
//
//#include <GL/gl.h>
//#include <GL/glu.h>
//
//#include "../physics/LinearMath/btVector3.h"
//
//#include "BrainVis.h"
//
//BrainVis::BrainVis(Brain* b) {
//	brain = b;
//
//	for (unsigned i = 0; i < b->numNeurons; i++) {
//		Neuron* n = b->neurons[i];
//		neuronPosition[n] = new btVector3();
//		neuronPosition[n]->setValue(frand(-5.5, 5.5), frand(-5.5, 5.5), frand(-5.5, 5.5));
//
//	}
//
//}
//
//BrainVis::~BrainVis() {
//}
//
//void BrainVis::init(int w, int h) {
//	/* Enable smooth shading */
//	glShadeModel(GL_SMOOTH);
//
//	/* Set the background black */
//	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//
//	/* Depth buffer setup */
//	glClearDepth(1.0f);
//
//	/* Enables Depth Testing */
//	glEnable(GL_DEPTH_TEST);
//
//	/* The Type Of Depth Test To Do */
//	glDepthFunc(GL_LEQUAL);
//
//	/* Really Nice Perspective Calculations */
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//
//	glEnable(GL_BLEND);
//
//	resize(w, h);
//}
//
//void BrainVis::resize(int w, int h) {
//	/* Height / width ration */
//	GLdouble ratio;
//
//	ratio = (GLfloat) w / (GLfloat) h;
//
//	/* Setup our viewport. */
//	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//
//	/* change to the projection matrix and set our viewing volume. */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	/* Set our perspective */
//	gluPerspective(45.0, ratio, 0.1, 100.0);
//
//	/* Make sure we're chaning the model view and not the projection */
//	glMatrixMode(GL_MODELVIEW);
//
//	/* Reset The View */
//	glLoadIdentity();
//
//}
//
////void drawTriangle(float x, float y, float z, float w, float h, float r, float g, float b) {
////	glLoadIdentity();
////	glTranslatef(x, y, z);
////	glScalef(w, h, 1.0);
////	glColor3f(r, g, b);
////
////	glBegin(GL_TRIANGLES); /* Drawing Using Triangles */
////	glVertex3f(0.0f, 1.0f, 0.0f); /* Top */
////	glVertex3f(-1.0f, -1.0f, 0.0f); /* Bottom Left */
////	glVertex3f(1.0f, -1.0f, 0.0f); /* Bottom Right */
////	glEnd(); /* Finished Drawing The Triangle */
////}
////
//void drawRect(float x, float y, float z, float w, float h, float r, float g, float b, float a) {
//	glLoadIdentity();
//
//	glTranslatef(x, y, z);
//	glScalef(w, h, 1);
//	glColor4f(r, g, b, a);
//
//	glBegin(GL_QUADS); /* Draw A Quad */
//	glVertex3f(-1.0f, 1.0f, 0.0f); /* Top Left */
//	glVertex3f(1.0f, 1.0f, 0.0f); /* Top Right */
//	glVertex3f(1.0f, -1.0f, 0.0f); /* Bottom Right */
//	glVertex3f(-1.0f, -1.0f, 0.0f); /* Bottom Left */
//	glEnd(); /* Done Drawing The Quad */
//}
//
//int frame = 0;
//
//void BrainVis::drawNeuron(int i) {
//	Neuron* n = brain->neurons[i];
//	float o = n->potential;
//	float r, g, b;
//	if (o < 0) {
//		r = -o;
//		g = b = 0;
//	}
//	else {
//		b = o;
//		r = g = 0;
//	}
//	float s = 0.15 + 0.7 * fabs(o);
//
//	btVector3* p = neuronPosition[n];
//
//	float w = 0.1;
//	float h = 0.1;
//
//	float fp = ((float)frame) * 0.01;
//
//
//	drawRect(p->getX(), p->getY(), (p->getZ())-5.0, w*s, h*s, r, g, b, 0.5);
//
//}
//
//void BrainVis::drawBrain() {
//	//drawTriangle(-1.5, 0, -6, 1, 1, 1.0, 0.5, 0.5);
//	//drawRect(1.5, 0, 0, 0.5, 1, 0.8, 0.5, 1.0);
//
//	if (frame % 500 < 250) {
//		brain->addRandomInputs(-0.1, 0.1, 0.99);
//	}
////	else {
////		int feedbackwidth = (int)fmin(brain->ins.size(), brain->outs.size());
////		for (int i = 0; i < feedbackwidth; i++) {
////			brain->ins[i]->setInput(brain->outs[i]->getOutput());
////		}
////	}
//
//
//
//	frame++;
//
//	float w = 0.1;
//	float h = 0.1;
//
//	float x=0, y=0, z=-6;
//
//	x = -2.5;
//	y = 2.2;
//	for (unsigned i = 0; i < brain->ins.size(); i++) {
//		InNeuron* n = brain->ins[i];
//		float c = (n->getOutput() + 1.0)/2.0;
//		drawRect(x, y, z, w, h, c, c, c, 1.0);
//		x+=w;
//	}
//
//	x = -2.5;
//	y = -2.2;
//	for (unsigned i = 0; i < brain->outs.size(); i++) {
//		OutNeuron* n = brain->outs[i];
//		float c = (n->getOutput() + 1.0)/2.0;
//		drawRect(x, y, z, w, h, c, c, c, 1.0);
//		x+=w;
//	}
//
//
//	int num = brain->neurons.size();
//
//	x = -1.5;
//	y = -1.8;
//
//	for (unsigned i = 0; i < brain->neurons.size(); i++) {
//		drawNeuron(i);
//	}
//
//
//
//
//}
//
//void BrainVis::processBrain() {
//	btVector3 d(0,0,0);
//
//
////    double wx = getBoundsMax().getX() / 2.0;
////    double wy = getBoundsMax().getY() / 2.0;
////    double wz = getBoundsMax().getZ() / 2.0;
//
//	brain->forward(1.0);
//
//	if (frame % 1 == 0) {
//		double stiffness = 0.1;
//		double repulsion = 0; //-0.0001;
//		double naturalLength = 0.01;
//		double speed = 0.03;
//
////		for (unsigned i = 0; i < brain->numNeurons; i++) {
////			Neuron* n = brain->neurons[i];
////			d.setValue(frand(-0.0002, 0.0002), frand(-0.0002, 0.0002), frand(-0.0002, 0.0002));
////			*(neuronPosition[n]) += d;
////		}
//
//		//attract
//                unsigned i;
//
//                //#pragma omp parallel for private(i)
//                for (i = 0; i < brain->numNeurons; i++) {
//			Neuron* a = brain->neurons[i];
//			btVector3* aPos = neuronPosition[a];
//			unsigned numSynapses = a->synapses.size();
//			for (unsigned s = 0; s < numSynapses; s++) {
//				Synapse* syn = a->synapses[s];
//				AbstractNeuron *b = syn->inputNeuron;
//				if (b == NULL)
//					continue;
//				btVector3* bPos = neuronPosition[(Neuron*)b];
//				if (bPos == NULL)
//					continue;
//
//				double currentLength = aPos->distance(*bPos);
//				double f = stiffness * (currentLength - naturalLength) / ((float)numSynapses);
//
//				double sx = f * (bPos->getX() - aPos->getX());
//				double sy = f * (bPos->getY() - aPos->getY());
//				double sz = f * (bPos->getZ() - aPos->getZ());
//
//				*aPos += btVector3(sx/2.0, sy/2.0, sz/2.0) * speed;
//				*bPos -= btVector3(sx/2.0, sy/2.0, sz/2.0) * speed;
//
//			}
//		}
//
//		//repel
//
//		btVector3 center(0,0,0);
//                //#pragma omp parallel for private(i)
//		for (i = 0; i < brain->numNeurons; i++) {
//			Neuron* a = brain->neurons[i];
//			btVector3* aPos = neuronPosition[a];
//
//			if (repulsion != 0.0) {
//				btVector3 force(0,0,0);
//				for (unsigned j = 0; j < brain->numNeurons; j++) {
//					if (i == j)
//						continue;
//
//					Neuron* b = brain->neurons[j];
//					btVector3* bPos = neuronPosition[b];
//
//					double dist = bPos->distance(*aPos);
//
//					double f = -repulsion * /*(nMass * mMass)*/1.0 / (dist * dist);
//
//					double sx = f * (aPos->getX() - bPos->getX());
//					double sy = f * (aPos->getY() - bPos->getY());
//					double sz = f * (aPos->getZ() - bPos->getZ());
//					force += btVector3(sx, sy, sz);
//				}
//
//				*aPos += force * speed;
//			}
//
//			center += *aPos;
//		}
//
//		center /= ((double)brain->numNeurons);
//
//                //#pragma omp parallel for private(i)
//		for (i = 0; i < brain->numNeurons; i++) {
//			Neuron* a = brain->neurons[i];
//			btVector3* aPos = neuronPosition[a];
//			*aPos -= center;
//		}
//	}
//
//
//}
//
//void BrainVis::draw() {
//	/* These are to calculate our fps */
//	static GLint T0 = 0;
//	static GLint Frames = 0;
//
//	/* Clear The Screen And The Depth Buffer */
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	/* Move Left 1.5 Units And Into The Screen 6.0 */
//	glLoadIdentity();
//
//	{
//		drawBrain();
//	}
//
//	/* Draw it to the screen */
//	SDL_GL_SwapBuffers();
//
//        processBrain();
//
//	/* Gather our frames per second */
//	Frames++;
//	{
//		GLint t = SDL_GetTicks();
//		if (t - T0 >= 5000) {
//			GLfloat seconds = (t - T0) / 1000.0;
//			GLfloat fps = Frames / seconds;
//			printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
//			T0 = t;
//			Frames = 0;
//		}
//	}
//
//}
//
//
//void BrainVis::handlekeyPressed(const SDLKey& key) {
//	static double pd = 0.9;
//
//		switch (key)
//		{
//
//			case SDLK_LEFTBRACKET:
//				pd -= 0.01;
//				if (pd < 0) pd = 0;
//				brain->setPotentialDecay(pd);
//				break;
//			case SDLK_RIGHTBRACKET:
//				pd += 0.01;
//				if (pd < 0) pd = 0;
//				brain->setPotentialDecay(pd);
//				break;
//
//			default:
//				break;
//		}
//
//}
//void BrainVis::handlekeyReleased(const SDLKey& key) {
//}
//
//void BrainVis::forward(SDL_Event *event) {
//	if (event->type == SDL_KEYDOWN) {
//		handlekeyPressed(event->key.keysym.sym);
//	}
//	else if (event->type == SDL_KEYUP) {
//		handlekeyReleased(event->key.keysym.sym);
//	}
//}
//
//
////Evolution::Evolution()
////{
////	cmd = Commands::Instance();
////	settings = Settings::Instance();
////	events = Events::Instance();
////
////	if ( settings->getCVar("race") == 1 )
////		world = new WorldRace();
////	else if ( settings->getCVar("testworld") == 1 )
////	{
////		world = new TestWorld1();
////// 		cerr << "test world yeah" << endl;
////	}
////	else
////		world = new WorldB();
////
////	world->mousex = &oldx;
////	world->mousey = &oldy;
////
////	cmd->world = world;
////	static_cast<Hud*>(canvas.children["hud"])->world = world;
////	static_cast<Critterview*>(canvas.children["critterview"])->world = world;
////	cmd->canvas = &canvas;
////
////	pause = false;
////// 	drawCVNeurons = false;
////
////	unsigned int delay = 200;
////	unsigned int speedup = 2;
////
////	// events
////	events->registerEvent(SDLK_ESCAPE,	"swapexitpanel", execcmd.gen("gui_togglepanel", "exitpanel"), 0, 0, 0 );
////	events->registerEvent(SDLK_F1,		"swaphelpinfo", execcmd.gen("gui_togglepanel", "helpinfo"), 0, 0, 0 );
////	events->registerEvent(SDLK_F2,		"swapinfobar", execcmd.gen("gui_togglepanel", "infobar"), 0, 0, 0 );
////	events->registerEvent(SDLK_F3,		"swapinfostats", execcmd.gen("gui_togglepanel", "infostats"), 0, 0, 0 );
////	events->registerEvent(SDLK_F4,		"swaptextverbosemessage", execcmd.gen("gui_togglepanel", "textverbosemessage"), 0, 0, 0 );
////
////	events->registerEvent(SDLK_F5,		"swapstatsgraph", execcmd.gen("gui_togglepanel", "statsgraph"), 0, 0, 0 );
////	events->registerEvent(SDLK_F6,		"swapsettingspanel", execcmd.gen("gui_togglepanel", "settingspanel"), 0, 0, 0 );
////	events->registerEvent(SDLK_F7,		"swapsettingsbrainpanel", execcmd.gen("gui_togglepanel", "settingsbrainpanel"), 0, 0, 0 );
////	events->registerEvent(SDLK_F8,		"swaphud", execcmd.gen("gui_togglepanel", "hud"), 0, 0, 0 );
////
////// 	events->registerEvent(SDLK_F5,		"dec_critters", execcmd.gen("settings_decrease", "mincritters"), delay, 0, speedup );
////// 	events->registerEvent(SDLK_F6,		"inc_critters", execcmd.gen("settings_increase", "mincritters"), delay, 0, speedup );
////// 	events->registerEvent(SDLK_F7,		"dec_killhalftrigger", execcmd.gen("settings_decrease", "critter_killhalfat"), delay, 0, speedup );
////// 	events->registerEvent(SDLK_F8,		"inc_killhalftrigger", execcmd.gen("settings_increase", "critter_killhalfat"), delay, 0, speedup );
////	events->registerEvent(SDLK_KP_DIVIDE,	"dec_camerasensitivity", execcmd.gen("settings_decrease", "camerasensitivity"), delay, 0, speedup );
////	events->registerEvent(SDLK_KP_MULTIPLY,	"inc_camerasensitivity", execcmd.gen("settings_increase", "camerasensitivity"), delay, 0, speedup );
////	events->registerEvent(SDLK_c,		"inc_colormode", execcmd.gen("settings_increase", "colormode"), 0, 0, 0 );
////
////	events->registerEvent(SDLK_F9,		"dec_body_mutationrate", execcmd.gen("settings_decrease", "body_mutationrate"), delay, 0, speedup );
////	events->registerEvent(SDLK_F10,		"inc_body_mutationrate", execcmd.gen("settings_increase", "body_mutationrate"), delay, 0, speedup );
////	events->registerEvent(SDLK_F11,		"dec_brain_mutationrate", execcmd.gen("settings_decrease", "brain_mutationrate"), delay, 0, speedup );
////	events->registerEvent(SDLK_F12,		"inc_brain_mutationrate", execcmd.gen("settings_increase", "brain_mutationrate"), delay, 0, speedup );
////
////	events->registerEvent(SDLK_BACKSPACE,	"resetcamera", execcmd.gen("camera_resetposition"), 0, 0, 0 );
////
////	events->registerEvent(SDLK_PAGEUP,	"keyloadAllCritters", execcmd.gen("loadallcritters"), 0, 0, 0 );
////	events->registerEvent(SDLK_PAGEDOWN,	"keysaveAllCritters", execcmd.gen("saveallcritters"), 0, 0, 0 );
////	events->registerEvent(SDLK_i,		"keyinsertCritter", execcmd.gen("insertcritter"), 0, 0, 0 );
////	events->registerEvent(SDLK_k,		"keykillhalfOfcritters", execcmd.gen("killhalfofcritters"), 0, 0, 0 );
////
////	events->registerEvent(SDLK_KP_MINUS,	"keydecreaseenergy", execcmd.gen("decreaseenergy"), delay, 0, speedup );
////	events->registerEvent(SDLK_KP_PLUS,	"keyincreaseenergy", execcmd.gen("increaseenergy"), delay, 0, speedup );
////
////	sharedTimer* t = events->registerSharedtimer( 20 );
////
////	events->registerEvent(SDLK_HOME,	"keycamera_moveup", execcmd.gen("camera_moveup"), t );
////	events->registerEvent(SDLK_END,		"keycamera_movedown", execcmd.gen("camera_movedown"), t );
////	events->registerEvent(SDLK_UP,		"keycamera_moveforward", execcmd.gen("camera_moveforward"), t );
////	events->registerEvent(SDLK_DOWN,	"keycamera_movebackward", execcmd.gen("camera_movebackward"), t );
////	events->registerEvent(SDLK_LEFT,	"keycamera_moveleft", execcmd.gen("camera_moveleft"), t );
////	events->registerEvent(SDLK_RIGHT,	"keycamera_moveright", execcmd.gen("camera_moveright"), t );
////
////	events->registerEvent(SDLK_KP2,		"keycamera_lookup", execcmd.gen("camera_lookup"), t );
////	events->registerEvent(SDLK_KP8,		"keycamera_lookdown", execcmd.gen("camera_lookdown"), t );
////	events->registerEvent(SDLK_KP4,		"keycamera_lookleft", execcmd.gen("camera_lookleft"), t );
////	events->registerEvent(SDLK_KP6,		"keycamera_lookright", execcmd.gen("camera_lookright"), t );
////
////	events->registerEvent(SDLK_KP1,		"keycamera_rollleft", execcmd.gen("camera_rollleft"), t );
////	events->registerEvent(SDLK_KP3,		"keycamera_rollright", execcmd.gen("camera_rollright"), t );
////
////	events->registerEvent(SDLK_f, "inc_fullscreen", execcmd.gen("settings_increase", "fullscreen"), 0, 0, 0 );
////
////	mouselook = false;
////
////	oldx = 0;
////	oldy = 0;
////
////	world->init();
////}
////
////void Evolution::draw()
////{
////	if ( pause )
////	{
////		usleep(20000);
////		return;
////	}
////
////	Timer::Instance()->mark();
////	sleeper.mark();
////
////	if ( !settings->getCVar("headless") )
////	{
////
////		handleEvents();
////		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
////	// 3D
////// 		GLfloat ambientLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
////		GLfloat ambientLight[] = {0.6f, 0.6f, 0.6f, 0.0f};
////		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
////// 		GLfloat lightColor[] = { 0.1f, 0.1f, 0.1f, 1.0f };
////		GLfloat lightColor[] = { 0.04f, 0.04f, 0.04f, 0.0f };
////		GLfloat lightPos[] = { 0.5f*settings->getCVar("worldsizeX"), 50.0f, 0.5f*settings->getCVar("worldsizeY"), 1.0f };
////// 		GLfloat lightPos1[] = { 0.0f, 20.0f, 0.5f*settings->getCVar("worldsizeY"), 1.0f };
////// 		GLfloat lightPos2[] = { settings->getCVar("worldsizeX")+1.0f, 20, 0.5f*settings->getCVar("worldsizeY"), 1.0f };
////		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
////		glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
////// 		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
////// 		glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
////// 		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
////// 		glLightfv(GL_LIGHT1, GL_POSITION, lightPos2);
////
////		glEnable(GL_DEPTH_TEST);
////		glEnable(GL_COLOR_MATERIAL);
////		glEnable(GL_LIGHTING);
////		glEnable(GL_LIGHT0);
////// 		glEnable(GL_LIGHT1);
////		glEnable(GL_CULL_FACE);
////		glCullFace(GL_BACK);
////
////		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
////// 		glHint(GL_FOG_HINT, GL_FASTEST);
////// 		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
////
////		glShadeModel(GL_FLAT);
////// 		glShadeModel(GL_SMOOTH);
////
////		glDisable(GL_DITHER);
////		glDisable(GL_POLYGON_SMOOTH);
////	}
////
////		world->process();
////		world->getGeneralStats();
////
////	if ( !settings->getCVar("headless") )
////	{
////
////// 			if (world->critters.size() > 1 )
////// 			{
////// 				world->camera.follow( (btDefaultMotionState*)world->critters[0]->body.mouths[0]->body->getMotionState() );
////// 				world->drawWithoutFaces();
////// // 				world->critters[0]->printVision();
////// 			}
////
////		world->camera.place();
////		world->drawWithGrid();
////
////		// draw selected info
////		btScalar position[16];
////		btTransform trans;
////		trans.setIdentity();
////
////		btTransform up;
////		up.setIdentity();
////		up.setOrigin( btVector3(0.0f, 0.2f, 0.0f) );
////
////		for ( unsigned int i=0; i < world->critterselection->clist.size(); i++ )
////		{
////			trans.setOrigin(world->critterselection->clist[i]->body.mouths[0]->ghostObject->getWorldTransform().getOrigin());
////			trans.getOrigin().setY(trans.getOrigin().getY()+0.5f);
////			trans.setBasis(world->camera.position.getBasis());
////			trans *= up;
////			trans.getOpenGLMatrix(position);
////
////			glPushMatrix();
////			glMultMatrixf(position);
////
////				glColor3f(1.5f, 1.5f, 1.5f);
////				glBegin(GL_LINES);
////					glVertex2f(-0.2f, 0.05f);
////					glVertex2f(-0.2f,-0.05f);
////
////					glVertex2f(-0.2f,-0.05f);
////					glVertex2f(0.2f, -0.05f);
////
////					glVertex2f(0.2f, -0.05f);
////					glVertex2f(0.2f,  0.05f);
////
////					glVertex2f(0.2f,  0.05f);
////					glVertex2f(-0.2f, 0.05f);
////				glEnd();
////
////			glPopMatrix();
////		}
////
////	// 2D
////		glDisable(GL_DEPTH_TEST);
////		glDisable (GL_LIGHTING);
////		glDisable(GL_LIGHT0);
////// 		glDisable(GL_LIGHT1);
////		glDisable(GL_COLOR_MATERIAL);
////// 		glDisable(GL_DITHER);
////		glDisable(GL_CULL_FACE);
////
////		glPushMatrix();
////		glMatrixMode(GL_PROJECTION);
////		glLoadIdentity();
////		glOrtho(0, *Settings::Instance()->winWidth, *Settings::Instance()->winHeight, 0, 0, 1);
////		glMatrixMode(GL_MODELVIEW);
////		glLoadIdentity();
////
////			canvas.draw();
////
////			world->mouseRayHit = false;
////			if (!mouselook && !canvas.mouseFocus )
////				world->castMouseRay();
////
////			// hover test
////			if ( world->mouseRayHit )
////			{
////				unsigned int margin = 20;
////				unsigned int rmargindistance = 70;
////				unsigned int vspacer = 12;
////				glColor3f(1.0f, 1.0f, 1.0f);
////				if ( world->mouseRayHitEntity->type == 1 )
////				{
////					Textprinter::Instance()->print( oldx+margin, oldy,    "food");
////					Textprinter::Instance()->print( oldx+margin, oldy+vspacer, "energy");
////					Textprinter::Instance()->print(oldx+rmargindistance, oldy+vspacer, "%1.1f", static_cast<const Food*>(world->mouseRayHitEntity)->energyLevel);
////				}
////				else if ( world->mouseRayHitEntity->type == 0 )
////				{
////					CritterB* c = static_cast<const CritterB*>(world->mouseRayHitEntity);
////					Textprinter::Instance()->print( oldx+margin, oldy,    "critter");
////					Textprinter::Instance()->print(oldx+rmargindistance, oldy, "%1i", c->critterID);
////					Textprinter::Instance()->print( oldx+margin, oldy+vspacer, "energy");
////					Textprinter::Instance()->print(oldx+rmargindistance, oldy+vspacer, "%1.1f", c->energyLevel);
////				}
////			}
////		glPopMatrix();
////
////		SDL_GL_SwapBuffers();
////	}
////
////	if ( world->critters.size() == 0 && settings->getCVar("exit_if_empty") )
////	{
////		cerr << "world is empty, exiting..." << endl;
////		cmd->quit();
////	}
////}
////
////void Evolution::handlekeyPressed(const SDLKey& key)
////{
////	if ( pause && key != SDLK_p )
////		return;
////
////	switch (key)
////	{
////		case SDLK_m:
////		{
////			mouselook = !mouselook;
////			if ( mouselook )
////			{
////#ifdef _WIN32
////				SDL_WarpMouse(0,0);
////#endif
////				SDL_WM_GrabInput(SDL_GRAB_ON);
////				SDL_ShowCursor(SDL_DISABLE);
////				// clear remaining poll events
////				{ SDL_Event e; while (SDL_PollEvent(&e)) {} };
////
////				// release picked objects
////				world->mousepicker->detach();
////			}
////			else
////			{
////				SDL_ShowCursor(SDL_ENABLE);
////				SDL_WM_GrabInput(SDL_GRAB_OFF);
////			}
////		}
////			break;
////
////		case SDLK_p:
////			pause = !pause;
////			break;
////
////		case SDLK_s: // FIXME make use of savedir (declared in world)
////		{
////			settings->saveProfile();
////			stringstream buf;
////			buf << "Profile written: ./" << settings->profileName;
////			Logbuffer::Instance()->add(buf);
////		}
////		break;
////
////		case SDLK_l:
////			sleeper.swap();
////			break;
////
////		default:
////			events->activateEvent(key);
////			events->handlecommands();
////			break;
////	}
////}
////
////void Evolution::handlekeyReleased(const SDLKey& key)
////{
////	events->deactivateEvent(key);
////}
////
////void Evolution::handlemousebuttonPressed(int x, int y, const int& button)
////{
////// 	cerr << "button " << button << " clicked at " << x << "x" << y << endl;
////	if ( !mouselook )
////	{
////		canvas.buttonPress(button);
////		if ( button == 1 )
////			world->selectBody( x, y );
////		else if ( button == 2 )
////			world->resetCamera();
////                else if (button == 2) {
////
////                }
////		else if ( button == 3 )
////			world->pickBody( x, y );
////		else if ( button == 4 )
////			world->moveInMouseDirection(true);
////		else if ( button == 5 )
////			world->moveInMouseDirection(false);
////	}
////}
////
////void Evolution::handlemousebuttonReleased(int x, int y, const int& button)
////{
////// 	cerr << "button " << button << " released at " << x << "x" << y << endl;
////	canvas.buttonRelease(button);
////	if ( button == 1 )
////		;
////	else if ( button == 3 )
////		world->mousepicker->detach();
////}
////
////void Evolution::handleMouseMotionAbs(int x, int y)
////{
////	if ( !mouselook )
////	{
////		oldx = x;
////		oldy = y;
////
////		// gui mouse dynamics
////		canvas.moveMouse(x, y);
////
////		// world mouse dynamics
////		world->calcMouseDirection();
////		world->movePickedBodyTo();
////	}
////}
////
////void Evolution::handleMouseMotionRel(int x, int y)
////{
////	if ( mouselook )
////	{
////		if ( x > 0 )
////			world->camera.lookRight( (float)x/3000 );
////		else if ( x != 0 )
////			world->camera.lookLeft( (float)x/-3000 );
////
////		if ( y > 0 )
////			world->camera.lookDown( (float)y/3000 );
////		else if ( y != 0 )
////			world->camera.lookUp( (float)y/-3000 );
////	}
////}
////
////void Evolution::handleEvents()
////{
////	events->processSharedTimers();
////	events->handlecommands();
////}
////
////Evolution::~Evolution()
////{
////	delete world;
////}
