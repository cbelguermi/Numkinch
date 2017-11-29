//
// Created by Chloé Belguermi on 19/11/2017.
//

#ifndef NUMKINCH_MONSTER_H
#define NUMKINCH_MONSTER_H


#include "Room.h"
#include "../PlayerLogic/Skill.h"

class Monster : public Room {

private:
    bool _isBoss;

    unsigned int _attack;

    unsigned int _defense;

    unsigned int _life;

public:
    Monster(int type, bool isBoss, const char * name, const char * description, const char * entityImage,
            unsigned int attack, unsigned int defense, unsigned int life);

    bool isBoss() const;

    unsigned int getAttack() const;

    unsigned int getDefense() const;

    unsigned int getLife() const;

private:
    const char * getSkillsString();
};


#endif //NUMKINCH_MONSTER_H
