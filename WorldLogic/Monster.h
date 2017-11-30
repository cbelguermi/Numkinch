//
// Created on 19/11/2017.
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

    int _life;

public:
    Monster(int type, bool isBoss, const char * name, const char * description, const char* imagePath,
            unsigned int attack, unsigned int defense, int life);

    bool isBoss() const;

    unsigned int getAttack() const;

    unsigned int getDefense() const;

    int getLife() const;

    void alterLife(int value);

private:
    const char * getSkillsString();
};


#endif //NUMKINCH_MONSTER_H
