#pragma once
#include "stdafx.h"

const double PI =  3.1415926535897932384626433832795028842;



/* Create a linearly spaced vector */
std::vector<double> linspace( double from, double to, int numPoints );
/* Compute the sum of a vector */
double sum( const std::vector<double>& v );
/* Compute the mean of a vector */ 
double mean( const std::vector<double>& v );
/*  Compute the standard deviation of a vector */
double standardDeviation( const std::vector<double>& v, bool population=0 );
/*  Find the minimum of a vector */
double min( const std::vector<double>& v );
/*  Find the maximum of a vector */
double max( const std::vector<double>& v );
/*  Find the given percentile of a vector */
double prctile( const std::vector<double>& v, double percentage );
/*  Sort a vector */
std::vector<double> sort( const std::vector<double>&  v );

/*  Create uniformly distributed random numbers */
std::vector<double> randuniform( int n );
/*  Create normally distributed random numbers */
std::vector<double> randn( int n );
/*  Seeds the default random number generator */
void rng( const std::string& setting );




/*
 *  Compute the cumulative 
 *  dustribution functiom of the
 *  normal distribution
 */

double normcdf( double x );

/*
 * Comput the inverse of normcdf
 */
double norminv( double x );

/*
 * Test function
 */

void testMatlib();

