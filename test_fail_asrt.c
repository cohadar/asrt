/*
 *  Tests for errors in macro fail handling.
 *  HALF-MANUAL TEST: use your eyes to verify fail printouts.
 */
#include <limits.h>
#include "asrt.h"

int fail_count = 0;
int pass_count = 0;

// redefine _ASRT_FAIL so we only print fail messages without aborting
#undef _ASRT_FAIL
#define _ASRT_FAIL() fail_count++
// redefine _ASRT_PASS so we make sure it never happends in fail tests
#undef _ASRT_PASS
#define _ASRT_PASS() pass_count++

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

void
test_fail_ASRT_double()
{
	double distance = 1.01;
	double radius = 1.0;
	ASRT_double(distance, radius, 0.001);
	ASRT_double(1.0, 0.0, 0.0);
	ASRT_double(3300.0, 3000.0, 100.0);
}

void
test_fail_ASRT_uint32_t()
{
	uint32_t a = 5;
	uint32_t b = 7;
	ASRT_uint32_t(a, b);
	ASRT_uint32_t(b, UINT32_MAX);
}

int
main(int argc, char const *argv[])
{
	test_fail_ASRT_true();
	test_fail_ASRT_char();
	test_fail_ASRT_strz();
	test_fail_ASRT_int();
	test_fail_ASRT_size_t();
	test_fail_ASRT_double();
	test_fail_ASRT_uint32_t();
	printf("failed:%d, passed:%d\n", fail_count, pass_count);
	if (pass_count > 0 ) {
		printf("Error: You have a bad fail test!\n");
		return 1;
	} else {
		printf("All fails Ok!\n");
		return 0;
	}
}