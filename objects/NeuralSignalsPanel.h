/* 
 * File:   BrainOutputPanel.h
 * Author: seh
 *
 * Created on February 22, 2010, 4:58 PM
 */

#ifndef _BRAINOUTPUTPANEL_H
#define	_BRAINOUTPUTPANEL_H

#include "../neural/Brain.h"
#include "../widget2d/panel.h"

#include <vector>
#include <GL/gl.h>

class NeuralSignalsPanel : public Panel {


public:
    vector<float>* input;
    float **v;

    int numSignals;
    int historySize;

    bool normalize;

    NeuralSignalsPanel(vector<float>* b, int _historySize) : Panel(), input(b), historySize(_historySize), normalize(true) {
        setSize(250, 200);
        setPosition(355, 355);

        numSignals = -1;
        reinit();

    }

    void reinit() {
        unsigned nextSignals = input->size();
        if (nextSignals!=numSignals) {
            numSignals = nextSignals;

            v = new float*[numSignals];
            for (unsigned i = 0; i < numSignals; i++) {
                v[i] = new float[historySize];

                for (unsigned j = 0; j < historySize; j++) {
                    v[i][j] = 0;
                }
            }
        }

    }

    void update() {
        reinit();

        if (numSignals < 0)
            return;
        if (historySize < 0)
            return;

        unsigned numOuts = input->size();

        for (unsigned i = 0; i < numOuts; i++) {
            for (unsigned j = 1; j < historySize; j++) {
                v[i][j-1] = v[i][j];
            }
            v[i][historySize-1] = ((*input)[i]);
        }        
    }

    virtual void draw() {
        update();     

        int hWidth = floor(float(width()) / float(historySize));
        int oHeight = floor(float(height()) / float(numSignals));

        double min=-1, max=1;

        if (normalize) {
            min = max = v[0][0];
            for (unsigned o = 0; o < numSignals; o++) {
               for (unsigned h = 0; h < historySize; h++) {
                   double a = v[o][h];
                   if (a < min) min = a;
                   if (a > max) max = a;
               }
            }
            if (abs(min) > abs(max)) {
                max = -min;
            }
            else if (abs(min) < abs(max)) {
                min = -max;
            }
        }

        unsigned x = 0;
        unsigned y = oHeight/2;
        drawRect(0, 0, 0, this->x(), this->y(), width(), height());
        
        for (int o = 0; o < numSignals; o++) {
           for (int h = 0; h < historySize; h++) {
                float a = fmin(a, max);
                a = fmax(a, min);
                a = (v[o][h]-min)/(max-min);

                double r, g, b;
                if (v[o][h] < 0)
                {
                    r = a;
                    g = a/4.0;
                    b = a/2.0;
                }
                else {
                    b = a/4.0;
                    g = a;
                    r = a/2.0;
                }
                float bh = (1.0 * abs(a - 0.5)) * oHeight;
                drawRect(r, g, b, x + this->x(), y+this->y()+(1.0 - bh)/2, hWidth, bh);
                x += hWidth;
             }
            x = 0;
            y += oHeight;
        }
    }

    virtual ~NeuralSignalsPanel() {

    }
    
private:

};

class BrainOutsPanel : public NeuralSignalsPanel {

public:
    BrainOutsPanel(Brain* b, int historySize) : NeuralSignalsPanel(&(b->outValues), historySize) {
        //setMin(-1);
        //setMax(1);
    }
    
};
class BrainInsPanel : public NeuralSignalsPanel {

public:
    BrainInsPanel(Brain* b, int historySize) : NeuralSignalsPanel(&(b->inValues), historySize) {
        //setMin(-1);
        //setMax(1);
    }

};

//class NeuralSignalsPanel : public Panel {
//
//    Brain* brain;
//
//    float **v;
//
//    int historySize;
//
//    bool normalize;
//
//public:
//    NeuralSignalsPanel(Brain* b, int _historySize) : Panel(), brain(b), historySize(_historySize), normalize(true) {
//        setSize(250, 200);
//        setPosition(355, 355);
//
//        unsigned numOuts = b->outs.size();
//
//        v = new float*[numOuts];
//        for (unsigned i = 0; i < numOuts; i++) {
//            v[i] = new float[historySize];
//
//            for (unsigned j = 0; j < historySize; j++) {
//                v[i][j] = 0;
//            }
//        }
//
//    }
//
//    void update() {
//        unsigned numOuts = brain->outs.size();
//
//        for (unsigned i = 0; i < numOuts; i++) {
//            for (unsigned j = 1; j < historySize; j++) {
//                v[i][j-1] = v[i][j];
//            }
//            v[i][historySize-1] = brain->outs[i]->getOutput();
//        }
//    }
//
//    void drawRect(double r, double g, double b, double x, double y, double w, double h) {
//        glColor4f(r, g, b, 0.9);
//
//        glBegin(GL_QUADS);
//		glVertex2f(x, y);
//                glVertex2f(x+w, y);
//		glVertex2f(x+w, y+h);
//                glVertex2f(x, y+h);
//	glEnd();
//    }
//
//    virtual void draw() {
//        //Panel::draw();
//
//        update();
//
//        int numOuts = brain->outs.size();
//
//
//        int hWidth = floor(float(width()) / float(historySize));
//        int oHeight = floor(float(height()) / float(numOuts));
//
//        double min=0, max=1.0;
//
//        if (normalize) {
//            min = max = v[0][0];
//            for (int o = 0; o < numOuts; o++) {
//               for (int h = 0; h < historySize; h++) {
//                   double a = v[o][h];
//                   if (a < min) min = a;
//                   if (a > max) max = a;
//               }
//            }
//        }
//
//        unsigned x = 0;
//        unsigned y = oHeight/2;
//        drawRect(0, 0, 0, this->x(), this->y(), width(), height());
//
//        for (int o = 0; o < numOuts; o++) {
//           for (int h = 0; h < historySize; h++) {
//                float a = (v[o][h]-min)/(max-min);;
//                double r, g, b;
//                {
//                    r = a/4.0;
//                    g = a/2.0;
//                    b = a;
//                }
//                float bh = floor((a / 1.0) * float(oHeight));
//                drawRect(r, g, b, x + this->x(), y+this->y()+(1.0 - bh)/2, hWidth, bh);
//                x += hWidth;
//             }
//            x = 0;
//            y += oHeight;
//        }
//    }
//
//    virtual ~NeuralSignalsPanel() {
//
//    }
//
//private:
//
//};

#endif	/* _BRAINOUTPUTPANEL_H */

