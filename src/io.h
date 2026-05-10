#ifndef IO_H
#define IO_H

#include <stdbool.h>

#include "common.h"

void print_usage();

void print_method_debug(const MethodDebugInfo* info);

void print_method_header();

bool parse_args(int argc, char* argv[], InputData* data);

#endif