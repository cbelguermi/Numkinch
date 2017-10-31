//
// Created by Chloé Belguermi on 17/10/2017.
//

#ifndef NUMKINCH_GAMESTATE_H
#define NUMKINCH_GAMESTATE_H

class GameState {

public:
    virtual void onEnter() = 0;
    virtual void onExit() = 0;

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual ~GameState() = default;
};


#endif //NUMKINCH_GAMESTATE_H
