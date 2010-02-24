/* 
 * File:   PointerPanel.h
 * Author: seh
 *
 * Created on February 23, 2010, 9:24 PM
 */

#ifndef _POINTERPANEL_H
#define	_POINTERPANEL_H

#include "../space/DefaultSpace.h"
#include "../space/AbstractBody.h"

#include "../widget2d/panel.h"
#include "../widget2d/text.h"

class PointerPanel : public Panel {

    DefaultSpace *space;
    Text* pickedLabel;
    Text* focusedLabel;

public:
    PointerPanel(DefaultSpace *sp) : Panel(), space(sp) {

        pickedLabel = new Text("Picked");
        addPanel("pickedLabel", pickedLabel);
        pickedLabel->span(5,15,60,35);

        focusedLabel = new Text("Focused");
        addPanel("focusedLabel", focusedLabel);
        focusedLabel->span(5,40,60,65);
    }

    virtual void draw() {
        char pickedText[128];
        snprintf(pickedText, 128, "%p", space->touched);
        pickedLabel->set(pickedText);
        
        Panel::draw();
    }

    virtual ~PointerPanel() {

    }

private:

};

class TouchedBodyHilite : public AbstractBody {

public:
    DefaultSpace *space;
    bool drawBox, drawSphere;

    TouchedBodyHilite(DefaultSpace* ds) : AbstractBody(), space(ds) {
        drawBox = drawSphere = true;
    }

    virtual void draw() {
        btRigidBody* body = space->touchedBody;
        if (body!=NULL) {
            if (drawSphere) {
                btVector3 c;
                btScalar r;
                body->getCollisionShape()->getBoundingSphere(c, r);
                c += body->getWorldTransform().getOrigin();

                glBegin(GL_LINES);
                glColor3f(1, 1, 0);
                {
                    glVertex3f(c.x()-r, c.y(), c.z());
                    glVertex3f(c.x()+r, c.y(), c.z());
                    glVertex3f(c.x(), c.y()-r, c.z());
                    glVertex3f(c.x(), c.y()+r, c.z());
                    glVertex3f(c.x(), c.y(), c.z()-r);
                    glVertex3f(c.x(), c.y(), c.z()+r);
                }

                glEnd();

            }
            if (drawBox) {
                btVector3 a, b;
                body->getAabb(a, b);

                glBegin(GL_LINES);
                glColor3f(0, 1, 1);

                glVertex3f(b.x(), a.y(), a.z());
                glVertex3f(b.x(), b.y(), a.z());

                glVertex3f(b.x(), a.y(), b.z());
                glVertex3f(b.x(), b.y(), b.z());

                glVertex3f(a.x(), a.y(), a.z());
                glVertex3f(a.x(), b.y(), a.z());

                glVertex3f(a.x(), a.y(), b.z());
                glVertex3f(a.x(), b.y(), b.z());

                glVertex3f(b.x(), a.y(), a.z());
                glVertex3f(b.x(), a.y(), b.z());

                glVertex3f(a.x(), a.y(), a.z());
                glVertex3f(a.x(), a.y(), b.z());

                glVertex3f(b.x(), b.y(), a.z());
                glVertex3f(b.x(), b.y(), b.z());

                glEnd();
            }
        }
    }
};


#endif	/* _POINTERPANEL_H */

