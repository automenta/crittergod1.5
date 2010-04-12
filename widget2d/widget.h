#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <map>

#include "textprinter.h"
#include "../math/vector3f.h"
#include "../math/vector2f.h"
#include <GL/gl.h>

using namespace std;

class Widget
{
	public:
		Widget();
		~Widget();

		Vector3f		position;
		Vector2f		absPosition;
                Vector2f                size;

                bool			hcenter;
                bool			vcenter;

		virtual void		draw();

                virtual bool onMouseMove(int x, int y);
                virtual bool onMouseButton(int button, int state, int x, int y);

//		virtual void		click(const int& button);
//		virtual void		release(const int& button);
                
		void			swap();

		bool			active;
		// movable (pickable) object
		bool			isMovable;
		// touchable object (allows ignoring containers as clickable)
		bool			isTouchable;
		// types
		bool			isContainer;

		// drawing
		bool			isTransparant;

                float absX() { return absPosition.x; }
                float absY() { return absPosition.y; }
                
                void span(float x1, float y1, float x2, float y2) {
                    float w = x2-x1;
                    float h = y2-y1;
                    setSize(w, h);
                    setPosition(x1, y1);
                }

                void setSize(float x, float y) {
                    size = Vector2f(x, y);
                }

		// width/height accessors
		float		height();
		float		width();

                float x() { return position.x; }
                float y() { return position.y; }
                float z() { return position.z; }


		// pointer to parent
		Widget*			parent;

		// is mouse over widget
		bool			isMouseOver( int x, int y );

		// widget ops
		virtual void		setPosition( float x, float y );

		virtual void		updateAbsPosition();

                void drawRect(double r, double g, double b, double x, double y, double w, double h) {
                    glColor4f(r, g, b, 0.9);

                    glBegin(GL_QUADS);
                            glVertex3f(x, y, 0);
                            glVertex3f(x+w, y, 0);
                            glVertex3f(x+w, y+h, 0);
                            glVertex3f(x, y+h, 0);
                    glEnd();
                }


	protected:
		Textprinter*		textprinter;


	private:
};

#endif
