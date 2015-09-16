// TODO: #ifndef NDEBUG ???

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Redefine next two macros if you want to integrate ASRT into your test framework.
 * For example you can make them return 0 and 1 instead of aborting.
 * Do this ONLY for your framework code because other user code might use plain asserting.
 */
#define _ASRT_FAIL() abort()
#define _ASRT_PASS() ((void)0)


#define ASRT_true(A) \
	do { \
    	if (!(A)) { \
    		printf( \
    			"%s:%u:\n" \
    			"ASRT_true(%s)\n\n", \
    			__FILE__, __LINE__, #A \
    		); \
    		_ASRT_FAIL(); \
		} \
		_ASRT_PASS(); \
    } while (0)

#define ASRT_char(A, B) \
	do { \
    	if ((A) != (B)) { \
    		printf( \
    			"%s:%u:\n" \
    			"ASRT_char(%s, %s)\n" \
    			"expect: '%c'\t(0x%X)\n" \
    			"actual: '%c'\t(0x%X)\n\n", \
    			__FILE__, __LINE__, #A, #B, (A), (A), (B), (B) \
    		); \
    		_ASRT_FAIL(); \
		} \
		_ASRT_PASS(); \
    } while (0)

#define ASRT_strz(A, B) \
    do { \
    	if ((A) == NULL && (B) == NULL) { \
    		_ASRT_PASS(); \
    	} else if ((A) == NULL) { \
    		printf( \
    			"%s:%u:\n" \
    			"ASRT_strz(%s, %s)\n" \
    			"expect: NULL\n" \
    			"actual: \"%s\"\n\n", \
    			__FILE__, __LINE__, #A, #B, (B) \
    		); \
    		_ASRT_FAIL(); \
    	} else if ((B) == NULL) { \
    		printf( \
    			"%s:%u:\n" \
    			"ASRT_strz(%s, %s)\n" \
    			"expect: \"%s\"\n" \
    			"actual: NULL\n\n", \
    			__FILE__, __LINE__, #A, #B, (A) \
    		); \
    		_ASRT_FAIL(); \
    	} else if (strcmp((A), (B)) != 0) { \
    		printf( \
    			"%s:%u:\n" \
    			"ASRT_strz(%s, %s)\n" \
    			"expect: \"%s\"\n" \
    			"actual: \"%s\"\n\n", \
    			__FILE__, __LINE__, #A, #B, (A), (B) \
    		); \
    		_ASRT_FAIL(); \
    	} else { \
    		_ASRT_PASS(); \
		} \
    } while (0)

#define ASRT_int(A, B) \
    do { \
        if ((A) != (B)) { \
            printf( \
                "%s:%u:\n" \
                "ASRT_int(%s, %s)\n" \
                "expect: %d\t(0x%X)\n" \
                "actual: %d\t(0x%X)\n\n", \
                __FILE__, __LINE__, #A, #B, (A), (A), (B), (B) \
            ); \
            _ASRT_FAIL(); \
        } \
        _ASRT_PASS(); \
    } while (0)

#define ASRT_size_t(A, B) \
    do { \
        if ((A) != (B)) { \
            printf( \
                "%s:%u:\n" \
                "ASRT_size_t(%s, %s)\n" \
                "expect: %zu\t(0x%zX)\n" \
                "actual: %zu\t(0x%zX)\n\n", \
                __FILE__, __LINE__, #A, #B, (A), (A), (B), (B) \
            ); \
            _ASRT_FAIL(); \
        } \
        _ASRT_PASS(); \
    } while (0)

