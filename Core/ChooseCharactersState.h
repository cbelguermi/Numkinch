//
// Created on 22/10/2017.
//

#ifndef NUMKINCH_CHOOSECHARACTERSSTATE_H
#define NUMKINCH_CHOOSECHARACTERSSTATE_H

#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../PlayerLogic/Race.h"
#include "../GUI/Tile.h"
#include "../GUI/CharacterCard.h"
#include <vector>
#include <memory>

using namespace std;

class ChooseCharactersState : public GameState {

private:
    Background _chooseCharacterBg;
    Button _playGameBtn;
    vector<CharacterCard *> _characters;

    vector<unique_ptr<Race>> _randomPlayers;

    void playStateHandler();


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
