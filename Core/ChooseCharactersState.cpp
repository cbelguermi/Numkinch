//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "ChooseCharactersState.h"
#include "../Logic/CharacterFactory.h"
#include "PlayState.h"

ChooseCharactersState::ChooseCharactersState() : _chooseCharacterBg(CHOOSE_CHAR_BG_PATH),
                                                 _playGameBtn(GAME_BUTTON_PATH, GAME_BUTTON_X, GAME_BUTTON_Y,
                                                 GAME_BUTTON_WIDTH, GAME_BUTTON_HEIGHT)
{}

void ChooseCharactersState:: playStateHandler(vector<Race *> & players)
{
    auto * playState = new PlayState();
    playState->setPlayers(players);
    GameStateManager::get().changeGameState(playState);
}

//TODO: generate 4 randomly chosen characters, put them in a vector and pass it to PlayState
void ChooseCharactersState::onEnter()
{
}

void ChooseCharactersState::onExit()
{
   _chooseCharacterBg.cleanup();
}

void ChooseCharactersState::handleEvents()
{

    vector<Race *> randomPlayers(NB_PLAYERS);
    for (int i = 0; i < NB_PLAYERS; i++) {
        randomPlayers[i] = CharacterFactory::get().createCharacter();
    }

    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }

        _playGameBtn.handleEvent(&event);
        if (_playGameBtn.pressed())
        {
            playStateHandler(randomPlayers);
            break;
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