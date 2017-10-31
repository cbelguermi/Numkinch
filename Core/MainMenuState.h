//
// Created by Chloé Belguermi on 18/10/2017.
//

#ifndef NUMKINCH_MAINMENUSTATE_H
#define NUMKINCH_MAINMENUSTATE_H

#include "GameEngine.h"
#include "GameState.h"
#include "../GUI/MenuBackground.h"
#include "../GUI/Button.h"

#define MENU_BG_PATH        "./res/menu_bg.png"
#define PLAY_BUTTON_PATH    "./res/play_btn.png"
#define QUIT_BUTTON_PATH    "./res/quit_btn.png"

#define PLAY_BUTTON_X ((GameEngine::get().getWindowWidth() / 2) - (MENU_BUTTON_WIDTH / 2))
#define PLAY_BUTTON_Y ((GameEngine::get().getWindowHeight() / 2) - (MENU_BUTTON_HEIGHT / 2))
#define QUIT_BUTTON_X ((GameEngine::get().getWindowWidth() / 2) - (MENU_BUTTON_WIDTH / 2))
#define QUIT_BUTTON_Y ((GameEngine::get().getWindowHeight() / 2) + MENU_BUTTON_HEIGHT)

class MainMenuState : public GameState {

private:
    MenuBackground _menuBg;
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
