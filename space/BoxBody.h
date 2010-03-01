/*
 * BoxBody.h
 *
 *  Created on: Feb 13, 2010
 *      Author: seh
 */

#ifndef BOXBODY_H_
#define BOXBODY_H_

using namespace std;
#include <iostream>
#include <list>

#include "DefaultSpace.h"
#include "AbstractBody.h"

#include "../widget3d/Rect.h"
#include "../widget3d/TextRect.h"

#include <FTGL/ftgl.h>

typedef list<Rect*> RectList;

static FTFont *font;

class BoxBody : public AbstractBody {
public:

    btVector3* position;
    btVector3* size;
    list<Rect*> frontRects;

    BoxBody(btVector3* _position, btVector3* _size) : AbstractBody(), position(_position), size(_size) {

    }

    virtual void init() {
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(*position);

        btRigidBody* rb = createRigidShape(btScalar(1.), transform, new btBoxShape(*size));
        rb->setDamping(0.8, 0.8);


        char const *file = "media/font/OCRA.ttf";

        if (font == NULL) {
            font = new FTPolygonFont(file);
            //font = new FTOutlineFont(file);
            //font = new FTBufferFont(file);
            //font = new FTBitmapFont(file);

            if (font->Error()) {
                fprintf(stderr, "could not load font `%s'\n", file);
                return;
            }

            font->FaceSize(1);
            font->Depth(10);
            font->CharMap(ft_encoding_unicode);
        }

    }

    list<Rect*>* front() {
        return &frontRects;
    }

    virtual void preDraw() {
    }

    virtual void drawFront() {
        glPushMatrix();
        glScalef(size->getX()*2.0, size->getY()*2.0, 1.0);

        for (RectList::const_iterator ri = frontRects.begin(); ri != frontRects.end(); ++ri) {
            Rect *r = (*ri);

            btVector3* rpos = r->pos;
            btVector3* rsize = r->size;

            float d = 0.1;

            btVector3* bgColor = r->fillColor;


            if (bgColor != NULL) {
                glBegin(GL_QUADS);
                glColor4f(bgColor->getX(), bgColor->getY(), bgColor->getZ(), 1.0);
                glVertex3f(rpos->getX() - rsize->getX() / 2.0, rpos->getY() - rsize->getY() / 2.0, -rpos->getZ() - d);
                glVertex3f(rpos->getX() - rsize->getX() / 2.0, rpos->getY() + rsize->getY() / 2.0, -rpos->getZ() - d);
                glVertex3f(rpos->getX() + rsize->getX() / 2.0, rpos->getY() + rsize->getY() / 2.0, -rpos->getZ() - d);
                glVertex3f(rpos->getX() + rsize->getX() / 2.0, rpos->getY() - rsize->getY() / 2.0, -rpos->getZ() - d);
                glEnd();
            }

            TextRect* tr = dynamic_cast<TextRect*> (r);
            if (tr != NULL) {
                glPushMatrix();
                //glMaterialfv(GL_FRONT, GL_AMBIENT, front_ambient);
                //glColorMaterial(GL_FRONT, GL_DIFFUSE);
                //glEnable(GL_TEXTURE);

                glScalef(-1.0 / 2.0 * rsize->getX(), 1.0 / 2.0 * rsize->getY(), 1.0 / 2.0);
                glTranslatef(-1.0 + (rpos->getX())*2.0, 0.0 + (rpos->getY())*2.0, -d * 3);
                glColor4f(1.0, 1.0, 1.0, 1.0);
                font->Render(tr->text.c_str());
                glPopMatrix();

            }

        }

        glPopMatrix();
    }

    virtual void draw() {
    }

    virtual ~BoxBody();
};

#endif /* BOXBODY_H_ */
