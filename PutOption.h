#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"
#include "PathIndependentOption.h"

class PutOption : public PathIndependentOption {
public:
    
    
    double payoff( double stockAtMaturity ) const;

    double price( const BlackScholesModel& bsm ) const;

};

void testPutOption();


