//
// Created by Chloé Belguermi on 17/10/2017.
//

#include "GameEngine.h"
#include "MainMenuState.h"

#define INIT_FAILED (-1)

// Static declarations
SDL_Window * GameEngine::_gameWindow;
SDL_Renderer * GameEngine::_gameRenderer;

/* ========== Singleton ========== */
GameEngine GameEngine::_gameEngine;

GameEngine & GameEngine::get()
{
    return _gameEngine;
}
/* =============================== */

/* ========== Constructor ========== */
GameEngine::GameEngine()
{
    _running = true;
    _gameWindow = nullptr;
    _gameRenderer = nullptr;
}
/* ================================= */

SDL_Window * GameEngine::getGameWindow()
{
    return _gameWindow;
}

SDL_Renderer * GameEngine::getGameRenderer()
{
    return _gameRenderer;
}

int GameEngine::getWindowWidth() const
{
    return WINDOW_WIDTH;
}

int GameEngine::getWindowHeight() const
{
    return WINDOW_HEIGHT;
}

/**
 * Creates game window.
 *
 * @return true if window creation succeeded.
 */
bool GameEngine::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // start SDL
    {
        return false;
    }

    IMG_Init(IMG_INIT_PNG);

    if ((_gameWindow = SDL_CreateWindow("Numkinch",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT,
                                        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)) == nullptr)
    {
        return false;
    }

    if ((_gameRenderer = SDL_CreateRenderer(GameEngine::getGameWindow(), -1, SDL_RENDERER_ACCELERATED)) == nullptr)
    {
        SDL_ShowSimpleMessageBox(0, "Renderer init error",
                                 SDL_GetError(), GameEngine::getGameWindow());
        return false;
    }

    return true;
}

void GameEngine::handleEvents()
{
    GameStateManager::get().getCurrentGameState().handleEvents();
}

void GameEngine::update()
{
    GameStateManager::get().getCurrentGameState().update();
}

void GameEngine::render()
{
    GameStateManager::get().getCurrentGameState().render();
}

/**
 * Launches game state manager.
 *
 * @return 0 if game exited successfully.
 */
int GameEngine::onExecute()
{
    if (!onInit())
    {
        return INIT_FAILED;
    }

    GameStateManager::get().pushGameState(new MainMenuState());

    /* Game Loop */
    while (_running)
    {
        handleEvents();

        update();

        render();

        SDL_RenderPresent(GameEngine::getGameRenderer());
    }


    onCleanup(); // clean resources

    return EXIT_SUCCESS;
}

/**
 * Exits game loop.
 *
 */
void GameEngine::Quit()
{
    _running = false;
}


/**
 * Shutdowns SDL.
 *
 */
void GameEngine::onCleanup()
{
    SDL_DestroyRenderer(getGameRenderer());
    SDL_DestroyWindow(getGameWindow());
    IMG_Quit();
    SDL_Quit();
}

GameEngine::~GameEngine()
{
    _gameRenderer = nullptr;
    _gameWindow = nullptr;
}