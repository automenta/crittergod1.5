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

using namespace std;
#include <map>

class BrainPanel : public Panel, ButtonModel {
    int frame;
    Brain* brain;
    //btVector3** neuronPosition;

    float firingThreshold;
    float potentialDecay;
    Button *decThreshButton;
    Button *incThreshButton;
    
    Button *decPotDecay;
    Button *incPotDecay;

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

        decThreshButton = new Button("Dec Fire Thresh");
        decThreshButton->setModel(this);
        decThreshButton->setSize(80, 25);
        decThreshButton->setPosition(10, 10);

        incThreshButton = new Button("Inc Fire Thresh");
        incThreshButton->setModel(this);
        incThreshButton->setSize(80, 25);
        incThreshButton->setPosition(10, 40);

        decPotDecay = new Button("Dec Pot Decay");
        decPotDecay->setModel(this);
        decPotDecay->setSize(80, 25);
        decPotDecay->setPosition(10, 70);

        incPotDecay = new Button("Inc Pot Decay");
        incPotDecay->setModel(this);
        incPotDecay->setSize(80, 25);
        incPotDecay->setPosition(10, 100);

        addWidgetPanel("decThresh", decThreshButton);
        addWidgetPanel("incThresh", incThreshButton);

        addWidgetPanel("decDecay", decPotDecay);
        addWidgetPanel("incDecay", incPotDecay);

    }
    virtual void onChange(Button* b, int state) {
        if (!state) {
            if (b == incThreshButton) {
                setThresh(firingThreshold + 0.05);
            }
            else if (b == decThreshButton) {
                setThresh(firingThreshold - 0.05);
            }
            else if (b == decPotDecay) {
                setPotentialDecay(potentialDecay - 0.01);
            }
            else if (b == incPotDecay) {
                setPotentialDecay(potentialDecay + 0.01);
            }

        }
    }

    virtual void draw();

};

#endif	/* _BRAINPANEL_H */

