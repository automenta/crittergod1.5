/* 
 * File:   BrainPanel.h
 * Author: seh
 *
 * Created on February 22, 2010, 3:09 PM
 */

#ifndef _BRAINPANEL_H
#define	_BRAINPANEL_H

#include "../neural/Brain.h"
#include "../widget2d/panel.h"
#include "../widget2d/button.h"
#include "../widget2d/slider.h"

using namespace std;
#include <map>

class BrainPanel : public Panel, SliderModel {
    int frame;
    Brain* brain;
    //btVector3** neuronPosition;

    float firingThreshold;
    float potentialDecay;

    HSlider *ftSlider;
    HSlider *pdSlider;

public:

    void setThresh(float newThresh) {
        firingThreshold = newThresh;
        brain->setFiringThreshold(firingThreshold);
    }

    void setPotentialDecay(float newDecay) {
        potentialDecay = newDecay;
        brain->setPotentialDecay(potentialDecay);
    }

    BrainPanel(Brain* b) : Panel(), brain(b), frame(0) {

        setThresh(0.8);
        setPotentialDecay(0.99);

        setSize(150, 150);
        setPosition(25, 25);

        ftSlider = new HSlider(&firingThreshold, 0, 1.0);
        ftSlider->span(5, 5, 100, 25);
        ftSlider->setModel(this);
        addPanel("ft", ftSlider);

        pdSlider = new HSlider(&potentialDecay, 0, 1.0);
        pdSlider->span(5, 30, 100, 50);
        pdSlider->setModel(this);
        addPanel("pd", pdSlider);
        
    }
    virtual void onChange(HSlider* s) {

        if (s == ftSlider) {
            setThresh(s->value());
        }
        else if (s == pdSlider) {
            setPotentialDecay(s->value());
        }
                
    }

    virtual void draw();

};

#endif	/* _BRAINPANEL_H */

