//
// Created on 21/11/2017.
//

#ifndef NUMKINCH_STATCARD_H
#define NUMKINCH_STATCARD_H

#include "Tile.h"
#include "Text.h"

class StatCard : public Tile {

private:
    Text _playerIdentity;

    Text _attack;

    Text _defense;

    Text _agility;

    Text _life;

public:
    StatCard(const char * path, int x, int y, int w, int h, const char * playerIdentity, const char * attack,
             const char * defense, const char * agility, const char * life);

    void init() override;

    void update(const char * attack, const char * defense, const char * agility, const char * life);

    void render() override;

    void cleanup() override;

    void setTile(const char* path);
};

#endif //NUMKINCH_STATCARD_H
