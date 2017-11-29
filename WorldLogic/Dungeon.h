//
// Created by Chloé Belguermi on 11/11/2017.
//

#ifndef NUMKINCH_DUNGEON_H
#define NUMKINCH_DUNGEON_H

#include <vector>
#include <memory>
#include "../GUI/Button.h"
#include "../GUI/Background.h"
#include "Room.h"
#include "Card.h"

using namespace std;

class Dungeon : public IHandleable, IDisplayable {

private:
    vector<unique_ptr<Card>> _playedDeck; // cards that are actually shown on board

    vector<unique_ptr<Room>> _allRooms; // all the cards

    bool _activated;

    Card * _lastVisitedCard;

public:

    Dungeon();

    void generate();

    void init() override;

    void handleEvent(SDL_Event * event) override;

    void update();

    void render() override;

    void cleanup() override;

private:
    Card * findCard(int positionX, int positionY);
};

#endif //NUMKINCH_DUNGEON_H