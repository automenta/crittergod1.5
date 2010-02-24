/* 
 * File:   RunSims.cpp
 * Author: seh
 * 
 * Created on February 23, 2010, 3:57 PM
 */

#include "RunSims.h"





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

        panel->addPanel("b", b);


        c->addPanel("a", panel);


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
    Brain* b = new Brain(16, 4, 256, 1, 8, 0.5);
    b->printSummary();

    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    ds->setShadows(false);
    ds->setTexturing(false);

    FDBrainBody fdb(b);
    ds->addBody(&fdb);

    BrainPanel *bp = new BrainPanel(b);
    ds->getFace()->addPanel("brainControl", bp);
    bp->setPosition(15, 15);

    FDBrainPanel fdo(&fdb);
    ds->getFace()->addPanel("fdPanel", &fdo);
    fdo.span(350, 500, 450, 600);
    
    BrainInsPanel bip(b, 100);
    ds->getFace()->addPanel("brainIns", &bip);
    bip.setPosition(600, 600);

    BrainOutsPanel bop(b, 100);
    ds->getFace()->addPanel("brainOuts", &bop);
    bop.setPosition(800, 600);


    runGLWindow(0, NULL, 1200, 1000, VERSION, ds);

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



    ds->getFace()->addPanel("brainControl", new BrainPanel(b));

    //    BrainInsPanel bip(b, 50);
    //    ds->getFace()->addWidgetPanel("brainIns", &bip);
    //    bip.setPosition(300, 300);
    //    bip.setSize(300, 300);

    BrainOutsPanel bop(b, 50);
    ds->getFace()->addPanel("brainOuts", &bop);
    bop.setPosition(400, 400);

    RetinaPanel rp(snake1->eyeRetina);
    ds->getFace()->addPanel("retina", &rp);
    rp.setSize(150, 150);
    rp.setPosition(300, 300);

    ds->addBody(new BoxBody(btVector3(1, 0.5, 0.5), btVector3(3, 3, 3)*0.5));
    ds->addBody(new BoxBody(btVector3(0, 2.5, 0.5), btVector3(3, 2, 3)*0.5));
    ds->addBody(new BoxBody(btVector3(1, 0.5, 0.8), btVector3(2, 3, 1)*0.5));
    ds->addBody(new BoxBody(btVector3(3, 0.5, 1.5), btVector3(2, 2, 1)*0.5));

    runGLWindow(0, NULL, 1224, 1000, VERSION, ds);

}

void runZoomDemo() {

    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    ds->addGround(50, 50, 5);

    {
        SpiderBody* spider = new SpiderBody(3, btVector3(0, 0, 5 + 1 * 2));
        ds->addBody(spider);
    }


    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

}

void runHumanoid() {

    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    ds->addGround(50, 50, 5);

    Humanoid* h = new Humanoid(btVector3(0, 1.5, 0));
    ds->addBody(h);

    Humanoid* h2 = new Humanoid(btVector3(0, 0.5, 0));
    ds->addBody(h2);

    RetinaPanel rp(h->eyeRetina);
    ds->getFace()->addPanel("retina", &rp);
    rp.setSize(150, 150);
    rp.setPosition(300, 600);

    RetinaPanel rp2(h->lhRetina);
    ds->getFace()->addPanel("lhRetina", &rp2);
    rp2.setSize(150, 150);
    rp2.setPosition(600, 600);

    BrainOutsPanel bop(h->brain, 50);
    ds->getFace()->addPanel("brainOuts", &bop);
    bop.setPosition(400, 400);


    runGLWindow(0, NULL, 1024, 800, VERSION, ds);

}


