//
// Created by Chloé Belguermi on 18/10/2017.
//

#include <SDL_ttf.h>
#include "MainMenuState.h"
#include "GameStateManager.h"
#include "ChooseCharactersState.h"
#include "../GUI/GUIConstants.h"

MainMenuState::MainMenuState() : _menuBg(MENU_BG_PATH),
                                 _menuNewPlayBtn(PLAY_BUTTON_PATH, ((WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2)),
                                                 ((WINDOW_HEIGHT / 2) - (BUTTON_HEIGHT / 2)), BUTTON_WIDTH,
                                                 BUTTON_HEIGHT),
                                 _menuQuitBtn(QUIT_BUTTON_PATH, ((WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2)),
                                              ((WINDOW_HEIGHT / 2) + BUTTON_HEIGHT), BUTTON_WIDTH,
                                              BUTTON_HEIGHT)
{}

void MainMenuState::onEnter()
{

}

void MainMenuState::onExit()
{
    _menuNewPlayBtn.cleanup();
    _menuQuitBtn.cleanup();
    _menuBg.cleanup();
}

void MainMenuState::handleEvents()
{
    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }

        _menuNewPlayBtn.handleEvent(& event);
        if (_menuNewPlayBtn.pressed())
        {
            GameStateManager::get().changeGameState(new ChooseCharactersState());
        }

        _menuQuitBtn.handleEvent(& event);
        if (_menuQuitBtn.pressed())
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }
    }
}

void MainMenuState::update() {}

void MainMenuState::render()
{
    _menuBg.render();
    _menuNewPlayBtn.render();
    _menuQuitBtn.render();
}