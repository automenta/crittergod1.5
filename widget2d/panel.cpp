#include <stdio.h>

#include "../math/Math.h"

#include "panel.h"

Panel::Panel() {
    isTouchable = true;
    isTransparant = true;
    zaxis = 0;
    dragging = false;

    bgColor[0] = 0.1;
    bgColor[1] = 0.1;
    bgColor[2] = 0.1;
    bgColor[3] = 0.75;
}

void Panel::draw() {
    if (active) {
//        glPushMatrix();
//        {
//            glScalef(1.0, 1.0, 1.0);
            drawBackground();
            drawBorders();
            drawChildren();
//        }
//        glPopMatrix();
    }
}

void Panel::drawBackground() {
    if (isTransparant) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
    }

    glColor4f(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);

    //glColor4f(0.05f, 0.05f, 0.05f, 0.75f);
    glBegin(GL_QUADS);
    glVertex2f(absPosition.x, absPosition.y + height());
    glVertex2f(absPosition.x, absPosition.y);
    glVertex2f(absPosition.x + width(), absPosition.y);
    glVertex2f(absPosition.x + width(), absPosition.y + height());
    glEnd();

    if (isTransparant)
        glDisable(GL_BLEND);
}

void Panel::drawBorders() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(absPosition.x, absPosition.y + height());
    glVertex2f(absPosition.x, absPosition.y);

    glVertex2f(absPosition.x, absPosition.y);
    glVertex2f(absPosition.x + width(), absPosition.y);

    glVertex2f(absPosition.x + width(), absPosition.y);
    glVertex2f(absPosition.x + width(), absPosition.y + height());

    glVertex2f(absPosition.x + width(), absPosition.y + height());
    glVertex2f(absPosition.x, absPosition.y + height());
    glEnd();
}

Panel::~Panel() {
}

bool Panel::onMouseMove(int x, int y) {
    if (dragging) {
        int px = x - dragStart.x;
        int py = y - dragStart.y;

        setPosition(px, py);
        return true;
    }

    //    if (isMouseOver(x, y)) {
    //        if (!)
    //        onMouseEnter();
    //    }
    //    else {
    //        onMouseExit();
    //    }

    Container::onMouseMove(x, y);

    return false;
}

bool Panel::onMouseButton(int button, int state, int mx, int my) {
    if (Container::onMouseButton(button, state, mx, my))
        return true;

    if (button == 0) {
        if (state == 0) {
            if (isMouseOver(mx, my)) {
                dragStart = Vector3f(mx - x(), my - y(), 0);
                dragging = true;
                return true;
            }
        } else {
            if (dragging) {
                dragging = false;
                return true;
            }
        }
    }


    return false;

}
