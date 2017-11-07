//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_SKILLSET_H
#define NUMKINCH_SKILLSET_H


#include "Skill.h"

class SkillSet {

private:
    enum Primitives { attack, defense, agility };
    Skill _attack;
    Skill _defense;
    Skill _agility;

public:

    void setSkillValue(int val, int skill);

    void setSkillMaxValue(int maxVal, int skill);

    int getSkillValue(int skill) const;

    int getSkillMaxValue(int skill) const;

    void alterSkillPoints(int val, int skill);

    void alterSkillMaxPoints(int maxVal, int skill);

};


#endif //NUMKINCH_SKILLSET_H
