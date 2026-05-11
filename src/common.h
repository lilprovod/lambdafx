#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>

#define ROOT_EPS 1e-14
#define ITER_EPS 5e-15

typedef struct {
    double parameter_a;
    bool debug_enabled;
} InputData;

typedef struct {
    const char* method_name;
    double lambda;
    size_t iterations;
    bool success;
} MethodResult;

typedef struct {
    size_t iteration;
    double lambda;
    double function_value;
} MethodDebugInfo;

#endif