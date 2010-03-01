/* 
 * File:   Rect.h
 * Author: seh
 *
 * Created on February 27, 2010, 5:07 PM
 */

#ifndef _RECT_H
#define	_RECT_H

#include "../physics/btBulletDynamicsCommon.h"

class Rect {

public:
    btVector3* pos;
    btVector3* size;
    btVector3* fillColor;

    Rect()  {
        Rect(0,0,0,1,1);
    }

    Rect(float x, float y, float z, float w, float h) {
        pos = new btVector3(x, y, z);
        size = new btVector3(w, h, 1.0);
        fillColor = new btVector3(1,1,1);
    }

    virtual ~Rect() {
        
    }
    
private:

};

#endif	/* _RECT_H */

