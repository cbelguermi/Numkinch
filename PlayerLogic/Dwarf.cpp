//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Dwarf.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Dwarf::Dwarf(const char * name, Class * characterClass) : Race(dwarf, name, characterClass)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE + START_BONUS);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE);
}