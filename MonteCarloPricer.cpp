#include "MonteCarloPricer.h"
#include "matlib.h"
#include "CallOption.h"
#include "PutOption.h"

using namespace std;

MonteCarloPricer::MonteCarloPricer() : nScenarios(10000), nSteps(10) {
}

double MonteCarloPricer::price( const ContinuousTimeOption& option,
                                const BlackScholesModel& model ) {
    int nSteps = this->nSteps;
    if (!option.isPathDependent()) {
        nSteps = 1;
    }    
    double total = 0.0;
    for (int i =0; i < nScenarios; i++ ) {
        vector<double> path = model.generateRiskNeutralPricePath(
                                    option.getMaturity(), nSteps);
        
        double payoff = option.payoff( path );
        total += payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = option.getMaturity() - model.date;
    return exp(-r*T)*mean;
}

//////////////////////////////////////
//
//   Tests
//
//////////////////////////////////////


static void testPriceCallOption() {
    rng("default");

    CallOption c;
    c.setStrike( 110 );
    c.setMaturity( 2 );

    BlackScholesModel m;
    
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price( c, m );
    double expected = c.price( m );
    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

static void testPutAndCall() {
    rng("default");

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;

    CallOption c;
    c.setStrike( 110 );
    c.setMaturity( 2 );

    PutOption p;
    p.setStrike( c.getStrike() );
    p.setMaturity( c.getMaturity() );

    // pricer can price puts and calls
    MonteCarloPricer pricer;
    double priceC = pricer.price(c, m);
    ASSERT_APPROX_EQUAL(priceC, c.price(m), 0.1);
    double priceP = pricer.price(p, m);    
    ASSERT_APPROX_EQUAL(priceP, p.price(m), 0.1);
}


void testMonteCarloPricer() {
    TEST( testPriceCallOption );
    TEST( testPutAndCall );
}

















