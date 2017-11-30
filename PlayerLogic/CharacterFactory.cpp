//
// Created on 03/11/2017.
//

#include <cstdlib>
#include <random>
#include "CharacterFactory.h"
#include "Races.h"
#include "Classes.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Assassin.h"
#include "Paladin.h"
#include "Thief.h"
#include "Priest.h"
#include "Barbarian.h"
#include "Human.h"
#include "Names.h"

using namespace std;

// Static declarations
CharacterFactory CharacterFactory::_characterFactory;

/* ========== Singleton ========== */

CharacterFactory & CharacterFactory::get()
{
    return _characterFactory;
}
/* =============================== */

/**
 * Randomly chooses a (race, class) combination and creates the character.
 *
 * @return pointer to a specific child of Race, with the Race type.
 */
Race * CharacterFactory::createCharacter() {

    int randRace, randClass, randName;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformRaceDistribution(elf, human); // between 0 and 3 included
    uniform_int_distribution<int> uniformClassDistribution(assassin, priest); // between 0 and 3 included
    uniform_int_distribution<int> uniformNameDistribution(dismin, iviel); // between 0 and 4 included

    randRace = uniformRaceDistribution(randomEngine);
    randClass = uniformClassDistribution(randomEngine);
    randName = uniformNameDistribution(randomEngine);

    switch (randRace) {
        case elf: {
            switch (randClass) {
                case assassin:
                    return new Elf(NameToString(randName), new Assassin());
                case paladin:
                    return new Elf(NameToString(randName), new Paladin());
                case thief:
                    return new Elf(NameToString(randName), new Thief());
                case priest:
                    return new Elf(NameToString(randName), new Priest());
                default:
                    return new Elf(NameToString(randName), new Assassin());
            }
        }
        case dwarf: {
            switch (randClass) {
                case assassin:
                    return new Dwarf(NameToString(randName), new Assassin());
                case paladin:
                    return new Dwarf(NameToString(randName), new Paladin());
                case thief:
                    return new Dwarf(NameToString(randName), new Thief());
                case priest:
                    return new Dwarf(NameToString(randName), new Priest());
                default:
                    return new Dwarf(NameToString(randName), new Assassin());
            }
        }
        case barbarian: {
            switch (randClass) {
                case assassin:
                    return new Barbarian(NameToString(randName), new Assassin());
                case paladin:
                    return new Barbarian(NameToString(randName), new Paladin());
                case thief:
                    return new Barbarian(NameToString(randName), new Thief());
                case priest:
                    return new Barbarian(NameToString(randName), new Priest());
                default:
                    return new Barbarian(NameToString(randName), new Assassin());
            }
        }
        case human: {
            switch (randClass) {
                case assassin:
                    return new Human(NameToString(randName), new Assassin());
                case paladin:
                    return new Human(NameToString(randName), new Paladin());
                case thief:
                    return new Human(NameToString(randName), new Thief());
                case priest:
                    return new Human(NameToString(randName), new Priest());
                default:
                    return new Human(NameToString(randName), new Assassin());
            }
        }
        default: {
            return new Dwarf(NameToString(randName), new Assassin());
        }
    }
}


Race * CharacterFactory::createCharacter(int race, int classname, const char* name)
{
    switch (race) {
        case elf: {
            switch (classname) {
                case assassin:
                    return new Elf(name, new Assassin());
                case paladin:
                    return new Elf(name, new Paladin());
                case thief:
                    return new Elf(name, new Thief());
                case priest:
                    return new Elf(name, new Priest());
                default:
                    return new Elf(name, new Assassin());
            }
        }
        case dwarf: {
            switch (classname) {
                case assassin:
                    return new Dwarf(name, new Assassin());
                case paladin:
                    return new Dwarf(name, new Paladin());
                case thief:
                    return new Dwarf(name, new Thief());
                case priest:
                    return new Dwarf(name, new Priest());
                default:
                    return new Dwarf(name, new Assassin());
            }
        }
        case barbarian: {
            switch (classname) {
                case assassin:
                    return new Barbarian(name, new Assassin());
                case paladin:
                    return new Barbarian(name, new Paladin());
                case thief:
                    return new Barbarian(name, new Thief());
                case priest:
                    return new Barbarian(name, new Priest());
                default:
                    return new Barbarian(name, new Assassin());
            }
        }
        case human: {
            switch (classname) {
                case assassin:
                    return new Human(name, new Assassin());
                case paladin:
                    return new Human(name, new Paladin());
                case thief:
                    return new Human(name, new Thief());
                case priest:
                    return new Human(name, new Priest());
                default:
                    return new Human(name, new Assassin());
            }
        }
        default: {
            return new Dwarf(name, new Assassin());
        }
    }
}

const char * CharacterFactory::NameToString(int name) const
{
    switch (name) {
        case dismin:
            return "Dismin";
        case eyl:
            return "Eyl";
        case gardy:
            return "Gardy";
        case iviel:
            return "Iviel";
        default:
            return "Blank";
    }
}
