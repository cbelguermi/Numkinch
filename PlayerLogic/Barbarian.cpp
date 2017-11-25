//
// Created by Chloé Belguermi on 20/11/2017.
//

#include "Barbarian.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Barbarian::Barbarian(const char * name, Class * characterClass) : Race(barbarian, name, characterClass)
{
    _attack = Skill(BASE_VALUE + START_BONUS);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE);
}
