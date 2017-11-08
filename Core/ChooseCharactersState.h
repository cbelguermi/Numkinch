//
// Created by Chloé Belguermi on 22/10/2017.
//

#ifndef NUMKINCH_CHOOSECHARACTERSSTATE_H
#define NUMKINCH_CHOOSECHARACTERSSTATE_H

#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../Logic/Race.h"
#include "../GUI/Sprite.h"
#include <vector>


using namespace std;

class ChooseCharactersState : public GameState {

private:
    Background _chooseCharacterBg;
    Button _playGameBtn;
    vector<Sprite *> _characters;

    vector<Race *> _randomPlayers;

    void playStateHandler(vector<Race *> & players);


public:
    ChooseCharactersState();

    void onEnter() override;

    void onExit() override;

    void handleEvents() override;

    void update() override;

    void render() override;

    ~ChooseCharactersState() override;
};


#endif //NUMKINCH_CHOOSECHARACTERSSTATE_H
