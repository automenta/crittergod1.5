#ifndef GLSCENE_H
#define GLSCENE_H

// Standard OpenGL/GLX
#include <GL/gl.h>
#include <SDL/SDL.h>

/* for keys used in the program */
#include <SDL/SDL_keysym.h>

class Spacetime {
	public:
		Spacetime();
		virtual ~Spacetime();

		virtual void init(int w, int h);
		// This is the drawing function. Whatever needs to be drawn, goes in this function

		virtual void resize(int w, int h);

		virtual void forward(SDL_Event *event);

		virtual void draw();
		// glwindow passes events to the scene
		virtual void handlekeyPressed(const SDLKey& key);
		virtual void handlekeyReleased(const SDLKey& key);

		virtual void handlemousebuttonPressed(int x, int y, const int&);
		virtual void handlemousebuttonReleased(int x, int y, const int&);

		virtual void handleMouseMotionRel(int x, int y);
		virtual void handleMouseMotionAbs(int x, int y);

		virtual void clean();
};

#endif	// GLSCENE_H
