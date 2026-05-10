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

void print_blank() { printf("\n"); }

void print_method_debug(const MethodDebugInfo* info, const char* method_prefix)
{
    printf("[%s] %-5zu | %-24.17g | %.17g\n",
            method_prefix,
            info->iteration, info->lambda, info->function_value);
}

void print_method_header(const char* method_name)
{
    printf("%s method iterations:\n", method_name);
    printf("Debug info format:\n");
    printf("%-10s | %-24s | %-17s\n", "iter", "lambda", "F(lambda)");
}

void print_method_result(
    const MethodResult* result,
    const char* method_name,
    size_t max_method_iterations
)
{
    printf("=== %s ===\n\n", method_name);
    if (result->success) {
        printf("Lambda: %.17g\n", result->lambda);
        printf("Iterations: %zu\n\n", result->iterations);
    } else {
        printf("Unsuccessful method...\n\n");
        if (result->iterations >= max_method_iterations) {
            printf("Too many iterations of method.\n");
        } else {
            printf("Invalid lambda value (NaN).\n");
        }
    }
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