//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Elf.h"
#include "Races.h"
#include "PlayerLogicConstants.h"

Elf::Elf(const char * name, Class * characterClass) : Race(elf, name, characterClass)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE + START_BONUS);
    _life = Skill(BASE_VALUE);
}