#ifndef TEXTPRINTER_H
#define TEXTPRINTER_H

#include <stdarg.h>
#include <string>

#include <FTGL/ftgl.h>
#include "../math/vector2f.h"

// #define FTGL_TEXTURE 5
#include <GL/gl.h>

using namespace std;

class Textprinter
{
	public:
		static Textprinter* Instance();
		void printTextprinter();

		// get bounding boxes
// 		FTPoint getBBox(const string& str);
// 		FTPoint getBBox(const char *fmt, ...);
		unsigned int getWidth(const char *fmt, ...);
		unsigned int getWidth(const string& str);
		//unsigned int getWidth(const int& number);
		Vector2f getDimensions(const string& str);

		string getFormattedString(const char *fmt, ...);

		// print left aligned
		//void print(int x, int y, const char *fmt, ...);
		//void print(int x, int y, const string& str);
		//void print(int x, int y, const long unsigned int& longuint);
		void print(const Vector2f& pos, const string& str);
		//void print(const Vector2i& pos, const unsigned int* num);
		// print right aligned
		void printR(float x, float y, const char *fmt, ...);

		void setUpFonts();

	protected:
		Textprinter();
	private:
		FTFont** fonts;
		
		va_list ap;     /* our argument pointer */
		char text[256];

};

#endif
