//
// Created by Chloé Belguermi on 20/11/2017.
//

#include "Human.h"
#include "Races.h"
#include "PlayerLogicConstants.h"

Human::Human(const char * name, Class * characterClass) : Race(human, name, characterClass)
{
    _attack = Skill(BASE_VALUE);
    _defense = Skill(BASE_VALUE);
    _agility = Skill(BASE_VALUE);
    _life = Skill(BASE_VALUE + START_BONUS);
}
