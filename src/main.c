#include <stdio.h>

#include "io.h"

int main(int argc, char* argv[])
{
    InputData data = { 0 };

    if (!parse_args(argc, argv, &data)) {
        return 1;
    }

    printf("Successfully parsed:\n\na = %f\ndebug: %s",
            data.parameter_a, (data.debug_enabled) ? "ON" : "OFF");

    return 0;
}