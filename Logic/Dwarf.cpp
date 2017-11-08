//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Dwarf.h"
#include "LogicConstants.h"
#include "Races.h"

Dwarf::Dwarf(Class * characterClass) : Race(dwarf, characterClass)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE + START_BONUS);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE);
}