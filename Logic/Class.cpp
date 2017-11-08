//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Class.h"

Class::Class(int characterClass) : _class(characterClass)
{}

int Class::getClass() const
{
    return _class;
}