#pragma once
#include "ContinuousTimeOptionBase.h"



/* A knock-out option ceases to exist when the
 * underlying asset price reaches a certain barrier.
 */

class KnockoutOption : public ContinuousTimeOptionBase {
public:
    virtual ~KnockoutOption() {}

    double getBarrier() const {
        return barrier;
    }

    void setBarrier(double barrier) {
        this->barrier=barrier;
    }

    bool isPathDependent() const {
        return true;
    }
private:
    double barrier;
};
