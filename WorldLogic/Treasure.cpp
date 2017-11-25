//
// Created by Chloé Belguermi on 19/11/2017.
//

#include "Treasure.h"
#include "../PlayerLogic/Skills.h"

Treasure::Treasure(int type, const char * name, const char * description, const char * entityImage,
                   unsigned int targetSkill, unsigned int bonus) :
        Room(type, name, description, entityImage), _targetSkill(targetSkill), _bonus(bonus)
{
    _bigCard = new BigCard(true, TAKE_BTN_PATH, ENTITY_PATH, getBonusString(), name, description);
}

const char * Treasure::getBonusString()
{
    auto * bonus = new char(16);
    switch (_targetSkill)
    {
        case (ATTACK):
            sprintf(bonus, "+ %d - ATTACK", _bonus);
        case (DEFENSE):
            sprintf(bonus, "+ %d - DEFENSE", _bonus);
        case (AGILITY):
            sprintf(bonus, "+ %d - AGILITY", _bonus);
        case (LIFE):
            sprintf(bonus, "+ %d - LIFE", _bonus);
        default:
            delete bonus;
            bonus = nullptr;
    }
    return bonus;
}
