//
// Created by Chloé Belguermi on 11/11/2017.
//

#ifndef NUMKINCH_DUNGEON_H
#define NUMKINCH_DUNGEON_H

#include <vector>
#include "../GUI/Button.h"
#include "../GUI/Background.h"
#include "../GUI/TileGroup.h"
#include "Room.h"
#include "Card.h"

using namespace std;

class Dungeon : public IHandleable {

private:
    Background _dungeonBg;
    vector<unique_ptr<Card>> _playedDeck; // cards that are actually shown on board
    vector<unique_ptr<Room>> _allRooms; // all the cards

    bool _activated;

    Card * _lastVisitedCard;

public:

    Dungeon();

    void generate();

    void handleEvent(SDL_Event * event) override;

    void render();

    void cleanup();

private:
    Card * findCard(int positionX, int positionY);


};


#endif //NUMKINCH_DUNGEON_H