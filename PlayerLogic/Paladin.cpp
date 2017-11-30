//
// Created on 03/11/2017.
//

#include "Paladin.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Paladin::Paladin() : Class(paladin)
{
    _attack = Skill(ATTACK_VALUE, ATTACK_MAX_VALUE);
    _defense = Skill(DEFENSE_VALUE+DEFENSE_BONUS, DEFENSE_MAX_VALUE+DEFENSE_MAX_BONUS);
    _agility = Skill(AGILITY_VALUE, AGILITY_MAX_VALUE);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}