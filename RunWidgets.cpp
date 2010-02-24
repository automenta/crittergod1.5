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