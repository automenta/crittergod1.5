#include "widget.h"

Widget::Widget()
{
	textprinter = Textprinter::Instance();

	hcenter = false;
	vcenter = false;
	
	isMovable = false;
	isTouchable = false;
	isContainer = false;

	isTransparant = false;
	active = false;
        
        parent = NULL;
}

bool Widget::onMouseMove(int x, int y) { return false; }
bool Widget::onMouseButton(int button, int state, int x, int y) { return false; }

void Widget::draw() {}

bool Widget::isMouseOver(int x, int y)
{
	if ( active && x > absPosition.x && x < absPosition.x+width() && y > absPosition.y && y < absPosition.y+height() )
		return true;
	return false;
}

void Widget::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	updateAbsPosition();
}

void Widget::updateAbsPosition()
{
	absPosition.x = position.x;
	absPosition.y = position.y;
	if ( parent )
	{
		absPosition.x += parent->absPosition.x;
		absPosition.y += parent->absPosition.y;
	}
}

void Widget::swap()
{
	active = !active;
}

float Widget::height()
{
	if ( active )
		return size.y;
	return 0;
}

float Widget::width()
{
	if ( active )
		return size.x;
	return 0;
}

Widget::~Widget()
{
}
