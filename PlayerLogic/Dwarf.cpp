//
// Created on 03/11/2017.
//

#include "Dwarf.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Dwarf::Dwarf(const char * name, Class * characterClass) : Race(dwarf, name, characterClass)
{
    _attack = Skill(ATTACK_VALUE, ATTACK_MAX_VALUE);
    _defense = Skill(DEFENSE_VALUE+DEFENSE_BONUS, DEFENSE_MAX_VALUE+DEFENSE_MAX_BONUS);
    _agility = Skill(AGILITY_VALUE, AGILITY_MAX_VALUE);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}