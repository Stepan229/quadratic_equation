#ifndef QUADRATIC_EQUATION
#define QUADRATIC_EQUATION

#include <math.h>
#include <stddef.h>

// INCORRECT_QUADRATIC - недопустимые входные данные
// SUCCESS_QUADRATIC - два действительных корня
// SINGLE_ROOT_QUADRATIC - один действительный корень
// COMPLEX_ROOT_QUADRATIC - два комплексных корня
enum ERROR_QUADRATIC {
  INCORRECT_QUADRATIC = -1,
  SUCCESS_QUADRATIC,
  SINGLE_ROOT_QUADRATIC,
  COMPLEX_ROOT_QUADRATIC,
};

// x_1 - первый корень квадратного уравнения
// x_2 - второй корень квадратного уравнения
// error - возможная ошибка при решении квадратного уравнения
typedef struct quadratic_struct {
  double x_1;
  double x_2;
  int error;
} quadratic_t;

quadratic_t solve_equation(double a, double b, double c);

#endif