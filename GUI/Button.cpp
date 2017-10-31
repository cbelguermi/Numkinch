//
// Created by Chloé Belguermi on 18/10/2017.
//

#include "Button.h"

Button::Button(const char * path, int x, int y) : Element(path) {

    _pressed = false;
    _btnRect.w = MENU_BUTTON_WIDTH;
    _btnRect.h = MENU_BUTTON_HEIGHT;
    _btnRect.x = x;
    _btnRect.y = y;
}

bool Button::pressed() const {

    return _pressed;
}

void Button::handleEvent(SDL_Event *event) {

    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        if ((x >= _btnRect.x) && (x <= (_btnRect.x + _btnRect.w)) && (y >= _btnRect.y) && (y <= (_btnRect.y + _btnRect.h)))
        {
            _pressed = true;
        }
    }
}

void Button::render() {

    loadImage();

    loadTexture();

    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, NULL, &_btnRect);
}

void Button::cleanup() {

    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
}