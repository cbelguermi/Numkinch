//
// Created by Chloé Belguermi on 20/11/2017.
//

#include "Text.h"
#include "../Core/GameEngine.h"

Text::Text(TTF_Font * font, Uint8 colorR, Uint8 colorG, Uint8 colorB, const char * text, int rectX, int rectY)
        : _textWidth(0), _textHeight(0)
{
    _font = font;
    _textColor = { colorR, colorG, colorB };
    _surface = TTF_RenderText_Blended(_font, text, _textColor);
    _texture = SDL_CreateTextureFromSurface(GameEngine::getGameRenderer(), _surface);
    SDL_QueryTexture(_texture, nullptr, nullptr, & _textWidth, & _textHeight);
    _distanceRect = { rectX, rectY, _textWidth, _textHeight };
}

void Text::update(const char * text)
{
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
    _surface = TTF_RenderText_Blended(_font, text, _textColor);
    _texture = SDL_CreateTextureFromSurface(GameEngine::getGameRenderer(), _surface);
}

void Text::render()
{
    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, & _distanceRect);
}

void Text::cleanup()
{
    TTF_CloseFont(_font);
    SDL_DestroyTexture(_texture);
    SDL_FreeSurface(_surface);
}
