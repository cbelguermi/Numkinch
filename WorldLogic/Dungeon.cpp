//
// Created on 11/11/2017.
//

#include <random>
#include "Dungeon.h"
#include "Entities.h"
#include "Monster.h"
#include "Trap.h"
#include "../PlayerLogic/Skills.h"
#include "Treasure.h"
#include "../GUI/GUIConstants.h"
#include "../Core/GameStateManager.h"
#include "../Core/PlayState.h"

#define CARDS_PER_LINE 6

Dungeon::Dungeon()
{
    _playedDeck.reserve(NB_CARDS_INGAME);
    _allRooms.reserve(NB_CARDS);
    _activated = true;
    _lastVisitedCard = nullptr;
    _returnedCardsCount = 0;

    int i;
    for (i = 0; i < 30; i++)
    {
        _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "Gros monstre pas beau",
                                                         "Tu vas prendre cher sale petit nomnom", 20, 5, 20)));
    }
    for (i = 30; i < 60; i++)
    {
        _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "Un piege machiavelique",
                                                      "Ouille !! Il te pique les fesses", LIFE, 3)));
    }
    for (i = 60; i < 90; i++)
    {
        _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "Super epee maginifique",
                                                          "Tu vas pouvoir tous les defoncer ces sales petits chin... euh, monstres, oui c'est cela, ces sales petits monstres !",
                                                          ATTACK, 2)));
    }
    for (i = 90; i < 100; i++)
    {
        _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS du donjon",
                                                         "Dragon de glace crachant du feu", 60, 5, 80)));
    }
}

void Dungeon::generate()
{
    int randPosition;
    int nbInGameCards = NB_CARDS_INGAME;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformPositionDistribution(0, DISTANCE);

    while (nbInGameCards > 0)
    {
        randPosition = uniformPositionDistribution(randomEngine);

        while (nbInGameCards > 0 && randPosition < NB_CARDS && !_allRooms[randPosition]->inDeck())
        {
            _allRooms[randPosition]->setInDeck(true);
            _playedDeck.push_back(unique_ptr<Card>(new Card(_allRooms[randPosition].get(),
                                                            (NB_CARDS_INGAME - nbInGameCards) % CARDS_PER_LINE,
                                                            (NB_CARDS_INGAME - nbInGameCards) / CARDS_PER_LINE)));
            randPosition += DISTANCE;
            nbInGameCards --;
        }
    }
}

void Dungeon::regenerate()
{
    int randPosition;
    int nbInGameCards = NB_CARDS_INGAME;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformPositionDistribution(0, DISTANCE);

    while (nbInGameCards > 0)
    {
        randPosition = uniformPositionDistribution(randomEngine);

        while (nbInGameCards > 0 && randPosition < NB_CARDS && !_allRooms[randPosition]->inDeck())
        {
            _allRooms[randPosition]->setInDeck(true);

            _playedDeck[NB_CARDS_INGAME - nbInGameCards].reset(new Card(_allRooms[randPosition].get(),
                                                                        (NB_CARDS_INGAME - nbInGameCards) % CARDS_PER_LINE,
                                                                        (NB_CARDS_INGAME - nbInGameCards) / CARDS_PER_LINE));

            randPosition += DISTANCE;
            nbInGameCards --;
        }
    }
}

void Dungeon::init()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->init();
    }
}

void Dungeon::handleEvent(SDL_Event * event)
{
    if (_activated)
    {
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            // Get mouse position
            int x, y;
            x = event->button.x;
            y = event->button.y;

            Card * foundCard = findCard(x, y);
            if (foundCard != nullptr)
            {
                _lastVisitedCard = foundCard;
                _activated = false;
                foundCard->handleEvent(event);
            }
        }
    }

    else if (_lastVisitedCard != nullptr)
    {
        if (_lastVisitedCard->getRoom()->getBigCard()->displayed())
        {
            _lastVisitedCard->getRoom()->getBigCard()->handleEvent(event);
        }
    }
}

Card * Dungeon::findCard(int positionX, int positionY)
{
    for (auto &card : _playedDeck)
    {
        if (positionX >= card->getX() && positionX <= card->getX() + CARD_WIDTH && positionY >= card->getY()
            && positionY <= card->getY() + CARD_HEIGHT)
        {
            return card.get();
        }
    }
    return nullptr;
}

void Dungeon::update()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->update();
        if (_playedDeck[i]->updatePlayer())
        {
            _playedDeck[i]->setUpdate(false);
            auto * playState = (PlayState *) GameStateManager::get().getCurrentGameState();
            playState->updateCurrentPlayer(_playedDeck[i]->getRoom(),
                                           _playedDeck[i]->getRoom()->getBigCard()->accept());
            _playedDeck[i]->getRoom()->getBigCard()->setAccept(false);
            _playedDeck[i]->getRoom()->getBigCard()->setRefuse(false);

            _returnedCardsCount ++;
            if(_returnedCardsCount == NB_CARDS_INGAME)
            {
                cleanup();
                regenerate();
                init();
            }
        }
    }
}

void Dungeon::render()
{
    bool noBigCard = true;
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->render();
        if (_playedDeck[i]->getRoom()->getBigCard()->displayed())
        {
            noBigCard = false;
        }
    }
    if (noBigCard)
    {
        _activated = true;
    }
}

void Dungeon::cleanup()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->cleanup();
    }
}