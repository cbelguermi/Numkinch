//
// Created by Chloé Belguermi on 07/11/2017.
//

#ifndef NUMKINCH_SPRITE_H
#define NUMKINCH_SPRITE_H


#include "Element.h"

class Sprite : public Element {

private:
    SDL_Rect _spriteRect;

public:
    Sprite(const char * path, int x, int y, int w, int h);

    void handleEvent(SDL_Event *event) override;

    void render() override;

    void cleanup() override;
};


#endif //NUMKINCH_SPRITE_H
