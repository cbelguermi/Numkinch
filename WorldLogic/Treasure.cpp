//
// Created on 19/11/2017.
//

#include "Treasure.h"
#include "../PlayerLogic/Skills.h"

Treasure::Treasure(int type, const char * name, const char * description, const char * entityImage,
                   unsigned int targetSkill, unsigned int bonus) :
        Room(type, name, description, entityImage), _bonus(bonus)
{
    _targetSkill = targetSkill;
    _bigCard = new BigCard(false, TAKE_BTN_PATH, ENTITY_PATH, getBonusString(), name, description);
}

unsigned int Treasure::getBonus() const
{
    return _bonus;
}

const char * Treasure::getBonusString()
{
    auto * bonus = new char(16);
    switch (_targetSkill)
    {
        case (ATTACK):
            sprintf(bonus, "+ %d - ATTACK", _bonus);
            break;
        case (DEFENSE):
            sprintf(bonus, "+ %d - DEFENSE", _bonus);
            break;
        case (AGILITY):
            sprintf(bonus, "+ %d - AGILITY", _bonus);
            break;
        case (LIFE):
            sprintf(bonus, "+ %d - LIFE", _bonus);
            break;
        default:
            delete bonus;
            bonus = nullptr;
            break;
    }
    return bonus;
}