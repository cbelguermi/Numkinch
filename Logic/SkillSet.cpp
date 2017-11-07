//
// Created by Chloé Belguermi on 03/11/2017.
//

#include "SkillSet.h"

void SkillSet::setSkillValue(int val, int skill) {

    switch (skill) {
        case attack:
            _attack.setValue(val);
        case defense:
            _defense.setValue(val);
        case agility:
            _agility.setValue(val);
        default:
            ;
    }

}

void SkillSet::setSkillMaxValue(int maxVal, int skill) {

    switch (skill) {
        case attack:
            _attack.setMaxValue(maxVal);
        case defense:
            _defense.setMaxValue(maxVal);
        case agility:
            _agility.setMaxValue(maxVal);
        default:
            ;
    }
}

int SkillSet::getSkillValue(int skill) const {

    switch (skill) {
        case attack:
            _attack.getValue();
        case defense:
            _defense.getValue();
        case agility:
            _agility.getValue();
        default:
            throw -1;
    }
}

int SkillSet::getSkillMaxValue(int skill) const {

    switch (skill) {
        case attack:
            _attack.getMaxValue();
        case defense:
            _defense.getMaxValue();
        case agility:
            _agility.getMaxValue();
        default:
            throw -1;
    }
}

void SkillSet::alterSkillPoints(int val, int skill) {

    switch (skill) {
        case attack:
            _attack.alterPoints(val);
        case defense:
            _defense.alterPoints(val);
        case agility:
            _agility.alterPoints(val);
        default:
            ;
    }
}

void SkillSet::alterSkillMaxPoints(int maxVal, int skill) {

    switch (skill) {
        case attack:
            _attack.alterMaxPoints(maxVal);
        case defense:
            _defense.alterMaxPoints(maxVal);
        case agility:
            _agility.alterMaxPoints(maxVal);
        default:
            ;
    }
}
