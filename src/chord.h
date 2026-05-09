#ifndef CHORD_H
#define CHORD_H

#include <stddef.h>

#include "interval.h"
#include "io.h"

#define EPS 1e-14
#define MAX_ITERATIONS 100

typedef struct {
    double lambda;
    size_t iterations;
    bool success;
} ChordResult;

typedef struct {
    size_t iteration;
    double lambda;
    double function_value;
} ChordDebugInfo;

ChordResult chord_method(const InputData* data, const Interval* interval);

#endif