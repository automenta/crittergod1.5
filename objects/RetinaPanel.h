/* 
 * File:   RetinaPanel.h
 * Author: seh
 *
 * Created on February 22, 2010, 7:35 PM
 */

#ifndef _RETINAPANEL_H
#define	_RETINAPANEL_H

#include "../bio/Retina.h"
#include "../widget2d/panel.h"

class RetinaPanel : public Panel {
    Retina *retina;
                                  
public:
    RetinaPanel(Retina* r) : Panel(), retina(r) {
        
    }

    virtual void draw() {
        unsigned wx = width()/retina->width;
        unsigned wy = height()/retina->height;

        unsigned px = 0;
        unsigned py = 0;
        
        drawRect(0, 0, 0, this->x(), this->y(), width(), height());

        for (unsigned y = 0; y< retina->height; y++) {
            for (unsigned x = 0; x < retina->width; x++) {

                float r = retina->pixel[x][y].getX();
                float g = retina->pixel[x][y].getY();
                float b = retina->pixel[x][y].getZ();

                drawRect(r, g, b, this->x() + px, this->y() + py, wx, wy);
                
                px += wx;
            }

            px = 0;
            py += wy;
        }
    }

    virtual ~RetinaPanel() {
        
    }
private:

};

#endif	/* _RETINAPANEL_H */

