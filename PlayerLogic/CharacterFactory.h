//
// Created on 03/11/2017.
//

#ifndef NUMKINCH_CHARACTERFACTORY_H
#define NUMKINCH_CHARACTERFACTORY_H

#include "Race.h"

class CharacterFactory {

private:
    CharacterFactory() = default; // avoid instancing

    static CharacterFactory _characterFactory;

public:
    static CharacterFactory & get();

    CharacterFactory(const CharacterFactory &) = delete; // avoid copy

    CharacterFactory & operator=(const CharacterFactory &) = delete; // avoid copy

    Race * createCharacter();

    const char * NameToString(int name) const;

};


#endif //NUMKINCH_CHARACTERFACTORY_H
