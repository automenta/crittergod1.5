#include "button.h"

Button::Button(const char* text) {
    active = true;
    model = NULL;

    isTransparant = false;
    // 	cmd = Commands::Instance();
    setSize(60, 40);

    if (text != NULL) {
        addText("label", text);
    }

}

bool Button::onMouseButton(int button, int state, int x, int y) {
    if (isMouseOver(x, y)) {
        if (button == 0) {
            if (state == 0) {
                onPressed();
                return true;
            } else {
                onReleased();
                return true;
            }
        }
    }
    return false;
}

void Button::draw() {
    if (active) {
        drawBackground();
        drawBorders();
        drawChildren();
    }
}

Button::~Button() {
}
