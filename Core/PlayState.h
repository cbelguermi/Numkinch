//
// Created by Chloé Belguermi on 07/11/2017.
//

#ifndef NUMKINCH_PLAYSTATE_H
#define NUMKINCH_PLAYSTATE_H

#include <vector>
#include "../Logic/Race.h"
#include "GameState.h"
#include "../GUI/Background.h"

#define IN_GAME_BG_PATH "./res/choose_bg.png"


using namespace std;

class PlayState : public GameState {

private:
    Background _inGameBg;
    vector<unique_ptr<Race>> _players;

public:
    PlayState();

    void setPlayers(vector<Race *> players);

    void onEnter() override;

    void onExit() override;

    void handleEvents() override;

    void update() override;

    void render() override;

    ~PlayState() override;


};


#endif //NUMKINCH_PLAYSTATE_H
