#pragma once
#include "BlackScholesModel.h"

/*
 * Represent a general security. 
 * This could be a stock, a bond, 
 * a derivative and so forth.
 */

class Priceable {
public:
    /* Compute the price of the security in the Black Scholes world */
    virtual double price( const BlackScholesModel& model ) const = 0;
};
