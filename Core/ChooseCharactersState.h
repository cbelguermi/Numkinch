//
// Created by Chloé Belguermi on 22/10/2017.
//

#ifndef NUMKINCH_CHOOSECHARACTERSSTATE_H
#define NUMKINCH_CHOOSECHARACTERSSTATE_H

#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../Logic/Race.h"
#include <vector>

#define CHOOSE_CHAR_BG_PATH "./res/choose_bg.png"
#define GAME_BUTTON_PATH    "./res/game_btn.png"

#define GAME_BUTTON_X ((GameEngine::get().getWindowWidth() / 2) - (MENU_BUTTON_WIDTH / 2))
#define GAME_BUTTON_Y ((GameEngine::get().getWindowHeight() / 2) - (MENU_BUTTON_HEIGHT / 2))
#define GAME_BUTTON_WIDTH 100
#define GAME_BUTTON_HEIGHT 50

class ChooseCharactersState : public GameState {

private:
    Background _chooseCharacterBg;
    Button _playGameBtn;

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
