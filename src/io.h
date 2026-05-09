#ifndef IO_H
#define IO_H

#include <stdbool.h>

#include "common.h"

void print_usage();

void print_chord_debug(const ChordDebugInfo* info);

void print_chord_header();

bool parse_args(int argc, char* argv[], InputData* data);

#endif