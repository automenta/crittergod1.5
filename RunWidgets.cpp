/* 
 * File:   RunWidgets.cpp
 * Author: seh
 * 
 * Created on February 23, 2010, 3:59 PM
 */

#include <iostream>
#include <string.h>

using namespace std;

#include "video/GLWindow.h"

#include "space/DefaultSpace.h"
#include "physics/OpenGL/GlutStuff.h"

#include "audio/Audio.h"

#include "widget2d/container.h"
#include "widget2d/panel.h"
#include "widget2d/button.h"
#include "widget2d/text.h"
#include "widget2d/slider.h"

#include "RunWidgets.h"

class SliderTestPanel : public Panel {

public:
    float a;
    float b;

    SliderTestPanel() : Panel() {

        a = b = 0.5;
        
        
        HSlider* hs = new HSlider(&a, 0, 1.0);
        hs->span(15, 15, 200, 40);
        addPanel("hslider", hs);

        VSlider* vs = new VSlider(&b, 0, 1.0);
        vs->span(15, 50, 50, 250);
        addPanel("vslider", vs);

    }
    
};

void runSliders() {
    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    SliderTestPanel *stp = new SliderTestPanel();
    stp->span(5,5,400,400);
    ds->getFace()->addPanel("stp", stp);

    runGLWindow(0, NULL, 1024, 800, "Sliders", ds);

    delete audio;

}

void runFont3D() {
    Audio* audio = new Audio();
    DefaultSpace* ds = new DefaultSpace(audio);

    char const *file = "media/font/OCRA.ttf";

    // Initialise FTGL stuff
    static FTPolygonFont* font = new FTPolygonFont(file);

    if(font->Error())
    {
        fprintf(stderr, "could not load font `%s'\n", file);
        return;
    }

    font->FaceSize(40);
    font->CharMap(ft_encoding_unicode);

    class FontBody : public AbstractBody {
        float n;
        virtual void draw() {
            glEnable(GL_LIGHTING);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_TEXTURE);

            glPushMatrix();
                //glColorMaterial(GL_FRONT, GL_DIFFUSE);
                glTranslatef(0.0, 0.0, 20.0);
                glScalef(-0.1, 0.1, 0.1);
//                glRotatef(n / 1.11, 0.0, 1.0, 0.0);
//                glRotatef(n / 2.23, 1.0, 0.0, 0.0);
//                glRotatef(n / 3.17, 0.0, 0.0, 1.0);
                //glColor3f(1.0, 0.5, 1.0);
                //drawText3D(font[fontindex], "SpaceGraph", 0, 0, 20.0);
                font->Render("SpaceGraph");
            glPopMatrix();

            //n += 1.0;
        }
    };

    ds->addBody(new FontBody());
    
    runGLWindow(0, NULL, 1024, 800, "Sliders", ds);

    delete audio;

}
