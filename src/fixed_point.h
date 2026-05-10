#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include "common.h"

#define FP_ALPHA 0.1
#define FP_MAX_ITERATIONS 10000

/**
 * @brief Описывает функцию вида `λ = φ(λ)` для метода простой итерации
 * 
 * @param lambda[in] Корень уравения `λ`
 * @param a[in]      Параметр из правой части, равный (`√2 * ω0*t`)
 */
double phi(double lambda, double a);

/**
 * @brief Метод простой итерации для решения уравнения.
 * 
 * @param input[in]  Входные данные (параметр и флаг debug)
 * @param lambda[in] Стартовое значение `λ`
 */
MethodResult fp_method(const InputData* input, double lambda);

#endif