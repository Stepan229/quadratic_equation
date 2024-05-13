CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = quadratic_equation.a
LIB_DIR = functions/quadratic_equation.c
LIB_DIR_TEST = tests/*.c
LIBS_FOR_CHECK_PCKG = -lpthread -lcheck -lrt -lm -lsubunit

GCOV_FLAG = -fprofile-arcs -ftest-coverage


all: quadratic_equation.a

quadratic_equation.a:
	$(CC) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o

check: quadratic_equation.a
	$(CC) $(FLAGS) -o test.out $(LIB_DIR_TEST) -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) 
	./test.out

gcov_report:
	$(CC) $(FLAGS) -o test.out $(LIB_DIR_TEST) $(LIB_DIR) $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG) 

	./test.out
	lcov -t "test-funct" -o test-funct.info -c -d .
	rm -rf
	genhtml -o report test-funct.info
	rm -rf *.gcda *.gcno

clean:
	rm -f *.a *.o *.so *.out  *.info *.gcno *.gcda
	rm -rf report
	rm -rf .clang-format
	rm -rf function/.clang-format
