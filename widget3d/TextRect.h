/* 
 * File:   TextRect.h
 * Author: seh
 *
 * Created on February 22, 2010, 11:05 AM
 */

#ifndef _TEXTRECT_H
#define	_TEXTRECT_H

#include "Rect.h"

using namespace std;
#include <string>

class TextRect : public Rect {

public:
    string text;


    TextRect(const char* _text, float w=1.0, float h=1.0)  {
        Rect();
        text = _text;
        this->pos = new btVector3(0,0,0);
        this->size = new btVector3(w, h, 1.0);
        this->fillColor = NULL;
    }

    virtual ~TextRect() {

    }
    
private:

};

#endif	/* _TEXTRECT_H */

