//
// Created by Chloé Belguermi on 22/10/2017.
//

#include "ChooseCharactersState.h"
#include "../Logic/CharacterFactory.h"
#include "PlayState.h"
#include "../GUI/GUIConstants.h"
#include "GameStateManager.h"
#include "../Logic/Races.h"

#define THIEF_PATH "./res/thief.png"
#define WIZARD_PATH "./res/wizard.png"

#define CHOOSE_CHAR_BG_PATH "./res/choose_bg.png"
#define GAME_BUTTON_PATH    "./res/game_btn.png"


ChooseCharactersState::ChooseCharactersState() : _chooseCharacterBg(CHOOSE_CHAR_BG_PATH),
                                                 _playGameBtn(GAME_BUTTON_PATH,
                                                              ((WINDOW_WIDTH / 2) - (MENU_BUTTON_WIDTH / 2)),
                                                              ((WINDOW_HEIGHT / 2) - (MENU_BUTTON_HEIGHT / 2)),
                                                              MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT),
                                                 _randomPlayers(NB_PLAYERS), _characters(NB_PLAYERS)
{}

void ChooseCharactersState:: playStateHandler(vector<Race *> & players)
{
    auto * playState = new PlayState();
    playState->setPlayers(players);
    GameStateManager::get().changeGameState(playState);
}

void ChooseCharactersState::onEnter()
{
    for (int i = 0; i < NB_PLAYERS; i++) {
        _randomPlayers[i] = CharacterFactory::get().createCharacter();
    }
}

void ChooseCharactersState::onExit()
{
    _playGameBtn.cleanup();
    _chooseCharacterBg.cleanup();
}

void ChooseCharactersState::handleEvents()
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

        _playGameBtn.handleEvent(&event);
        if (_playGameBtn.pressed())
        {
            playStateHandler(_randomPlayers);
            break;
        }
    }
}

void ChooseCharactersState::update()
{
    for (int i = 0; i < NB_PLAYERS; i++) {
        if (_randomPlayers[i]->getRace() == elf)
        {
            _characters[i] = new Sprite(THIEF_PATH, 20 + 200 * i, 10, 200, 600);
        }
        else
        {
            _characters[i] = new Sprite(WIZARD_PATH, 20 + 200 * i, 10, 200, 600);
        }
    }
}

void ChooseCharactersState::render()
{
    _chooseCharacterBg.render();
    for (int i = 0; i < NB_PLAYERS; i++) {
        _characters[i]->render();
    }
    //_playGameBtn.render();
}

ChooseCharactersState::~ChooseCharactersState() = default;