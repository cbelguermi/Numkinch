//
// Created by Chloé Belguermi on 22/10/2017.
//

#ifndef NUMKINCH_MENUBACKGROUND_H
#define NUMKINCH_MENUBACKGROUND_H

#include "Element.h"

class Background : public Element {

public:
    explicit Background(const char * path);

    void handleEvent(SDL_Event * event) override;

    void render() override;

    void cleanup() override;

};


#endif //NUMKINCH_MENUBACKGROUND_H
