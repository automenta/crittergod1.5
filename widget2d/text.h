#ifndef TEXT_H
#define TEXT_H

#include "widget.h"

using namespace std;

class Text : public Widget
{
	public:
		Text(const string& n_string);
		~Text();
		void		set(const string& n_string);
		virtual void		draw();
		string		v_string;
		Vector2f	dimensions;
	protected:
	private:
};

#endif
