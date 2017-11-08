//
// Created by Chloé Belguermi on 03/11/2017.
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

    int randRace, randClass;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformRaceDistribution(elf, dwarf);
    uniform_int_distribution<int> uniformClassDistribution(assassin, paladin);

    randRace = uniformRaceDistribution(randomEngine);
    randClass = uniformClassDistribution(randomEngine);

    switch (randRace) {
        case elf: {
            switch (randClass) {
                case assassin:
                    return new Elf(new Assassin());
                case paladin:
                    return new Elf(new Paladin());
                default:
                    return new Elf(new Assassin());
            }
        }
        case dwarf: {
            switch (randClass) {
                case assassin:
                    return new Dwarf(new Assassin());
                case paladin:
                    return new Dwarf(new Paladin());
                default:
                    return new Dwarf(new Assassin());
            }
        }
        default: {
            return new Dwarf(new Assassin());
        }
    }
}
