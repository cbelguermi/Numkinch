//
// Created on 03/11/2017.
//

#include "Elf.h"
#include "Races.h"
#include "PlayerLogicConstants.h"

Elf::Elf(const char * name, Class * characterClass) : Race(elf, name, characterClass)
{
    _attack = Skill(ATTACK_VALUE, ATTACK_MAX_VALUE);
    _defense = Skill(DEFENSE_VALUE, DEFENSE_MAX_VALUE);
    _agility = Skill(AGILITY_VALUE+ AGILITY_BONUS, AGILITY_MAX_VALUE+AGILITY_MAX_BONUS);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}