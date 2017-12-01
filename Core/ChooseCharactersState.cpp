//
// Created on 22/10/2017.
//

#include "ChooseCharactersState.h"
#include "../PlayerLogic/CharacterFactory.h"
#include "PlayState.h"
#include "../GUI/GUIConstants.h"
#include "GameStateManager.h"

#define CARD_PATH "./res/CardBase.png"
#define CHOOSE_CHAR_BG_PATH "./res/choose_bg.png"
#define GAME_BUTTON_PATH    "./res/game_btn.png"

ChooseCharactersState::ChooseCharactersState() : _chooseCharacterBg(CHOOSE_CHAR_BG_PATH),
                                                 _playGameBtn(GAME_BUTTON_PATH,
                                                              ((WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2)),
                                                              ((WINDOW_HEIGHT / 2) - (BUTTON_HEIGHT / 2)) +
                                                                      CHAR_CARD_HEIGHT,
                                                              BUTTON_WIDTH, BUTTON_HEIGHT),
                                                 _characters(NB_PLAYERS)
{
    _randomPlayers.reserve(NB_PLAYERS);
}

void ChooseCharactersState:: playStateHandler()
{
    auto * playState = new PlayState(move(_randomPlayers));

    GameStateManager::get().pushGameState(playState);
}

void ChooseCharactersState::onEnter()
{
    _chooseCharacterBg.init();
    _playGameBtn.init();

    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _randomPlayers.push_back(unique_ptr<Race>(CharacterFactory::get().createCharacter()));
    }

    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _characters[i] = new CharacterCard(CARD_PATH, CHAR_CARD_MARGIN_SIDE + i * CHAR_CARD_WIDTH,
                                                CHAR_CARD_MARGIN_TOP, CHAR_CARD_WIDTH, CHAR_CARD_HEIGHT,
                                                _randomPlayers[i]->RaceToString(), _randomPlayers[i]->ClassToString(),
                                                _randomPlayers[i]->getName());
        _characters[i]->init();
    }
}

void ChooseCharactersState::onExit()
{
    _playGameBtn.cleanup();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _characters[i]->cleanup();
    }
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
            break;
        }
    }
}

void ChooseCharactersState::update()
{}

void ChooseCharactersState::render()
{
    _chooseCharacterBg.render();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _characters[i]->render();
    }
    _playGameBtn.render();
}

ChooseCharactersState::~ChooseCharactersState()
{
    for (auto character : _characters)
    {
        delete character;
    }
}