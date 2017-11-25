//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Assassin.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Assassin::Assassin() : Class(assassin)
{
    _attack = Skill(BASE_VALUE + START_BONUS);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE);
}