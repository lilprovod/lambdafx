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

void print_chord_debug(ChordDebugInfo* info)
{
    printf("%-5s | %.17g | %.17g\n",
            info->iteration, info->lambda, info->function_value);
}

void print_chord_header()
{
    printf("Debug info format:\n");
    printf("iter | lambda | F(lambda)");
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

        if (argc == 3) {
            if (strcmp(argv[2], "--debug") == 0) {
                data->debug_enabled = true;
            }
        } else {
            data->debug_enabled = false;
        }
    }

    return true;
}