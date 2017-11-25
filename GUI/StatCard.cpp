//
// Created by Chloé Belguermi on 21/11/2017.
//

#include "StatCard.h"

StatCard::StatCard(const char * path, int x, int y, int w, int h, const char * playerNb, const char * attack,
                   const char * defense, const char * agility, const char * life) :
        Tile(path, x, y, w, h),
        _playerNb(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, playerNb, x + 20, y + 10),
        _attack(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, attack, x + 20, y + 30),
        _defense(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, defense, x + 20, y + 50),
        _agility(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, agility, x + 20, y + 70),
        _life(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, life, x + 20, y + 90)
{}

void StatCard::render()
{
    Tile::render();
    _playerNb.render();
    _attack.render();
    _defense.render();
    _agility.render();
    _life.render();
}

void StatCard::cleanup()
{
    Tile::cleanup();
    _playerNb.cleanup();
    _attack.cleanup();
    _defense.cleanup();
    _agility.cleanup();
    _life.cleanup();
}
