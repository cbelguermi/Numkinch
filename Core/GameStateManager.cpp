//
// Created by Chloé Belguermi on 18/10/2017.
//

#include "GameStateManager.h"

/* ========== Singleton ========== */
GameStateManager GameStateManager::_gameStateManager;

GameStateManager & GameStateManager::get() {

    return _gameStateManager;
}

/* ========== Constructor / Destructor ========== */
GameStateManager::GameStateManager() = default;

GameStateManager::~GameStateManager() {

    while (!_gameStates.empty())
    {
        _gameStates.pop();
    }
}
/* ============================================== */

/**
 *
 * @return the current state
 */
GameState * GameStateManager::getCurrentGameState() const {

    return _gameStates.top().get();
}

/**
 * Exits current game state and replace it by a new game state.
 *
 * @param newState the replacing state of the current state
 */
void GameStateManager::changeGameState(GameState * newState) {

    // Clean-up current state
    if (!_gameStates.empty())
    {
        _gameStates.top()->onExit();
        _gameStates.pop();
    }

    // Push new state and activate it
    _gameStates.push(unique_ptr<GameState>(newState));
    _gameStates.top()->onEnter();
}

/**
 * Switch to a new game state but pauses only current state (keep it in stack).
 *
 * @param newState the replacing state of the current state
 */
void GameStateManager::pushGameState(GameState * newState) {

    // Pause current state
    if (!_gameStates.empty())
    {
       //TODO: pause
    }

    // Push new state and activate it
    _gameStates.push(unique_ptr<GameState>(newState));
    _gameStates.top()->onEnter();
}

/**
 * Exits current game state and switch back to previous game state if exists.
 */
void GameStateManager::popGameState() {

    // Clean-up current state
    if (!_gameStates.empty())
    {
        _gameStates.top()->onExit();
        _gameStates.pop();
    }

    // Resume previous state
    if (! _gameStates.empty())
    {
        //TODO: resume
    }
}

void GameStateManager::updateCurrentGameState() {

    if (!_gameStates.empty())
    {
        _gameStates.top()->update();
    }

}
