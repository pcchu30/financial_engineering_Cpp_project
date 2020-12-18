#include "matlib.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "UpAndOutOption.h"
#include "DownAndOutOption.h"
#include "Portfolio.h"
using namespace std;

int main()
{
    testMatlib();
    testCallOption();
    testPutOption();
    testBlackScholesModel();
    testMonteCarloPricer();
    testUpAndOutOption();
    testDownAndOutOption();
    testContinuousTimeOptionBase();
    testPortfolio();
    return 0;
}
