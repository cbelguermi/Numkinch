//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Race.h"

class Class;

Race::Race(int race, Class * characterClass) : _race(race)
{
    _class = characterClass;
}

int Race::getRace() const
{
    return _race;
}

int Race::getClass() const
{
    return _class->getClass();
}

const Skill & Race::getAttack() const
{
    return _attack;
}

const Skill & Race::getDefense() const
{
    return _defense;
}

const Skill & Race::getAgility() const
{
    return _agility;
}

const Skill & Race::getLife() const
{
    return _life;
}

Race::~Race() = default;