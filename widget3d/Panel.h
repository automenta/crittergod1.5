/* 
 * File:   Panel.h
 * Author: seh
 *
 * Created on March 5, 2010, 5:33 PM
 */

#ifndef _PANEL_H
#define	_PANEL_H

#include "../space/BoxBody.h"

class PanelBody : public BoxBody {
public:
    PanelBody(btVector3* _position, btVector3* _size) : BoxBody(_position, _size) {

    }

    virtual void preDraw() {
        btQuaternion front(0,0,0,0);
        front.setEulerZYX(0,0,0);
        btQuaternion q = rb->getWorldTransform().getRotation().slerp(front, 0.1);
        rb->getWorldTransform().setRotation(q);

        btVector3 groundProjection = rb->getWorldTransform().getOrigin();
        groundProjection.setZ(0);
        btVector3 r = rb->getWorldTransform().getOrigin().lerp(groundProjection, 0.1);
        rb->getWorldTransform().setOrigin(r);
    }

    
private:

};

#endif	/* _PANEL_H */

