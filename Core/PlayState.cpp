//
// Created by Chloé Belguermi on 07/11/2017.
//

#include "PlayState.h"
#include "../GUI/GUIConstants.h"
#include <cstdio>

#define STAT_CARD_PATH "./res/StatCard.png"

PlayState::PlayState(vector<unique_ptr<Race>> players) : _inGameBg(IN_GAME_BG_PATH), _playerStats(NB_PLAYERS),
                                                         _players(move(players))
{}

void PlayState::onEnter()
{
    _dungeon.generate();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        auto * playerNb = new char(2);
        sprintf(playerNb, "%d", i);
        auto * attack = new char(10);
        sprintf(attack, "%d / %d", _players[i]->getAttack().getValue(), _players[i]->getAttack().getMaxValue());
        auto * defense = new char(10);
        sprintf(defense, "%d / %d", _players[i]->getDefense().getValue(), _players[i]->getDefense().getMaxValue());
        auto * agility = new char(10);
        sprintf(agility, "%d / %d", _players[i]->getAgility().getValue(), _players[i]->getAgility().getMaxValue());
        auto * life = new char(10);
        sprintf(life, "%d / %d", _players[i]->getLife().getValue(), _players[i]->getLife().getMaxValue());

        _playerStats[i] = new StatCard(STAT_CARD_PATH, WINDOW_WIDTH - STAT_CARD_WIDTH,
                                       20 + STAT_CARD_HEIGHT * i, STAT_CARD_WIDTH, STAT_CARD_HEIGHT, playerNb, attack,
                                       defense, agility, life);
    }
}

void PlayState::onExit()
{
    _dungeon.cleanup();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->cleanup();
    }
    _inGameBg.cleanup();
}

void PlayState::handleEvents()
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

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            _dungeon.handleEvent(& event);
        }
    }
}

void PlayState::update() {}

void PlayState::render()
{
    _inGameBg.render();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->render();
    }
    _dungeon.render();
}

PlayState::~PlayState() = default;
