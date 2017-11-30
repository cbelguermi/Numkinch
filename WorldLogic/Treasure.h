//
// Created on 19/11/2017.
//

#ifndef NUMKINCH_TREASURE_H
#define NUMKINCH_TREASURE_H

#include "Room.h"

class Treasure : public Room {

private:
    const unsigned int _bonus;

public:
    Treasure(int type, const char * name, const char * description, const char * entityImage, unsigned int targetSkill,
             unsigned int bonus);

    unsigned int getBonus() const;

private:
    const char * getBonusString();
};

#endif //NUMKINCH_TREASURE_H
