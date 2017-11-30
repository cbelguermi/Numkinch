//
// Created on 18/10/2017.
//

#ifndef NUMKINCH_MAINMENUSTATE_H
#define NUMKINCH_MAINMENUSTATE_H

#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../GUI/Text.h"

#define MENU_BG_PATH        "./res/menu_bg.png"
#define PLAY_BUTTON_PATH    "./res/play_btn.png"
#define QUIT_BUTTON_PATH    "./res/quit_btn.png"

class MainMenuState : public GameState {

private:
    Background _menuBg;
    Button _menuNewPlayBtn;
    Button _menuQuitBtn;

public:
    MainMenuState();

    void onEnter() override;

    void onExit() override;

    void handleEvents() override;

    void update() override;

    void render() override;
};


#endif //NUMKINCH_MAINMENUSTATE_H
