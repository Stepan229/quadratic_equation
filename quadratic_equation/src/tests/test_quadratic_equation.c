#include <check.h>

#include "../quadratic_equation.h"
#define TOLERANCE 1e-15

START_TEST(test_quad_1) {
  double a, b, c;
  double expected_x_1 = -2;
  double expected_x_2 = -1;
  int expected_return = 0;
  a = 1;
  b = 3;
  c = 2;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}
// Дискриминант < 0
START_TEST(test_quad_2) {
  double a, b, c;
  int expected_return = 2;
  a = 3;
  b = 3;
  c = 3;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_nan(func_return.x_1);
  ck_assert_double_nan(func_return.x_2);
  ck_assert_int_eq(func_return.error, expected_return);
}

// Дискриминант = 0
START_TEST(test_quad_3) {
  double a, b, c;
  double expected_x_1 = -1;
  double expected_x_2 = -1;
  int expected_return = 1;
  a = 3;
  b = 6;
  c = 3;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

// a = 0, c = 0
START_TEST(test_quad_4) {
  double a, b, c;
  double expected_x_1 = 0;
  double expected_x_2 = 0;
  int expected_return = 1;
  a = 0;
  b = 6;
  c = 0;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

// a = 0
START_TEST(test_quad_5) {
  double a, b, c;
  double expected_x_1 = -1;
  double expected_x_2 = -1;
  int expected_return = 1;
  a = 0;
  b = 6;
  c = 6;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

// b = 0
START_TEST(test_quad_6) {
  double a, b, c;
  int expected_return = 2;
  a = 6;
  b = 0;
  c = 6;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_nan(func_return.x_1);
  ck_assert_double_nan(func_return.x_2);
  ck_assert_int_eq(func_return.error, expected_return);
}

// c = 0
START_TEST(test_quad_7) {
  double a, b, c;
  double expected_x_1 = -1;
  double expected_x_2 = 0;
  int expected_return = 0;
  a = 6;
  b = 6;
  c = 0;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}



START_TEST(test_quad_8) {
  double a, b, c;
  double expected_x_1 = -5.03878086260614;
  double expected_x_2 = 1.786888830975022;
  int expected_return = 0;
  a = 1.1231345;
  b = 3.652312131;
  c = -10.11241242146902114;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}



// a = NaN
START_TEST(test_quad_9) {
  double a, b, c;
  int expected_return = -1;
  a = NAN;
  b = 3.652312131;
  c = 3.652312131;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_nan(func_return.x_1);
  ck_assert_double_nan(func_return.x_2);
  ck_assert_int_eq(func_return.error, expected_return);
}

//b = 0 c = 0
START_TEST(test_quad_10) {
  double a, b, c;
  double expected_x_1 = 0;
  double expected_x_2 = 0;
  int expected_return = 1;
  a = 6;
  b = 0;
  c = 0;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

// c = 0
START_TEST(test_quad_11) {
  double a, b, c;
  double expected_x_1 = -0.5;
  double expected_x_2 = 0;
  int expected_return = 0;
  a = 6;
  b = 3;
  c = 0;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

// b = 0
START_TEST(test_quad_12) {
  double a, b, c;
  double expected_x_1 = -0.7071067811865475;
  double expected_x_2 = 0.7071067811865475;
  int expected_return = 0;
  a = 6;
  b = 0;
  c = -3;
  quadratic_t func_return = solve_equation(a, b, c);
  ck_assert_double_eq_tol(func_return.x_1, expected_x_1, TOLERANCE);
  ck_assert_double_eq_tol(func_return.x_2, expected_x_2, TOLERANCE);
  ck_assert_int_eq(func_return.error, expected_return);
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

Suite *quadratic_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("quadratic_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_quad_1);
  tcase_add_test(tc_core, test_quad_2);
  tcase_add_test(tc_core, test_quad_3);
  tcase_add_test(tc_core, test_quad_4);
  tcase_add_test(tc_core, test_quad_5);
  tcase_add_test(tc_core, test_quad_6);
  tcase_add_test(tc_core, test_quad_7);
  tcase_add_test(tc_core, test_quad_8);
  tcase_add_test(tc_core, test_quad_9);
  tcase_add_test(tc_core, test_quad_10);
  tcase_add_test(tc_core, test_quad_11);
  tcase_add_test(tc_core, test_quad_12);

  suite_add_tcase(s1, tc_core);
  return s1;
}

int main() {
  int fail = 0;
  case_test(quadratic_suite(), &fail);
  return fail;
}