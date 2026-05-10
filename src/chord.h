#ifndef CHORD_H
#define CHORD_H

#include <stddef.h>

#include "common.h"
#include "interval.h"

#define CHORD_MAX_ITERATIONS 100
#define CHORD_PREFIX_NAME "CH"

/**
 * @brief Метод хорд для решения уравнения.
 */
MethodResult chord_method(const InputData* data, const Interval* interval);

#endif