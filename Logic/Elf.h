//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_CHARACTER_H
#define NUMKINCH_CHARACTER_H


#include "Race.h"

class Elf : public Race {

public:
    Elf();

    explicit Elf(Class & characterClass);

};


#endif //NUMKINCH_CHARACTER_H
