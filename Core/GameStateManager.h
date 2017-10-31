//
// Created by Chloé Belguermi on 18/10/2017.
//

#ifndef NUMKINCH_GAMESTATEMANAGER_H
#define NUMKINCH_GAMESTATEMANAGER_H

#include <stack>
#include "GameState.h"
#include <memory>

using namespace std;

class GameStateManager {

private:
    static GameStateManager _gameStateManager;
    stack<unique_ptr<GameState>> _gameStates;

public:
    static GameStateManager & get();

    GameStateManager(const GameStateManager &) = delete; // avoid copy

    GameStateManager & operator=(const GameStateManager&) = delete; // avoid copy


public:
    GameState & getCurrentGameState() const;

    void changeGameState(GameState * newState);

    void pushGameState(GameState * newState);

    void popGameState();

    void updateCurrentGameState();

private:
    GameStateManager(); // avoid instancing
    ~GameStateManager();

};


#endif //NUMKINCH_GAMESTATEMANAGER_H
