//
// Created by Chloé Belguermi on 20/11/2017.
//

#include "Priest.h"
#include "PlayerLogicConstants.h"
#include "Classes.h"

Priest::Priest() : Class(priest)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE + START_BONUS);
}
