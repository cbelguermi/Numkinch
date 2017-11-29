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

GameStateManager::~GameStateManager()
{
    while (!_gameStates.empty())
    {
        popGameState();
    }
}
/* ============================================== */

/**
 *
 * @return the current state
 */
GameState * GameStateManager::getCurrentGameState() const
{
    return _gameStates.top().get();
}

/**
 * Switch to a new game state but pauses only current state (keep it in stack).
 *
 * @param newState the replacing state of the current state
 */
void GameStateManager::pushGameState(GameState * newState)
{
    // Push new state and activate it
    _gameStates.push(unique_ptr<GameState>(newState));
    _gameStates.top()->onEnter();
}

/**
 * Exits current game state.
 */
void GameStateManager::popGameState()
{
    // Clean-up current state
    if (!_gameStates.empty())
    {
        _gameStates.top()->onExit();
        _gameStates.pop();
    }
}