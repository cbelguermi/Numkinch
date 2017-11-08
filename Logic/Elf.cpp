//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Elf.h"
#include "Races.h"
#include "LogicConstants.h"

Elf::Elf(Class * characterClass) : Race(elf, characterClass)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE + START_BONUS);
    _life = Skill(BASE_VALUE);
}