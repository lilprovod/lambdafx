#ifndef IO_H
#define IO_H

#include <stdbool.h>

#include "chord.h"

typedef struct {
    double parameter_a;
    bool debug_enabled;
} InputData;

void print_usage();

void print_chord_debug(ChordDebugInfo* info);

void print_chord_header();

bool parse_args(int argc, char* argv[], InputData* data);

#endif