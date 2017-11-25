//
// Created by Chloé Belguermi on 21/11/2017.
//

#include <zconf.h>
#include "Card.h"
#include "../GUI/GUIConstants.h"

#define BACK_CARD_PATH "./res/BackCard.png"
#define FRONT_CARD_PATH "./res/FrontCard.png"


static int nb_visited = 0;

Card::Card(Room * room, int column, int line) : _room(room),
                                                _backCardBtn(BACK_CARD_PATH, column * CARD_WIDTH + CARD_MARGIN_SIDE,
                                                             line * CARD_HEIGHT + CARD_MARGIN_TOP, CARD_WIDTH,
                                                             CARD_HEIGHT),
                                                _frontCardTile(FRONT_CARD_PATH,
                                                               column * CARD_WIDTH + CARD_MARGIN_SIDE,
                                                               line * CARD_HEIGHT + CARD_MARGIN_TOP, CARD_WIDTH,
                                                               CARD_HEIGHT)
{
    _positionX = column * CARD_WIDTH + CHAR_CARD_MARGIN_SIDE;
    _positionY = line * CARD_HEIGHT + CHAR_CARD_MARGIN_TOP;
}

Room * Card::getRoom()
{
    return _room;
}

void Card::handleEvent(SDL_Event * event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        if (!_room->visited())
        {
            _backCardBtn.handleEvent(event);
            if (_backCardBtn.pressed())
            {
                _room->setVisited(true);
                _room->getBigCard()->setDisplay(true);
                printf("NB visited: %d, last %d %d, set %d\n", ++nb_visited, getX(), getY(),
                       _room->getBigCard()->displayed());

            }
        }
    }
}

void Card::render()
{
    _backCardBtn.render();
    if (_room->visited())
    {
        _backCardBtn.cleanup();
        _frontCardTile.render();
        /*printf("rendered visited %d %d\n\n", (getX() - CHAR_CARD_MARGIN_SIDE) / CARD_WIDTH, (getY() -
        CHAR_CARD_MARGIN_TOP) / CARD_HEIGHT);
         */
        if (_room->getBigCard()->displayed())
        {
            _room->getBigCard()->render();
        }
    }
}

void Card::cleanup()
{
    if (!_room->visited())
    {
        _backCardBtn.cleanup();
    }
    else if (_room->visited())
    {
        _frontCardTile.cleanup();
    }
}

int Card::getX() const
{
    return _positionX;
}

int Card::getY() const
{
    return _positionY;
}
