//
// Created on 03/11/2017.
//

#include "Assassin.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Assassin::Assassin() : Class(assassin)
{
    _attack = Skill(ATTACK_VALUE+ATTACK_BONUS, ATTACK_MAX_VALUE+ATTACK_MAX_BONUS);
    _defense = Skill(DEFENSE_VALUE, DEFENSE_MAX_VALUE);
    _agility = Skill(AGILITY_VALUE, AGILITY_MAX_VALUE);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}