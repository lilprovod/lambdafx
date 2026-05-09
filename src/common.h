#ifndef COMMON_H
#define COMMON_H

#define EPS 1e-14

typedef struct {
    double parameter_a;
    bool debug_enabled;
} InputData;

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

#endif