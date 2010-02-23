#ifndef PANEL_H
#define PANEL_H

#include "../math/vector2f.h"
#include "container.h"

using namespace std;

class Panel : public Container
{
	public:
		Panel();
		~Panel();
		virtual void		draw();
		unsigned int	zaxis;

                virtual bool onMouseMove(int x, int y);
                virtual bool onMouseButton(int button, int state, int x, int y);

                float bgColor[4];
                
	protected:
                Vector3f dragStart;                
                       
		virtual void	drawBackground();
		virtual void	drawBorders();

                bool dragging;
	private:

};

#endif
