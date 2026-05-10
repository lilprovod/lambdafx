#include <stdbool.h>
#include <math.h>

#include "chord.h"
#include "io.h"
#include "equation.h"

MethodResult chord_method(const InputData* data, const Interval* interval)
{
    double a   = data->parameter_a;
    bool debug = data->debug_enabled;
    MethodDebugInfo debug_info = { 0 };
    MethodResult result = { 0, 0, true };
    
    if (debug) {
        print_method_header("Chord");
    }

    double left = interval->left, right = interval->right;
    double f_left = equation(left, a), f_right = equation(right, a);

    size_t iters = 0;
    double x_previous = left;
    double x_current = (left * f_right - right * f_left) /
                       (f_right - f_left);

    while (fabs(x_current - x_previous) > EPS && iters < CHORD_MAX_ITERATIONS) {
        iters++;
        x_previous = x_current;

        double f_x = equation(x_current, a);

        if (f_left * f_x < 0) {
            right = x_current;
            f_right = f_x;
        } else {
            left = x_current;
            f_left = f_x;
        }
        
        // Вырожденное решение
        if (fabs(f_right - f_left) < EPS) {
            result.success = false;
            break;
        }

        x_current = (left * f_right - right * f_left) / (f_right - f_left);

        if (debug) {
            debug_info.iteration = iters;
            debug_info.lambda = x_previous;
            debug_info.function_value = f_x;

            print_method_debug(&debug_info, "C");
        }
    }

    if (debug) {
        print_blank();
    }

    result.iterations = iters;
    result.lambda = x_current;

    // Нет сходимости
    if (iters >= CHORD_MAX_ITERATIONS)
        result.success = false;

    return result;
}