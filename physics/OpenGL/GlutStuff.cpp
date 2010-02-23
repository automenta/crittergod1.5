/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#include "SpaceProcess.h"

#include <vector>

//glut is C code, this global gDemoApplication links glut to the C++ demo

std::vector<SpaceProcess*> processes;

#include "GlutStuff.h"


static	void glutKeyboardCallback(unsigned char key, int x, int y) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->onKeyboard(key,x,y);
	}
}

static	void glutKeyboardUpCallback(unsigned char key, int x, int y) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->keyboardUpCallback(key,x,y);
	}
}

static void glutSpecialKeyboardCallback(int key, int x, int y) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->specialKeyboard(key,x,y);
	}
}

static void glutSpecialKeyboardUpCallback(int key, int x, int y){
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->specialKeyboardUp(key,x,y);
	}
}


static void glutReshapeCallback(int w, int h) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->reshape(w,h);
	}
}

static void glutMoveAndDisplayCallback() {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->moveAndDisplay();
	}
}

static void glutMouseFuncCallback(int button, int state, int x, int y) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->onMouseButton(button,state,x,y);
	}
}


static void	glutMotionFuncCallback(int x,int y) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->onMouseMove(x,y);
	}
}


static void glutDisplayCallback(void) {
	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->draw();
	}
}

int runGLWindow(int argc, char **argv,int width,int height, const char* title, SpaceProcess* p) {
	std::vector<SpaceProcess*> vp;
	vp.push_back(p);
	runGLWindow(argc, argv, width, height, title, &vp);
}


int runGLWindow(int argc, char **argv,int width,int height,const char* title, std::vector<SpaceProcess*>* initialProcesses) {
    
	for (unsigned i = 0; i < initialProcesses->size(); i++)
		processes.push_back((*initialProcesses)[i]);

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);

#ifdef BT_USE_FREEGLUT
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif

	for (unsigned i = 0; i < processes.size(); i++) {
		SpaceProcess* sp = processes[i];
		sp->preDraw();
	}

	glutKeyboardFunc(glutKeyboardCallback);
	glutKeyboardUpFunc(glutKeyboardUpCallback);
	glutSpecialFunc(glutSpecialKeyboardCallback);
	glutSpecialUpFunc(glutSpecialKeyboardUpCallback);

	glutReshapeFunc(glutReshapeCallback);
    //createMenu();
	glutIdleFunc(glutMoveAndDisplayCallback);
	glutMouseFunc(glutMouseFuncCallback);
	glutPassiveMotionFunc(glutMotionFuncCallback);
	glutMotionFunc(glutMotionFuncCallback);
	glutDisplayFunc( glutDisplayCallback );

	glutMoveAndDisplayCallback();
	
    glutMainLoop();
    return 0;
}


