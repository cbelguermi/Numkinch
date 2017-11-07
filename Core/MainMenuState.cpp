//
// Created by Chloé Belguermi on 18/10/2017.
//

#include <cassert>
#include <SDL_image.h>
#include "MainMenuState.h"
#include "ChooseCharactersState.h"

MainMenuState::MainMenuState() : _menuBg(MENU_BG_PATH),
                                 _menuNewPlayBtn(PLAY_BUTTON_PATH, PLAY_BUTTON_X, PLAY_BUTTON_Y, MENU_BUTTON_WIDTH,
                                 MENU_BUTTON_HEIGHT),
                                 _menuQuitBtn(QUIT_BUTTON_PATH, QUIT_BUTTON_X, QUIT_BUTTON_Y, MENU_BUTTON_WIDTH,
                                 MENU_BUTTON_HEIGHT)
{}

void MainMenuState::onEnter() {

}

void MainMenuState::onExit() {

    _menuNewPlayBtn.cleanup();
    _menuQuitBtn.cleanup();
    _menuBg.cleanup();
}

void MainMenuState::handleEvents() {

    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }

        _menuNewPlayBtn.handleEvent(&event);
        if (_menuNewPlayBtn.pressed())
        {
            GameStateManager::get().changeGameState(new ChooseCharactersState());
        }

        _menuQuitBtn.handleEvent(&event);
        if (_menuQuitBtn.pressed())
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }
    }
}

void MainMenuState::render() {

    _menuBg.render();
    _menuNewPlayBtn.render();
    _menuQuitBtn.render();
}

void MainMenuState::update() {

}