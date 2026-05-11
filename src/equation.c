#include <math.h>

#include "equation.h"

double equation_log(double lambda, double a)
{
    if (lambda < 1.0) return NAN;

    double term1 = sqrt(lambda * (lambda - 1.0));
    
    double root1 = sqrt(lambda);
    double root2 = sqrt(lambda - 1.0);
    double term2 = log(root1 + root2);

    double function = term1 + term2 - a;

    return function;
}

double equation_acosh(double lambda, double a)
{
    if (lambda < 1.0) return NAN;

    double root = sqrt(lambda);
    
    double term1 = sqrt(lambda * (lambda - 1.0));
    double term2 = acosh(root);

    double function = term1 + term2 - a;

    return function;
}