using namespace std;
#include <iostream>

#include "text.h"
#include "button.h"

#include "container.h"

Container::Container() {
    active = true;
    isContainer = true;
}

void Container::draw() {
    if (active)
        drawChildren();
}

void Container::drawChildren() {
    for (childit = children.begin(); childit != children.end(); childit++) {
        childit->second->draw();
    }
}

Widget* Container::addPanel(const string& name, Widget* nwidget) {
    children[name] = nwidget;
    children[name]->parent = this;

    return children[name];
}

Widget* Container::addText(const string& name, unsigned int posx, unsigned int posy, const string& textstring) {
    Text* t = new Text(textstring);
    t->parent = this;
    t->setPosition(posx, posy);
    t->active = true;
    children[name] = t;

    return children[name];
}

Widget* Container::addText(const string& name, const string& textstring) {
    Text* t = new Text(textstring);
    t->parent = this;
    // 	t->translate(posx, posy);
    t->hcenter = true;
    t->vcenter = true;
    t->set(textstring);
    t->active = true;
    children[name] = t;

    return children[name];
}


bool Container::onMouseMove(int x, int y) {
    bool t = false;
    if (active) {
        for (childit = children.begin(); childit != children.end(); childit++) {
            if (childit->second->onMouseMove(x, y)) {
                t = true;
            }
        }
    }

    return t;
}

bool Container::onMouseButton(int button, int state, int x, int y) {
    bool t = false;
    if (active) {
        for (childit = children.begin(); childit != children.end(); childit++) {
            if (childit->second->onMouseButton(button, state, x, y))
                t = true;
        }
    }
    return t;

}

//Widget* Container::addWidgetButton( const string& name, const Vector2i& pos, const Vector2i& dimensions, const string& textstring, const Vector2i& textpos, const cmdsettings& cmds, unsigned int responsetime, unsigned int minfresponsetime, unsigned int fresponseinterval )
//{
//	Button* t = new Button();
//	t->parent = this;
//	t->translate(pos.x, pos.y);
//	t->v_width = dimensions.x;
//	t->v_height = dimensions.y;
//	t->addWidgetText( "btext", textpos.x, textpos.y, textstring );
//	t->genEvent(1, name, cmds, responsetime, minfresponsetime, fresponseinterval);
//	t->active = true;
//	children[name] = t;
//
//	return children[name];
//}
//
//Widget* Container::addWidgetButton( const string& name, const Vector2i& pos, const Vector2i& dimensions, const string& textstring, const cmdsettings& cmds, unsigned int responsetime, unsigned int minfresponsetime, unsigned int fresponseinterval )
//{
//	Button* t = new Button();
//	t->parent = this;
//	t->translate(pos.x, pos.y);
//	t->v_width = dimensions.x;
//	t->v_height = dimensions.y;
//	t->addWidgetText( "btext", textstring );
//	t->genEvent(1, name, cmds, responsetime, minfresponsetime, fresponseinterval);
//	t->active = true;
//	children[name] = t;
//
//	return children[name];
//}

bool Container::mouseOverChild(Widget** fWidget, int x, int y) {
    for (childit = children.begin(); childit != children.end(); childit++) {
        if ((childit->second->isTouchable && childit->second->active && childit->second->isMouseOver(x, y)) || !childit->second->isTouchable) {
            // RECURSIVE INTO CONTAINERS
            if (childit->second->isContainer) {
                Container* c = static_cast<Container*> (childit->second);
                if (c->mouseOverChild(fWidget, x, y)) {
                    return true;
                } else if (childit->second->isTouchable) {
                    *fWidget = childit->second;
                    return true;
                }
            } else if (childit->second->isTouchable) {
                *fWidget = childit->second;
                return true;
            }
        }
    }
    return false;
}

void Container::updateAbsPosition() {
    absPosition.x = position.x;
    absPosition.y = position.y;
    if (parent) {
        absPosition.x += parent->absPosition.x;
        absPosition.y += parent->absPosition.y;
    }

    // adjust children aswell
    for (childit = children.begin(); childit != children.end(); childit++)
        childit->second->updateAbsPosition();
}

Container::~Container() {
    for (childit = children.begin(); childit != children.end(); childit++)
        delete childit->second;
}
