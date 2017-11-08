//
// Created by Chloé Belguermi on 18/10/2017.
//

#ifndef NUMKINCH_BUTTON_H
#define NUMKINCH_BUTTON_H

#include "Element.h"

class Button : public Element {

private:
    SDL_Rect _btnRect;
    bool _pressed;

public:
    Button(const char * path, int x, int y, int w, int h);

    void handleEvent(SDL_Event *event) override;

    void render() override;

    void cleanup() override;

    bool pressed() const;
};


#endif //NUMKINCH_BUTTON_H