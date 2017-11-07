//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Race.h"

class Class;

Race::Race() {

}

Race::Race(Class & characterClass) : _class(characterClass) {

}

void Race::setCharacterClass(Class & characterClass) {

    _class = characterClass;

}