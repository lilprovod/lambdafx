#include <math.h>
#include <stdio.h>

#include "io.h"
#include "interval.h"
#include "equation.h"
#include "chord.h"
#include "fixed_point.h"

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

    // Экспериментально λ ≈ a, особенно при больших a
    double start_lambda = fmax(2.0, data.parameter_a);

    MethodResult c_result  = chord_method(&data, &root_interval);
    MethodResult fp_result = fp_method(&data, start_lambda);

    printf("---===    CHORD METHOD    ===---\n\n");
    if (c_result.success) {
        printf("Root: %.17g\n", c_result.lambda);
        printf("Iterations: %zu\n\n", c_result.iterations);
    } else {
        printf("Unsuccessful chord method...\n\n");
    }

    printf("---=== FIXED POINT METHOD ===---\n");
    if (fp_result.success) {
        printf("Root: %.17g\n", fp_result.lambda);
        printf("Iterations: %zu\n\n", fp_result.iterations);
    } else {
        printf("Unsuccessful fixed point method... Maybe phi(x) diverges?\n");
        printf("Count of method iterations: %zu\n\n", fp_result.iterations);
    }

    return 0;
}