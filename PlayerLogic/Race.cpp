//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Race.h"
#include "Races.h"
#include "Classes.h"

class Class;

Race::Race(int race, const char * name, Class * characterClass) : _race(race), _name(name)
{
    _class = characterClass;

    _attack.setMaxValue(_attack.getMaxValue() + _class->getAttack().getMaxValue());
    _attack.setValue(_attack.getValue() + _class->getAttack().getValue());

    _defense.setMaxValue(_defense.getMaxValue() + _class->getAttack().getMaxValue());
    _defense.setValue(_defense.getValue() + _class->getAttack().getValue());

    _agility.setMaxValue(_agility.getMaxValue() + _class->getAttack().getMaxValue());
    _agility.setValue(_agility.getValue() + _class->getAttack().getValue());

    _life.setMaxValue(_life.getMaxValue() + _class->getAttack().getMaxValue());
    _life.setValue(_life.getValue() + _class->getAttack().getValue());
}

int Race::getRace() const
{
    return _race;
}

int Race::getClass() const
{
    return _class->getClass();
}

const char * Race::getName() const
{
    return _name;
}

Skill * Race::getAttack() const
{
    return & _attack;
}

Skill * Race::getDefense() const
{
    return & _defense;
}

Skill * Race::getAgility() const
{
    return & _agility;
}

Skill * Race::getLife() const
{
    return & _life;
}

const char * Race::RaceToString() const
{
    switch (_race)
    {
        case barbarian:
            return "Barbarian";
        case dwarf:
            return "Dwarf";
        case elf:
            return "Elf";
        case human:
            return "Human";
        default:
            return "UFO";
    }
}

const char * Race::ClassToString() const
{
    switch (_class->getClass())
    {
        case assassin:
            return "Assassin";
        case paladin:
            return "Paladin";
        case priest:
            return "Priest";
        case thief:
            return "Thief";
        default:
            return "UFO";
    }
}

Race::~Race() = default;