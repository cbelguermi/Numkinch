//
// Created by Chloé Belguermi on 21/11/2017.
//

#ifndef NUMKINCH_CARD_H
#define NUMKINCH_CARD_H

#include "Room.h"
#include "BigCard.h"

class Card : public IHandleable {

private:
    Room * _room; // don't delete it since it comes from a unique_ptr

    Button _backCardBtn;

    Tile _frontCardTile;

    int _positionX;

    int _positionY;

public:
    Card(Room * room, int column, int line);

    Room * getRoom();

    int getX() const;

    int getY() const;

    void handleEvent(SDL_Event * event) override;

    void render();

    void cleanup();

    ~Card();
};


#endif //NUMKINCH_CARD_H
