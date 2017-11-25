//
// Created by Chloé Belguermi on 19/11/2017.
//

#include "Trap.h"
#include "../PlayerLogic/Skills.h"

Trap::Trap(int type, const char * name, const char * description, const char * entityImage,
           const unsigned int targetSkill, const unsigned int damage) :
        Room(type, name, description, entityImage), _targetSkill(targetSkill), _damage(damage)
{
    _bigCard = new BigCard(true, TAKE_BTN_PATH, ENTITY_PATH, getDamageString(), name, description);
}

const char * Trap::getDamageString()
{
    auto * damage = new char(16);
    switch (_targetSkill)
    {
        case (ATTACK):
            sprintf(damage, "- %d - ATTACK", _damage);
        case (DEFENSE):
            sprintf(damage, "- %d - DEFENSE", _damage);
        case (AGILITY):
            sprintf(damage, "- %d - AGILITY", _damage);
        case (LIFE):
            sprintf(damage, "- %d - LIFE", _damage);
        default:
            delete damage;
            damage = nullptr;
    }
    return damage;
}
