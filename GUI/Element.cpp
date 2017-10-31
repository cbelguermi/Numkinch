//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "Element.h"

Element::Element(const char * path) {

    _imagePath = path;
    _surface = NULL;
    _texture = NULL;
}

void Element::loadImage() {

    try {
        _surface = IMG_Load(_imagePath);
        if (_surface == NULL)
            throw "Surface init failed";
    }
    catch (char * str) {
        SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(),
                                 GameEngine::getGameWindow());
    }
}

void Element::loadTexture() {

    try {
        _texture = SDL_CreateTextureFromSurface(GameEngine::getGameRenderer(), _surface);
        if (_texture == NULL)
            throw "Texture init failed";
    }
    catch (char * str) {
        SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(),
                                 GameEngine::getGameWindow());
    }
}

Element::~Element() {

    _imagePath = NULL;
    _texture = NULL;
    _surface = NULL;
}
