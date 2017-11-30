//
// Created on 20/11/2017.
//

#include "CharacterCard.h"

CharacterCard::CharacterCard(const char * path, int x, int y, int w, int h, const char * race,
                             const char * characterClass, const char * name) : Tile(path, x, y, w, h),
                                                                               _race(TTF_OpenFont(FONT_PATH, 25), 0, 0,
                                                                                     0, race, x + 20, y + 20),
                                                                               _class(TTF_OpenFont(FONT_PATH, 25), 0, 0,
                                                                                      0, characterClass, x + 20, y + 60),
                                                                               _name(TTF_OpenFont(FONT_PATH, 25), 0, 0,
                                                                                     0, name, x + 20, y + 90)
{}

void CharacterCard::init()
{
    Tile::init();
}

void CharacterCard::render()
{
    Tile::render();
    _race.render();
    _class.render();
    _name.render();
}

void CharacterCard::cleanup()
{
    Tile::cleanup();
    _name.cleanup();
    _class.cleanup();
    _race.cleanup();
}


