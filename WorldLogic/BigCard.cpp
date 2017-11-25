//
// Created by Chloé Belguermi on 24/11/2017.
//

#include "BigCard.h"
#include "../GUI/GUIConstants.h"
#include "../Core/GameStateManager.h"

#define BIG_CARD_PATH "./res/BigCard.png"
#define REFUSE_BTN_PATH "./res/FleeBtn.png"

BigCard::BigCard(bool hasRefuseBtn, const char * acceptBtnPath, const char * entityImagePath, const char * topText,
                 const char * entityNameText,
                 const char * descriptionText) : _cardImage(BIG_CARD_PATH, (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2),
                                                            (WINDOW_HEIGHT / 2) - (BIG_CARD_HEIGHT / 2), BIG_CARD_WIDTH,
                                                            BIG_CARD_HEIGHT),

                                                 _acceptBtn(acceptBtnPath, (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                                           + 20, (WINDOW_HEIGHT / 2) -
                                                                    (BIG_CARD_HEIGHT / 2) + BIG_CARD_HEIGHT - 80,
                                                            BUTTON_WIDTH, BUTTON_HEIGHT),

                                                 _refuseBtn(REFUSE_BTN_PATH, (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                                             + 126, (WINDOW_HEIGHT / 2) -
                                                                    (BIG_CARD_HEIGHT / 2) + BIG_CARD_HEIGHT - 80,
                                                            BUTTON_WIDTH, BUTTON_HEIGHT),

                                                 _entityImage(entityImagePath, (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                                               + ENTITY_IMAGE_MARGIN_SIDE,
                                                              (WINDOW_HEIGHT / 2) - (BIG_CARD_HEIGHT / 2) +
                                                                      ENTITY_IMAGE_MARGIN_TOP, ENTITY_IMAGE_WIDTH,
                                                              ENTITY_IMAGE_HEIGHT),

                                                 _topTxt(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, topText,
                                                         (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                         + ENTITY_IMAGE_MARGIN_SIDE, (WINDOW_HEIGHT / 2) -
                                                                                     (BIG_CARD_HEIGHT / 2) + 20),

                                                 _entityNameTxt(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, entityNameText,
                                                                (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                                + ENTITY_IMAGE_MARGIN_SIDE, (WINDOW_HEIGHT / 2) -
                                                                        (BIG_CARD_HEIGHT / 2) + ENTITY_IMAGE_MARGIN_TOP
                                                                                            + ENTITY_IMAGE_HEIGHT + 10),

                                                 _descriptionTxt(TTF_OpenFont(FONT_PATH, 15), 0, 0, 0, descriptionText,
                                                                 (WINDOW_WIDTH / 2) - (BIG_CARD_WIDTH / 2)
                                                                 + ENTITY_IMAGE_MARGIN_SIDE, (WINDOW_HEIGHT / 2) -
                                                                                             (BIG_CARD_HEIGHT / 2) +
                                                                         ENTITY_IMAGE_MARGIN_TOP + ENTITY_IMAGE_HEIGHT
                                                                                             + 25)
{
    _hasRefuseBtn = hasRefuseBtn;
    _displayed = false;
}

bool BigCard::hasRefuseBtn() const
{
    return _hasRefuseBtn;
}

bool BigCard::displayed() const
{
    return _displayed;
}

void BigCard::setDisplay(bool displayed)
{
    _displayed = displayed;
}

void BigCard::init()
{
    _cardImage.init();
    _acceptBtn.init();
    if (hasRefuseBtn())
    {
        _refuseBtn.init();
    }
    _entityImage.init();
}

void BigCard::handleEvent(SDL_Event * event)
{
    _acceptBtn.handleEvent(event);
    if (hasRefuseBtn())
    {
        _refuseBtn.handleEvent(event);
    }
    if (_acceptBtn.pressed())
    {
        setDisplay(false);
        cleanup();
    }
    else if (_refuseBtn.pressed())
    {
        setDisplay(false);
        cleanup();
    }
}

void BigCard::render()
{
    _cardImage.render();
    _acceptBtn.render();
    if (hasRefuseBtn())
    {
        _refuseBtn.render();
    }
    _entityImage.render();
    _topTxt.render();
    _entityNameTxt.render();
    _descriptionTxt.render();
}

void BigCard::cleanup()
{
    _descriptionTxt.cleanup();
    _entityNameTxt.cleanup();
    _topTxt.cleanup();
    if (hasRefuseBtn())
    {
        _refuseBtn.cleanup();
    }
    _acceptBtn.cleanup();
    _cardImage.cleanup();
}
