//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "MenuBackground.h"

MenuBackground::MenuBackground(const char * path) : Element(path) {

}

void MenuBackground::render() {

    loadImage();

    loadTexture();

    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, nullptr);
}

void MenuBackground::handleEvent(SDL_Event * event) {

}

void MenuBackground::cleanup() {

   Element::cleanup();
}