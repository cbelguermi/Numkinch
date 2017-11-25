//
// Created by Chloé Belguermi on 21/11/2017.
//

#ifndef NUMKINCH_STATCARD_H
#define NUMKINCH_STATCARD_H

#include "Tile.h"
#include "Text.h"

class StatCard : public Tile {

private:
    Text _playerNb;

    Text _attack;

    Text _defense;

    Text _agility;

    Text _life;

public:
    StatCard(const char * path, int x, int y, int w, int h, const char * playerNb, const char * attack,
             const char * defense, const char * agility, const char * life);

    void init() override;

    void render() override;

    void cleanup() override;
};

#endif //NUMKINCH_STATCARD_H
