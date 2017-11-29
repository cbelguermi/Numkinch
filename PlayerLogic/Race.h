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

    const char * _name;

    Skill _attack;

    Skill _defense;

    Skill _agility;

    Skill _life;

    Class * _class;

public:
    Race(int race, const char * name, Class * characterClass);

    int getRace() const;

    int getClass() const;

    const char * getName() const;

    Skill * getAttack() const;

    Skill * getDefense() const;

    Skill * getAgility() const;

    Skill * getLife() const;

    const char * RaceToString() const;

    const char * ClassToString() const;

    virtual ~Race();
};


#endif //NUMKINCH_RACE_H
