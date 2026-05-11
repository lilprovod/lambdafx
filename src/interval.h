#ifndef INTERVAL_H
#define INTERVAL_H

#include <stdbool.h>

#define MAX_END_BOUND 1e6

typedef struct {
    double left;
    double right;
} Interval;

/**
 * @brief Ищет интервал функции `F(λ)`, на котором она пересекает ось OX.
 * 
 * @param a[in]         Параметр правой части уравнения
 * @param interval[out] Найденный интервал
 * 
 * @return Возвращает `true`, если интервал успешно найден. Иначе `false`.
 */
bool find_interval(double a, Interval* interval);

#endif