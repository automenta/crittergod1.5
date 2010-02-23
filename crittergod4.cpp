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
#include "objects/BrainPanel.h"
#include "objects/NeuralSignalsPanel.h"
#include "objects/RetinaPanel.h"
#include "objects/FDBrainBody.h"

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

#include "widget2d/container.h"
#include "widget2d/panel.h"
#include "widget2d/button.h"
#include "widget2d/text.h"

void runSim() {
    Audio* audio = new Audio();

    DefaultSpace* ds = new DefaultSpace(audio);

    {
        Container* c = ds->getFace();

        static Panel* panel = new Panel();
        panel->setSize(200, 200);
        panel->setPosition(50, 50);

        Button* b = new Button("Clear");

        class TestButtonModel : public ButtonModel {

            virtual void onChange(Button* b, int state) {
                cout << "button pressed : " << state << "\n";
                panel->bgColor[0] = 1.0;
            }
        };
        b->setModel(new TestButtonModel());
        b->setSize(65, 25);
        b->setPosition(5, 5);

        panel->addWidgetPanel("b", b);


        c->addWidgetPanel("a", panel);


    }


    {
        ds->addGround(50, 50, 5);

        for (unsigned i = 2; i < 5; i++) {
            SnakeBody* snake1 = new SnakeBody(btVector3(0, 0, 0), i * 2);
            ds->addBody(snake1);

        }

        for (unsigned i = 0; i < 5; i++) {
            SpiderBody* spider = new SpiderBody(1 + i, btVector3(0, 0, 5 + i * 2));
            ds->addBody(spider);
        }
    }
    //
    //    BoxBody* box = new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.5, 0.5));
    //    ds->addBody(box);

    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

    delete audio;

}

void runBrainDemo() {
    Brain* b = new Brain(16, 4, 512, 8, 32, 0.5);
    b->printSummary();

    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    ds->addBody(new FDBrainBody(b));

    ds->getFace()->addWidgetPanel("brainControl", new BrainPanel(b));

    BrainOutsPanel bop(b, 100);
    ds->getFace()->addWidgetPanel("brainOuts", &bop);
    bop.setPosition(400, 400);


    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

}

void runCritterLab() {

    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    Brain *b;

    ds->addGround(50, 50, 5);

    {
            SpiderBody* spider = new SpiderBody(3, btVector3(0, 0, 5 + 1 * 2));
            ds->addBody(spider);
    }


    SnakeBody* snake1 = new SnakeBody(btVector3(0, 0, 0), 6);
    ds->addBody(snake1);

    b = snake1->brain;



    ds->getFace()->addWidgetPanel("brainControl", new BrainPanel(b));

//    BrainInsPanel bip(b, 50);
//    ds->getFace()->addWidgetPanel("brainIns", &bip);
//    bip.setPosition(300, 300);
//    bip.setSize(300, 300);

    BrainOutsPanel bop(b, 50);
    ds->getFace()->addWidgetPanel("brainOuts", &bop);
    bop.setPosition(400, 400);

    RetinaPanel rp(snake1->eyeRetina);
    ds->getFace()->addWidgetPanel("retina", &rp);
    rp.setSize(150, 150);
    rp.setPosition(300, 300);

    ds->addBody(new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.5, 0.5)));
    ds->addBody(new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.2, 0.7)));
    ds->addBody(new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.3, 0.7)));
    ds->addBody(new BoxBody(btVector3(3, 3, 3), btVector3(1, 0.5, 0.5)));

    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

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


    //runSim();

    runBrainDemo();

    //runCritterLab();

    //runRT();
    //testGraph();

    //runFontDemo();


    return 0;
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
