//============================================================================
// Name        : crittergod4.cpp
// Author      : crittergod.sourceforge.net
// Version     :
// Copyright   : Copyright (C) 2010 CritterGod. All Rights Reserved.
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

#include "neural/Brain.h"
#include "video/GLWindow.h"
#include "objects/BrainVis.h"

#include "graph/Graph.h"

#include "physics/RunBox2D/Box2dDemo.h"
#include "space/DefaultSpace.h"
#include "physics/OpenGL/GlutStuff.h"

//#include "physics/optic/Raytracer.h"

#include "video/font/FontDemo1.h"

#define VERSION "CritterGod 0.01"

#include "space/AbstractBody.h"
#include "space/SpiderBody.h"
#include "space/SnakeBody.h"
#include "space/BoxBody.h"

#include "audio/Audio.h"

void runSim() {
    Audio* audio = new Audio();

    DefaultSpace* ds = new DefaultSpace(audio);

    SnakeBody* snake1 = new SnakeBody(btVector3(0, 0, 0), 8);
    ds->addBody(snake1);

    SnakeBody* snake2 = new SnakeBody(btVector3(2, 2, 0), 12);
    ds->addBody(snake2);

    for (unsigned i = 0; i < 5; i++) {
        SpiderBody* spider = new SpiderBody(1 + i, btVector3(0, 0, 5 + i * 2));
        ds->addBody(spider);
    }

    BoxBody* box = new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.5, 0.5));
    ds->addBody(box);

    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

    delete audio;

}

//void runRT() {
//    Raytracer* raytraceDemo = new Raytracer();
//
//
//    raytraceDemo->initPhysics();
//
//    raytraceDemo->setCameraDistance(6.f);
//
//    std::vector<SpaceProcess*> procs;
//	procs.push_back(raytraceDemo);
//
//
//	runGLWindow(0, NULL, 640, 640,"Bullet GJK Implicit Shape Raytracer Demo",&procs);
//}

void runBrainDemo() {
    Brain* b = new Brain(48, 32, 32000, 1, 8, 0.4);
    b->printSummary();
    GLWindow* g = new GLWindow();
    g->create("Brain", 800, 600);
    g->start(new BrainVis(b));
}

void testGraph() {
    Graph g;

    string a = string("a");
    string b = string("b");

    g.addEdge(new string("ab"), &a, &b);
    g.addEdge(new string("cd"), &a, &b);

    g.print();

}


int main(int argc, char** argv) {


    runSim();
    //runBrainDemo();
    //runRT();
    //testGraph();

    //runFontDemo();


    return 0;
}
