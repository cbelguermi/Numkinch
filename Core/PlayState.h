//
// Created on 07/11/2017.
//

#ifndef NUMKINCH_PLAYSTATE_H
#define NUMKINCH_PLAYSTATE_H

#include <vector>
#include "../PlayerLogic/Race.h"
#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/StatCard.h"
#include "../WorldLogic/Dungeon.h"

#define IN_GAME_DEFAULT_BG_PATH "./res/choose_bg.png"
#define IN_GAME_BG_1_PATH "./res/play_bg_1.png"
#define IN_GAME_BG_2_PATH "./res/play_bg_2.png"
#define IN_GAME_BG_3_PATH "./res/play_bg_3.png"
#define IN_GAME_BG_4_PATH "./res/play_bg_4.png"

using namespace std;

class PlayState : public GameState {

private:
    Background _inGameBg;

    Dungeon _dungeon;

    vector<StatCard *> _playerStats;

    vector<unique_ptr<Race>> _players;

    unsigned int _currentPlayer;

public:
    explicit PlayState(vector<unique_ptr<Race>> players);

    void onEnter() override;

    void onExit() override;

    void handleEvents() override;

    void updateCurrentPlayer(Room * room, bool accept);

    void update() override;

    void render() override;

    ~PlayState() override;
};

#endif //NUMKINCH_PLAYSTATE_H
