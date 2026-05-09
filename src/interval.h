#ifndef INTERVAL_H
#define INTERVAL_H

#include <stdbool.h>

#define MAX_END_BOUND 1e6

typedef struct {
    double left;
    double right;
} Interval;

bool find_interval(double a, Interval* interval);

#endif