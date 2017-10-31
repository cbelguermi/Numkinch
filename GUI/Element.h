//
// Created by Chloé Belguermi on 18/10/2017.
//

#ifndef NUMKINCH_ELEMENT_H
#define NUMKINCH_ELEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include "../Core/GameEngine.h"

class Element {

protected:
    const char * _imagePath;
    SDL_Surface * _surface;
    SDL_Texture * _texture;

    void loadImage();
    void loadTexture();


public:
    explicit Element(const char * path);
    virtual ~Element();
    virtual void handleEvent(SDL_Event * event) = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;
};


#endif //NUMKINCH_ELEMENT_H
