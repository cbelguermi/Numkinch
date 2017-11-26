//
// Created by Chloé Belguermi on 11/11/2017.
//

#ifndef NUMKINCH_ROOM_H
#define NUMKINCH_ROOM_H

#include "../GUI/Button.h"
#include "../GUI/CharacterCard.h"
#include "BigCard.h"

#define ENTITY_PATH "./res/genericEntity.png"
#define TAKE_BTN_PATH "./res/TakeBtn.png"

class Room {

protected:
    int _type;

    bool _visited;

    bool _inDeck;

    const char * _name;

    const char * _description;

    const char * _entityImage;

    BigCard * _bigCard;


public:
    Room(int type, const char * name, const char * description, const char * entityImage);

    int getType() const;

    bool inDeck() const;

    bool visited() const;

    void setVisited(bool visited);

    BigCard * getBigCard();

    virtual ~Room();

    void setInDeck(bool inDeck);
};


#endif //NUMKINCH_ROOM_H
