//
// Created on 20/11/2017.
//

#include "Barbarian.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Barbarian::Barbarian(const char * name, Class * characterClass) : Race(barbarian, name, characterClass)
{
    _attack = Skill(ATTACK_VALUE+ATTACK_BONUS, ATTACK_MAX_VALUE+ATTACK_MAX_BONUS);
    _defense = Skill(DEFENSE_VALUE, DEFENSE_MAX_VALUE);
    _agility = Skill(AGILITY_VALUE, AGILITY_MAX_VALUE);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}
