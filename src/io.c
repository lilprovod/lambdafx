#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"

void print_usage()
{
    printf(
        "Usage: ./lambdafx <a> [--debug]\n"
    );
}

void print_chord_debug(const ChordDebugInfo* info)
{
    printf("%-5zu | %.17g | %.17g\n",
            info->iteration, info->lambda, info->function_value);
}

void print_chord_header()
{
    printf("Debug info format:\n");
    printf("iter | lambda | F(lambda)\n");
}

bool parse_args(int argc, char* argv[], InputData* data)
{
    if (argc < 2 || argc > 3) {
        print_usage();
        return false;
    } else {
        char* endptr;
        data->parameter_a = strtod(argv[1], &endptr);

        if (argv[1] == endptr || *endptr != '\0') {
            fprintf(stderr, "Incorrect value for parameter a: %s\n", argv[1]);
            return false;
        }
        if (data->parameter_a < 0.0) {
            fprintf(stderr, "Right part of equation must be positive: %s\n", argv[1]);
            return false;
        }

        if (argc == 3) {
            if (strcmp(argv[2], "--debug") == 0) {
                data->debug_enabled = true;
            } else {
                fprintf(stderr, "Unknown argument: %s\n", argv[2]);
                return false;
            }
        } else {
            data->debug_enabled = false;
        }
    }

    return true;
}