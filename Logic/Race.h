//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_RACE_H
#define NUMKINCH_RACE_H


#include "SkillSet.h"
#include "Class.h"

class Race {

private:
    SkillSet _innateSkills;
    Class _class;

public:
    Race();

    void setCharacterClass(Class & characterClass);

};


#endif //NUMKINCH_RACE_H
