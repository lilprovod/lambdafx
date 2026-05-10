#include <math.h>

#include "equation.h"

/**
 * @brief Описывает функцию `F(λ)`, равную разности уравнения и параметра
 * для проверки корня. Возвращает результат вычисления функции.
 * 
 * @param lambda[in] Корень уравения `λ`
 * @param a[in]      Параметр из правой части, равный (`√2 * ω0*t`)
 * 
 * @return Результат вычисления функции. Если результат равен нулю, `λ` является корнем.
 */
double equation(double lambda, double a)
{
    if (lambda < 1.0) return NAN;

    double term1 = sqrt(lambda * (lambda - 1.0));
    
    double root1 = sqrt(lambda);
    double root2 = sqrt(lambda - 1.0);
    double term2 = log(root1 + root2);

    double function = term1 + term2 - a;

    return function;
}