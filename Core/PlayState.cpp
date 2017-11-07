//
// Created by Chloé Belguermi on 07/11/2017.
//

#include "PlayState.h"


PlayState::PlayState() : _inGameBg(IN_GAME_BG_PATH), _players(NB_PLAYERS) {

}

void PlayState::onEnter() {}

void PlayState::onExit() {

    _inGameBg.cleanup();

}

void PlayState::handleEvents() {

    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            onExit();
            GameEngine::get().Quit();
            break;
        }

    }

}

void PlayState::update() {

}

void PlayState::render() {

    _inGameBg.render();
}

void PlayState::setPlayers(vector<Race *> players) {

    for (auto &player : players) {
        _players.push_back(unique_ptr<Race>(player));
    }

}

PlayState::~PlayState() = default;
