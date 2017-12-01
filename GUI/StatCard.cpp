//
// Created on 21/11/2017.
//

#include "StatCard.h"

StatCard::StatCard(const char * path, int x, int y, int w, int h, string playerIdentity, string attack,
                   string defense, string agility, string life) :
        Tile(path, x, y, w, h),
        _playerIdentity(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, playerIdentity.c_str(), x + 20, y + 10),
        _attack(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, attack.c_str(), x + 20, y + 30),
        _defense(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, defense.c_str(), x + 20, y + 50),
        _agility(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, agility.c_str(), x + 20, y + 70),
        _life(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, life.c_str(), x + 20, y + 90)
{}

void StatCard::init()
{
    Tile::init();
}

void StatCard::update(string attack, string defense, string agility, string life)
{
    _attack.update(move(attack));
    _defense.update(move(defense));
    _agility.update(move(agility));
    _life.update(move(life));
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

void StatCard::setTile(const char * path)
{
    Tile::cleanup();
    Tile::setImagePath(path);
    Tile::init();
    Tile::render();
}