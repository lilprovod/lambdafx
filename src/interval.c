#include "equation.h"
#include "interval.h"

bool find_interval(double a, Interval* interval)
{
    double start = 1.0, end = 2.0;
    double step = 1.0;

    double function_start = equation(start, a);

    while (function_start * equation(end, a) >= 0) {
        end  += step;
        step *= 2;

        if (end > MAX_END_BOUND) {
            return false;
        }
    }

    interval->left  = start;
    interval->right = end;

    return true;
}