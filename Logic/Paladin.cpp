//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Paladin.h"
#include "Classes.h"
#include "LogicConstants.h"

Paladin::Paladin() : Class(paladin)
{
    _attack = Skill(BASE_VALUE + START_BONUS);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE);
}