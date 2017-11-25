//
// Created by Chloé Belguermi on 11/11/2017.
//

#include "Room.h"
#include "../GUI/GUIConstants.h"
#include "Entities.h"

Room::Room(int type, const char * name, const char * description, const char * entityImage) :
        _type(type), _name(name), _description(description), _visited(false), _entityImage(entityImage)
{
    _bigCard = nullptr;
}

bool Room::visited() const
{
    return _visited;
}

void Room::setVisited(bool visited)
{
    _visited = visited;
}

BigCard * Room::getBigCard()
{
    return _bigCard;
}


Room::~Room()
{
    _name = nullptr;
    _description = nullptr;
    _entityImage = nullptr;
    delete _bigCard;
    _bigCard = nullptr;
}