/* 
 * File:   slider.h
 * Author: seh
 *
 * Created on February 23, 2010, 3:54 PM
 */

#ifndef _SLIDER_H
#define	_SLIDER_H

using namespace std;
#include <iostream>

#include "panel.h"

class HSlider;

//TODO Make Slider abstract
class SliderModel {
public:
    virtual void onChange(HSlider *h) { }
};

class HSlider : public Panel {
protected:
    float *val;
    float pct;
    float min, max;
    float knobPosition;
    bool sliding;
    SliderModel *model;

public:

    HSlider(float *_value, float _min, float _max) : val(_value), min(_min), max(_max), model(NULL) {
        sliding = false;

        updateValue(*_value);
    }

    float value() { return *val; }
    
    void setModel(SliderModel* sm) {
        model = sm;
    }

    virtual void draw() {
        Panel::draw();

        int knobWidth = float(width()) / 10.0;
        int heightMargin = 4;

        
        pct = (value() - min) / (max - min);

        knobPosition = pct * (this->width() - knobWidth * 2);

        drawRect(getKnobR(), getKnobG(), getKnobB(),
                knobPosition + this->absX() + knobWidth / 2,
                heightMargin + this->absY(),
                knobWidth,
                height() - heightMargin * 2);
    }

    virtual float getKnobR() {
        return 0.5 + 0.5 * (1.0 - pct);
    }

    virtual float getKnobB() {
        return 0.5;
    }

    virtual float getKnobG() {
        return 0.5 + 0.5 * pct;
    }

    virtual void updateSlide(int x, int y) {
        float rx = x - this->absX();

        float pct = rx / float(this->width());
        updatePercent(pct);
    }

    virtual bool onMouseMove(int x, int y) {
        if (isMouseOver(x, y)) {
            if (sliding) {
                updateSlide(x, y);
            }
        }
    }

    virtual bool onMouseButton(int button, int state, int x, int y) {
        if (isMouseOver(x, y)) {
            if (button == 0) {
                if (state == 1)
                    sliding = false;
                else {
                    sliding = true;
                    updateSlide(x, y);
                }
                return true;
            }
        } else {
            sliding = false;
        }

        return false;
    }

    void updateValue(float newValue) {
        *val = fmax(min, fmin(newValue, max));

        if (model!=NULL) {
            model->onChange(this);
        }
    }

    void updatePercent(float pct) {
        updateValue(min + pct * (max - min));
    }

    virtual ~HSlider() {

    }

};

class VSlider : public HSlider {
public:

    VSlider(float *_value, float _min, float _max) : HSlider(_value, _min, _max) {

    }

    virtual void draw() {
        Panel::draw();

        int knobHeight = float(height()) / 10.0;
        int widthMargin = 4;

        pct = (*val - min) / (max - min);
        knobPosition = pct * (this->height() - knobHeight * 2);

        drawRect(getKnobR(), getKnobG(), getKnobB(),
                widthMargin + this->absX(),
                knobPosition + this->absY() + knobHeight / 2,
                width() - widthMargin * 2, knobHeight);

    }

    virtual void updateSlide(int x, int y) {
        float ry = y - this->absY();

        float pct = ry / float(this->height());
        updatePercent(pct);
    }

    virtual ~VSlider() {

    }

};

#endif	/* _SLIDER_H */

