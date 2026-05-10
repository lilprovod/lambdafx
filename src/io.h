#ifndef IO_H
#define IO_H

#include <stdbool.h>

#include "common.h"

void print_usage();

void print_blank();

void print_method_debug(const MethodDebugInfo* info, const char* method_name);

void print_method_header(const char* method_name);

bool parse_args(int argc, char* argv[], InputData* data);

#endif