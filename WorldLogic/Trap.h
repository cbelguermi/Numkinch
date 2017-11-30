//
// Created on 19/11/2017.
//

#ifndef NUMKINCH_TRAP_H
#define NUMKINCH_TRAP_H


#include "Room.h"

class Trap : public Room {

private:
    const unsigned int _damage;

public:
    Trap(int type, const char * name, const char * description, const char * entityImage, unsigned int targetSkill,
         unsigned int damage);

    unsigned int getDamage() const;

private:
    const char * getDamageString();
};

#endif //NUMKINCH_TRAP_H
