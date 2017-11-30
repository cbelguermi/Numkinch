//
// Created on 20/11/2017.
//

#include "Thief.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Thief::Thief() : Class(thief)
{
    _attack = Skill(ATTACK_VALUE, ATTACK_MAX_VALUE);
    _defense = Skill(DEFENSE_VALUE, DEFENSE_MAX_VALUE);
    _agility = Skill(AGILITY_VALUE+ AGILITY_BONUS, AGILITY_MAX_VALUE+AGILITY_MAX_BONUS);
    _life = Skill(LIFE_VALUE, LIFE_MAX_VALUE);
}
