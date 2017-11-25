//
// Created by Chloé Belguermi on 18/10/2017.
//

#ifndef NUMKINCH_ELEMENT_H
#define NUMKINCH_ELEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include "../Core/GameEngine.h"
#include "IDisplayable.h"

class Element : public IDisplayable {

protected:
    const char * _imagePath;
    SDL_Surface * _surface;
    SDL_Texture * _texture;

    void loadImage();

    void loadTexture();


public:
    explicit Element(const char * path);

    virtual ~Element();

    void init() override;

    void render() override = 0;

    void cleanup() override;
};

#endif //NUMKINCH_ELEMENT_H
