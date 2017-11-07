//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "Skill.h"

Skill::Skill() : _value(0), _maxValue(0) { }

Skill::Skill(int maxValue, int value) {

    if (maxValue >= 0) {
        _maxValue = maxValue;
        if (value >= 0 && value <= maxValue) {
            _value = value;
        }
        else {
            _value = _maxValue;
        }
    }
    else {
        _maxValue = 0;
        _value = 0;
    }
}

int Skill::getValue() const {

    return _value;
}

int Skill::getMaxValue() const {

    return _maxValue;
}

void Skill::setValue(int val) {

    if (val >= 0 && val <= _maxValue) {
        _value = val;
    }
    else {
        _value = 0;
    }
}

void Skill::setMaxValue(int maxVal) {

    if (maxVal >= 0 && maxVal >= _value) {
        _maxValue = maxVal;
    }
    else {
        _maxValue = _value;
    }
}

void Skill::alterPoints(int val) {

    if ((_value + val) < 0) {
        _value = 0;
    }
    else if ((_value + val) > _maxValue) {
        _value = _maxValue;
    }
    else {
        _value += val;
    }
}

void Skill::alterMaxPoints(int maxVal) {

    if ((_maxValue + maxVal) < 0) {
        _maxValue = 0;
        setValue(0);
    }
    else if ((_maxValue + maxVal) < _value) {
        _maxValue += maxVal;
        setValue(_maxValue);
    }
    else {
        _maxValue += maxVal;
    }
}