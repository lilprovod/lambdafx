#include <math.h>
#include <stdio.h>

#include "io.h"
#include "interval.h"
#include "equation.h"
#include "chord.h"

int main(int argc, char* argv[])
{
    InputData data = { 0 };

    if (!parse_args(argc, argv, &data)) {
        return 1;
    }

    if (fabs(equation(1.0, data.parameter_a)) < EPS) {
        printf("Exact root: 1.0\n");
        return 0;
    }

    Interval root_interval = { 0 };
    if (!find_interval(data.parameter_a, &root_interval)) {
        fprintf(stderr, "Unable to find root interval\n");
        return 1;
    }

    ChordResult result = chord_method(&data, &root_interval);

    if (result.success) {
        printf("Root: %.17g\n", result.lambda);
        printf("Iterations: %zu\n", result.iterations);
    } else {
        printf("Unsuccessful chord method\n");
    }

    return 0;
}