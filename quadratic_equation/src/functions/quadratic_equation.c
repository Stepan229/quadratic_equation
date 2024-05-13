#include "../quadratic_equation.h"

quadratic_t solve_equation(double a, double b, double c) {
  quadratic_t quadratic;
  quadratic.error = SINGLE_ROOT_QUADRATIC;
  quadratic.x_1 = NAN;
  quadratic.x_2 = NAN;
  // Проверка на корректность входных аргументов
  // a, b, c  - не являются NaN
  if (!isnan(a) && !isnan(b) && !isnan(c)) {
    double discriminant = b * b - 4.0 * a * c;  // Вычисление дискриминанта
    // Проверка на существование действительных  корней
    if (discriminant >= 0 || (a == 0 && b == 0)) {  
      if (c == 0 && (a == 0 || b == 0))  // Проверка на равенство корней нулю
      {
        quadratic.x_1 = 0.0;
        quadratic.x_2 = 0.0;
      } else if (discriminant == 0)  // Проверка на совпадение корней
      {
        quadratic.x_1 = (-b - sqrt(discriminant)) / (2.0 * a);
        quadratic.x_2 = quadratic.x_1;
      } else if (a == 0)  // Проверка на существование x^2
      {
        quadratic.x_1 = -c / b;
        quadratic.x_2 = quadratic.x_1;
      } else {
        quadratic.x_1 = (-b - sqrt(discriminant)) / (2.0 * a);
        quadratic.x_2 = (-b + sqrt(discriminant)) / (2.0 * a);
        quadratic.error = SUCCESS_QUADRATIC;
      }
    } else
      quadratic.error = COMPLEX_ROOT_QUADRATIC;
  } else {
    quadratic.error = INCORRECT_QUADRATIC;
  }
  return quadratic;
}