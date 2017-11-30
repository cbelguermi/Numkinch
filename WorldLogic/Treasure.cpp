//
// Created on 19/11/2017.
//

#include "Treasure.h"
#include "../PlayerLogic/Skills.h"

Treasure::Treasure(int type, const char * name, const char * description,const char* imagePath,
                   unsigned int targetSkill, unsigned int bonus) :
        Room(type, name, description), _bonus(bonus)
{
    _targetSkill = targetSkill;
    _bigCard = new BigCard(false, TAKE_BTN_PATH, imagePath, getBonusString(), name, description);
}

unsigned int Treasure::getBonus() const
{
    return _bonus;
}

const char * Treasure::getBonusString()
{
    auto * bonus = new char(50);
    switch (_targetSkill)
    {
        case (ATTACK):
            sprintf(bonus, "BONUS : ATTACK +%d", _bonus);
            break;
        case (DEFENSE):
            sprintf(bonus, "BONUS : DEFENSE +%d", _bonus);
            break;
        case (AGILITY):
            sprintf(bonus, "BONUS : AGILITY +%d", _bonus);
            break;
        case (LIFE):
            sprintf(bonus, "BONUS : LIFE +%d", _bonus);
            break;
        default:
            delete bonus;
            bonus = nullptr;
            break;
    }
    return bonus;
}