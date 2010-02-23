#ifndef BUTTON_H
#define BUTTON_H

#include "panel.h"

using namespace std;

class Button;

class ButtonModel {
public:
    //state: 0=released, 1=pressed
    virtual void onChange(Button* b, int state) {    }
};

class Button : public Panel {
public:
    Button(const char *text);
    ~Button();

    void setModel(ButtonModel *_model) {
        model = _model;
    }

    virtual bool onMouseButton(int button, int state, int x, int y);

    virtual void onPressed() {
        if (model != NULL) {
            model->onChange(this, 1);
        }
    }

    virtual void onReleased() {
        if (model != NULL) {
            model->onChange(this, 0);
        }
    }

    void draw();

    //void genEvent( const int& button, const string& name, const cmdsettings& cmds, unsigned int responsetime, unsigned int minfresponsetime, unsigned int fresponseinterval );
    // 		cmdsettings command;

private:
    // 		Commands* cmd;
    // 		vector<string> eventnames;

    ButtonModel *model;

    map<unsigned int, string> buttonlist;
    // 		typedef map <string, cmd*>::const_iterator cmdlist_iterator;
    // 		cmdlist_iterator cmdit;

    string eventname;
};

#endif
