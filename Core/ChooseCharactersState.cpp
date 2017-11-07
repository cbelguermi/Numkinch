//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "ChooseCharactersState.h"
#include "PlayState.h"
#include "../Logic/CharacterFactory.h"

#define NB_PLAYERS 4

ChooseCharactersState::ChooseCharactersState() : _chooseCharacterBg(CHOOSE_CHAR_BG_PATH),
                                                 _playGameBtn(GAME_BUTTON_PATH, GAME_BUTTON_X, GAME_BUTTON_Y,
                                                 GAME_BUTTON_WIDTH, GAME_BUTTON_HEIGHT)
{}

void ChooseCharactersState:: playStateHandler()
{
    GameState * playState = new PlayState(_randomPlayers);
    GameStateManager::get().changeGameState(playState);
}

//TODO: generate 4 randomly chosen characters, put them in a vector and pass it to PlayState
void ChooseCharactersState::onEnter()
{
    for (int i = 0; i < NB_PLAYERS; i++) {
        _randomPlayers.push_back(unique_ptr<Race>(CharacterFactory::get().createCharacter()));
    }
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
            playStateHandler();
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