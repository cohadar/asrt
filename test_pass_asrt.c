/*
 *  Tests that all assertions that should pass - pass.
 */
#include <limits.h>
#include "asrt.h"

void
test_pass_ASRT_true()
{
	int x = 5;
	ASRT_true(x);
	ASRT_true(&x);
	ASRT_true(test_pass_ASRT_true);
	ASRT_true("hello");
	ASRT_true("");
	ASRT_true(2.3);
}

void
test_pass_ASRT_char()
{
	ASRT_char('a', 'a');
	ASRT_char('\0', '\0');
	ASRT_char('\255', '\255');
}

void
test_pass_ASRT_strz()
{
	ASRT_strz("hello", "hello");
	ASRT_strz("", "");
	ASRT_strz(NULL, NULL);
}

void
test_pass_ASRT_int()
{
	ASRT_int(0, 0);
	ASRT_int(1, 1);
	ASRT_int(123, 123);
	ASRT_int(-1, -1);
	ASRT_int(INT_MIN, INT_MIN);
	ASRT_int(INT_MAX, INT_MAX);
}

void
test_pass_ASRT_size_t()
{
	ASRT_size_t((size_t)0, (size_t)0);
	ASRT_size_t((size_t)1, (size_t)1);
	ASRT_size_t((size_t)123, (size_t)123);
	ASRT_size_t(SIZE_T_MAX, SIZE_T_MAX);
}

int
main(int argc, char const *argv[])
{
	test_pass_ASRT_true();
	test_pass_ASRT_char();
	test_pass_ASRT_strz();
	test_pass_ASRT_int();
	test_pass_ASRT_size_t();
	printf("All OK.\n");
	return 0;
}
