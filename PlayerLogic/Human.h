//
// Created by Chloé Belguermi on 20/11/2017.
//

#ifndef NUMKINCH_HUMAN_H
#define NUMKINCH_HUMAN_H


#include "Race.h"

class Human : public Race
{
public:
    explicit Human(const char * name, Class * characterClass);
};


#endif //NUMKINCH_HUMAN_H
