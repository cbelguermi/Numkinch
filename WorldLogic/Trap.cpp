//
// Created on 19/11/2017.
//

#include "Trap.h"
#include "../PlayerLogic/Skills.h"

Trap::Trap(int type, const char * name, const char * description, const char * entityImage,
           const unsigned int targetSkill, const unsigned int damage) :
        Room(type, name, description, entityImage), _damage(damage)
{
    _targetSkill = targetSkill;
    _bigCard = new BigCard(false, TAKE_BTN_PATH, ENTITY_PATH, getDamageString(), name, description);
}

unsigned int Trap::getDamage() const
{
    return _damage;
}

const char * Trap::getDamageString()
{
    auto * damage = new char(50);
    switch (_targetSkill)
    {
        case (ATTACK):
            sprintf(damage, "MALUS : ATTACK -%d", _damage);
            break;
        case (DEFENSE):
            sprintf(damage, "MALUS : DEFENSE -%d", _damage);
            break;
        case (AGILITY):
            sprintf(damage, "MALUS : AGILITY -%d", _damage);
            break;
        case (LIFE):
            sprintf(damage, "MALUS : LIFE -%d", _damage);
            break;
        default:
            delete damage;
            damage = nullptr;
            break;
    }
    return damage;
}
