/*
 *  Tests for errors in macro fail handling.
 *  HALF-MANUAL TEST: use your eyes to verify fail printouts.
 */
#include <limits.h>
#include "asrt.h"

int fail_count = 0;

// redefine _ASRT_FAIL so we only print fail messages without aborting
#undef _ASRT_FAIL
#define _ASRT_FAIL() fail_count++

void
test_fail_ASRT_true()
{
	int x = 0;
	char *p = NULL;
	double zero = 0.0;
	double nzero = -0.0;
	ASRT_true(x);
	ASRT_true(p);
	ASRT_true(zero);
	ASRT_true(nzero);
}

void
test_fail_ASRT_char()
{
	char first = 'a';
	char second = 'b';
	ASRT_char(first, second);
}

void
test_fail_ASRT_strz()
{
	char *strA = "hello";
	char *strB = "world";
	ASRT_strz(strA, strB);
	ASRT_strz(strA, "");
	ASRT_strz("", strB);
	ASRT_strz(strA, NULL);
	ASRT_strz(NULL, strB);
}

void
test_fail_ASRT_int()
{
	int a = 5;
	int b = 7;
	ASRT_int(a, b);
	ASRT_int(INT_MIN, INT_MAX);
}

void
test_fail_ASRT_size_t()
{
	size_t a = 5;
	size_t b = 7;
	ASRT_size_t(a, b);
	ASRT_size_t(b, SIZE_T_MAX);
}

int
main(int argc, char const *argv[])
{
	test_fail_ASRT_true();
	test_fail_ASRT_char();
	test_fail_ASRT_strz();
	test_fail_ASRT_int();
	test_fail_ASRT_size_t();
	printf("fail_count = %d\n", fail_count);
	return 0;
}