//
// Created by Chloé Belguermi on 07/11/2017.
//

#include "Sprite.h"

Sprite::Sprite(const char * path, int x, int y, int w, int h) : Element(path) {

    _spriteRect.w = w;
    _spriteRect.h = h;
    _spriteRect.x = x;
    _spriteRect.y = y;
}

void Sprite::handleEvent(SDL_Event * event) {

}

void Sprite::render() {

    loadImage();

    loadTexture();

    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, &_spriteRect);

}

void Sprite::cleanup() {

    Element::cleanup();
}
