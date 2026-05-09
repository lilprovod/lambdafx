#ifndef IO_H
#define IO_H

#include <stdbool.h>

typedef struct {
    double parameter_a;
    bool debug_enabled;
} InputData;

void print_usage();

bool parse_args(int argc, char* argv[], InputData* data);

#endif