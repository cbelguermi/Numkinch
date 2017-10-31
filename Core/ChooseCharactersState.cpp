//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "ChooseCharactersState.h"
#include "MainMenuState.h"

ChooseCharactersState::ChooseCharactersState() : _chooseCharacterBg(CHOOSE_CHAR_BG_PATH),
                                                 _playGameBtn(GAME_BUTTON_PATH, GAME_BUTTON_X, GAME_BUTTON_Y)
{}

void ChooseCharactersState::onEnter()
{

}

void ChooseCharactersState::onExit()
{
   _chooseCharacterBg.cleanup();
}

void ChooseCharactersState::handleEvents()
{
    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            GameEngine::get().Quit();
            break;
        }

        _playGameBtn.handleEvent(&event);
        if (_playGameBtn.pressed())
        {
            GameStateManager::get().changeGameState(new MainMenuState());
        }
    }
}

void ChooseCharactersState::update()
{

}

void ChooseCharactersState::render()
{
    _chooseCharacterBg.render();
    _playGameBtn.render();
}

ChooseCharactersState::~ChooseCharactersState() = default;