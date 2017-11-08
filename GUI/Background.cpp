//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "Background.h"

Background::Background(const char * path) : Element(path) {}

void Background::render()
{
    loadImage();

    loadTexture();

    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, nullptr);
}

void Background::handleEvent(SDL_Event * event) {}

void Background::cleanup()
{
   Element::cleanup();
}