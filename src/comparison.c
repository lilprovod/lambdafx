#include <stddef.h>
#include <math.h>

#include "comparison.h"

/** @brief Рассчитывает разницу между двумя числами. */
double delta(double value1, double value2)
{
    return fabs(value1 - value2);
}

/** @brief Возвращает количество совпадающих знаков между двумя числами. */
int matching_digits(double value1, double value2)
{
    double diff = delta(value1, value2);
    if (diff == 0.0) return 15;

    int digits = (int)-floor(log10(diff));

    return (digits > 0) ? digits : 0;
}