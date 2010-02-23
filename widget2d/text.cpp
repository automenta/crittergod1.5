using namespace std;
#include <iostream>

#include "text.h"

Text::Text(const string& n_string)
{
    active = true;
    set(n_string);
}

void Text::draw()
{


	//glColor3f(1.0f, 1.0f, 1.0f);

	if ( hcenter )
	{
		absPosition.x = parent->absPosition.x + (parent->width()/2) - (dimensions.x/2);
		absPosition.y = parent->absPosition.y + (parent->height()/2) - (dimensions.y/2) + dimensions.y;
		textprinter->print( absPosition, v_string );
	}
	else {
		textprinter->print( absPosition, v_string );
        }
}

void Text::set(const string& n_string)
{
	v_string = n_string;
	dimensions = textprinter->getDimensions(v_string);
}

Text::~Text()
{
}
