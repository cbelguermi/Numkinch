//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "CharacterFactory.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Assassin.h"
#include "Paladin.h"
#include <cstdlib>
#include <random>

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

    Race * newChar = nullptr;
    switch (randRace) {
        case elf: {
            newChar = new Elf();
        }
        case dwarf: {
            newChar = new Dwarf();
        }
        default: {
            newChar = new Dwarf();
        }
    }

    switch (randClass) {
        case assassin: {
            Assassin tempAssassin;
            Class &newAssassin = tempAssassin;
            newChar->setCharacterClass(newAssassin);
        }
        case paladin: {
            Paladin tempPaladin;
            Class &newPaladin = tempPaladin;
            newChar->setCharacterClass(newPaladin);
        }
        default: {
            Paladin defaultPaladin;
            Class &newDefPaladin = defaultPaladin;
            newChar->setCharacterClass(newDefPaladin);
        }
    }

    return newChar;
}
