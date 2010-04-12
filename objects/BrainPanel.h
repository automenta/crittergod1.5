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

        addText("ftLabel", 5, 10, "Firing Threshold");
        ftSlider = new HSlider(&firingThreshold, 0, 1.5);
        ftSlider->span(5, 25, 100, 55);
        ftSlider->setModel(this);
        addPanel("ft", ftSlider);

        addText("pdLabel", 5, 75, "Potential Decay");
        pdSlider = new HSlider(&potentialDecay, 0, 1.5);
        pdSlider->span(5, 105, 100, 135);
        pdSlider->setModel(this);
        addPanel("pd", pdSlider);
        
    }
    virtual void onChange(HSlider* s) {

        if (s == ftSlider) {
            cout << "Firing Threshold: " << s->value() << "\n";
            setThresh(s->value());
        }
        else if (s == pdSlider) {
            cout << "Potential Decay: " << s->value() << "\n";
            setPotentialDecay(s->value());
        }
                
    }

    virtual void draw();

};

#endif	/* _BRAINPANEL_H */

