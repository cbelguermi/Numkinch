//
// Created by Chloé Belguermi on 03/11/2017.
//

#ifndef NUMKINCH_SKILL_H
#define NUMKINCH_SKILL_H

class Skill {

private:
    int _maxValue;
    int _value;

public:
    Skill();

    explicit Skill(int maxValue);

    int getValue() const;

    int getMaxValue() const;

    void setValue(int val);

    void setMaxValue(int maxVal);

    void alterPoints(int val);

    void alterMaxPoints(int maxVal);
};


#endif //NUMKINCH_SKILL_H
