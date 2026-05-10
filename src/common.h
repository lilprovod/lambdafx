#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>

#define EPS 1e-14

typedef struct {
    double parameter_a;
    bool debug_enabled;
} InputData;

typedef struct {
    char* method_name;
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