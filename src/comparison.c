#include <float.h>
#include <stddef.h>
#include <math.h>

#include "comparison.h"

double delta(double value1, double value2)
{
    return fabs(value1 - value2);
}

int matching_digits(double value1, double value2)
{
    double diff = delta(value1, value2);
    if (diff == 0.0) return DBL_DIG;

    int digits = (int)-floor(log10(diff));

    return (digits > 0) ? digits : 0;
}