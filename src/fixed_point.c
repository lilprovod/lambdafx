#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#include "equation.h"
#include "fixed_point.h"
#include "io.h"

double phi(double lambda, double a)
{
    if (lambda < 1.0) return NAN;

    double reversed = 1.0 / lambda;

    double term1 = sqrt(1 - reversed);
    double term2 = log(sqrt(lambda) + sqrt(lambda - 1));

    double function = a / (term1 + reversed * term2);

    return function;
}

MethodResult fp_method(const InputData* data, double lambda)
{
    double a   = data->parameter_a;
    bool debug = data->debug_enabled;
    MethodDebugInfo debug_info = { 0 };
    MethodResult result = {0, 0, true};

    if (debug) {
        print_method_header("Fixed point");
    }

    size_t iters = 0;
    double x_previous = lambda;

    // Применяем метод релаксациии для повышения сходимости:
    // Введем 0 < FP_ALPHA < 1
    // x = (1 - FP_ALPHA) * x_previous + FP_ALPHA * x
    double x_raw = phi(x_previous, a);
    double x_current = (1.0 - FP_ALPHA) * x_previous + FP_ALPHA * x_raw;

    while (fabs(x_current - x_previous) > EPS && iters < FP_MAX_ITERATIONS) {
        iters++;
        x_previous = x_current;
        
        x_raw = phi(x_previous, a);

        if (isnan(x_raw)) {
            result.success = false;
            break;
        }

        x_current = (1.0 - FP_ALPHA) * x_previous + FP_ALPHA * x_raw;

        if (debug) {
            debug_info.iteration = iters;
            debug_info.lambda = x_current;
            debug_info.function_value = equation(x_current, a);

            print_method_debug(&debug_info, "FP");
        }
    }

    if (debug) {
        print_blank();
    }

    result.iterations = iters;
    result.lambda = x_current;

    if (iters >= FP_MAX_ITERATIONS) {
        result.success = false;
    }

    return result;
}