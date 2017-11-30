//
// Created on 20/11/2017.
//

#include "Priest.h"
#include "PlayerLogicConstants.h"
#include "Classes.h"

Priest::Priest() : Class(priest)
{
    _attack = Skill(ATTACK_VALUE, ATTACK_MAX_VALUE);
    _defense = Skill(DEFENSE_VALUE, DEFENSE_MAX_VALUE);
    _agility = Skill(AGILITY_VALUE, AGILITY_MAX_VALUE);
    _life = Skill(LIFE_VALUE+LIFE_BONUS, LIFE_MAX_VALUE+LIFE_MAX_BONUS);
}
