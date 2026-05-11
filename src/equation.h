#ifndef EQUATION_H
#define EQUATION_H

/**
 * @brief Описывает функцию `F(λ)`, равную разности уравнения и параметра
 * для проверки корня. Возвращает результат вычисления функции.
 * 
 * @note Использует логарифм на прямую.
 * 
 * @param lambda[in] Корень уравения `λ`
 * @param a[in]      Параметр из правой части, равный (`√2 * ω0*t`)
 * 
 * @return Результат вычисления функции. Если результат равен нулю, `λ` является корнем.
 */
double equation_log(double lambda, double a);

/**
 * @note Версия `equation_log` с использованием функции `acosh` для вычисления логарифма.
 */
double equation_acosh(double lambda, double a);

#endif