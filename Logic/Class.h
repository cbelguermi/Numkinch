//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_CLASS_H
#define NUMKINCH_CLASS_H

#include "Skill.h"

class Class {

protected:
    const int _class;

    Skill _attack;

    Skill _defense;

    Skill _agility;

    Skill _life;

public:
    explicit Class(int characterClass);

    int getClass() const;
};


#endif //NUMKINCH_CLASS_H
