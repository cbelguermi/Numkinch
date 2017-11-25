//
// Created by Chloé Belguermi on 20/11/2017.
//

#include "Thief.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Thief::Thief() : Class(thief)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE + START_BONUS);
    _life = Skill(BASE_VALUE);
}
