#pragma once

#include "stdafx.h"
#include "Priceable.h"

/*
 * A Portfolio contains different options in various quantities
 */

class Portfolio : public Priceable {
public:
    /* Virtual destructor */
    virtual ~Portfolio() {};
    /* Return the number of items in the portfolio */
    virtual int size() const = 0;
    /* Add a new security to the portfolio, return the index at which it was added */
    virtual int add( double quantity, std::shared_ptr<Priceable> security ) = 0;
    /* Update the quantity at a given index */
    virtual void setQuantity( int index, double quantity ) = 0;
    /* Compute the current price */
    virtual double price( const BlackScholesModel& model ) const = 0;
    /* Create a Portfolio */
    static std::shared_ptr<Portfolio> newInstance();
};

void testPortfolio();

