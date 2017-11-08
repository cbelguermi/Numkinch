//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_RACE_H
#define NUMKINCH_RACE_H

#include "Skill.h"
#include "Class.h"

class Race {

protected:
    const int _race;

    Skill _attack;

    Skill _defense;

    Skill _agility;

    Skill _life;

    Class * _class;

public:
    Race(int race, Class * characterClass);

    int getRace() const;

    int getClass() const;

    const Skill & getAttack() const;

    const Skill & getDefense() const;

    const Skill & getAgility() const;

    const Skill & getLife() const;

    virtual ~Race();
};


#endif //NUMKINCH_RACE_H
