/* 
 * File:   Rect.h
 * Author: seh
 *
 * Created on February 27, 2010, 5:07 PM
 */

#ifndef _RECT_H
#define	_RECT_H

#include <math.h>

#include "../physics/btBulletDynamicsCommon.h"

class Rect {
public:
    btVector3* pos;
    btVector3* size;
    btVector3* fillColor;

//    Rect() {
//        Rect(0, 0, 0, 1, 1);
//    }

    Rect(float x=0, float y=0, float z=0, float w=1, float h=1) {
        pos = new btVector3(x, y, z);
        size = new btVector3(w, h, 1.0);
        fillColor = new btVector3(1, 1, 1);
    }

    void span(float x1, float y1, float x2, float y2) {
        float w = fabs(x2 - x1);
        float h = fabs(y2 - y1);
        *size = btVector3(w, h, 1.0);
        *pos = btVector3((x1+x2)/2.0, (y1+y2)/2.0, 0);
    }

    virtual ~Rect() {

    }

private:

};

#endif	/* _RECT_H */

