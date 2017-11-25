//
// Created by Chloé Belguermi on 24/11/2017.
//

#ifndef NUMKINCH_BIGCARD_H
#define NUMKINCH_BIGCARD_H


#include "../GUI/IHandleable.h"
#include "../GUI/IDisplayable.h"
#include "../GUI/Button.h"
#include "../GUI/Text.h"

class BigCard : IHandleable, IDisplayable {

private:
    bool _hasRefuseBtn;

    bool _displayed;

    Tile _cardImage;

    Button _acceptBtn;

    Button _refuseBtn;

    Tile _entityImage;

    Text _topTxt;

    Text _entityNameTxt;

    Text _descriptionTxt;

public:
    BigCard(bool hasRefuseBtn, const char * acceptBtnPath, const char * entityImagePath, const char * topText,
            const char * entityNameText, const char * descriptionText);

    bool hasRefuseBtn() const;

    bool displayed() const;

    void setDisplay(bool displayed);

    void init() override;

    void handleEvent(SDL_Event * event) override;

    void render() override;

    void cleanup() override;
};


#endif //NUMKINCH_BIGCARD_H
