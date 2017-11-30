//
// Created on 21/11/2017.
//

#include "StatCard.h"

StatCard::StatCard(const char * path, int x, int y, int w, int h, const char * playerIdentity, const char * attack,
                   const char * defense, const char * agility, const char * life) :
        Tile(path, x, y, w, h),
        _playerIdentity(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, playerIdentity, x + 20, y + 10),
        _attack(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, attack, x + 20, y + 30),
        _defense(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, defense, x + 20, y + 50),
        _agility(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, agility, x + 20, y + 70),
        _life(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, life, x + 20, y + 90)
{}

void StatCard::init()
{
    Tile::init();
}

void StatCard::update(const char * attack, const char * defense, const char * agility, const char * life)
{
    _attack.update(attack);
    _defense.update(defense);
    _agility.update(agility);
    _life.update(life);
}

void StatCard::render()
{
    Tile::render();
    _playerIdentity.render();
    _attack.render();
    _defense.render();
    _agility.render();
    _life.render();
}

void StatCard::cleanup()
{
    Tile::cleanup();
    _playerIdentity.cleanup();
    _attack.cleanup();
    _defense.cleanup();
    _agility.cleanup();
    _life.cleanup();
}