//
// Created by Chloé Belguermi on 07/11/2017.
//

#ifndef NUMKINCH_PLAYSTATE_H
#define NUMKINCH_PLAYSTATE_H

#include <vector>
#include "../Logic/Race.h"
#include "GameState.h"

using namespace std;

class PlayState : public GameState {

private:
    vector<unique_ptr<Race>> _players;

public:
    PlayState() = default;

    explicit PlayState(vector<unique_ptr<Race>> & players);

    PlayState(const PlayState &) = default;

    void onEnter() override;

    void onExit() override;

    void handleEvents() override;

    void update() override;

    void render() override;

    ~PlayState() override;


};


#endif //NUMKINCH_PLAYSTATE_H
