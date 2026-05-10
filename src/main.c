#include <math.h>
#include <stdio.h>

#include "io.h"
#include "interval.h"
#include "equation.h"
#include "chord.h"
#include "fixed_point.h"
#include "comparison.h"

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

    print_method_result(&c_result, CHORD_MAX_ITERATIONS);
    print_method_result(&fp_result, FP_MAX_ITERATIONS);

    print_comparison_header();
    print_comparison_methods(&c_result, &fp_result);

    return 0;
}