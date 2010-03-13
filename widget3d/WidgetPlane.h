/* 
 * File:   WidgetPlane.h
 * Author: seh
 *
 * Created on March 5, 2010, 5:46 PM
 */

#ifndef _WIDGETPLANE_H
#define	_WIDGETPLANE_H

#include "../space/DefaultSpace.h"

class WidgetPlane {
    DefaultSpace* space;
    
public:
    WidgetPlane(DefaultSpace* _space) : space(_space) {

    }
    
    virtual ~WidgetPlane() {

    }

private:

};

#endif	/* _WIDGETPLANE_H */

