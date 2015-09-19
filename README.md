# asrt
C assertion drop-in header

The goal is to have type specific assertion macros that give better fail messages than generic assert.
Most macros have a name in the form: ASRT_base_type
``` ASRT_char, ASRT_strz, ASRT_int, ASRT_size_t, ASRT_double ```
There is also a generic zero/null checker ```ASRT_true``` that behaves like standard assert.

I am a big believer in YAGNI principle: https://en.wikipedia.org/wiki/You_aren't_gonna_need_it ,
for this reason asrt header contains only C assertions I have actually used in code so far.
Basically I add them as I go along. This has the benefit that every assertion I add is very thoroughly tested.

## Example outputs of failing assertions

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:21:
ASRT_true(x)
```

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:32:
ASRT_char(first, second)
expect: 'a'	(0x61)
actual: 'b'	(0x62)
```

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:40:
ASRT_strz(strA, strB)
expect: "hello"
actual: "world"
```

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:43:
ASRT_strz(strA, NULL)
expect: "hello"
actual: NULL
```

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:53:
ASRT_int(INT_MIN, INT_MAX)
expect: -2147483648	(0x80000000)
actual: 2147483647	(0x7FFFFFFF)
```

```
/Users/cohadar/workspaces/c-workspaces/asrt/test_fail_asrt.c:62:
ASRT_size_t(b, SIZE_T_MAX)
expect: 7	(0x7)
actual: 18446744073709551615	(0xFFFFFFFFFFFFFFFF)
```

```
/Users/cohadar/workspaces/gcj-workspaces/gcj-practice/asrt/test_fail_asrt.c:74:
ASRT_double(distance, radius, 0.001)
expect: 1.0100000000000000e+00	(1.01)
actual: 1.0000000000000000e+00	(1)
tolrnc: 1.0000000000000000e-03	(0.001)
```

## Further development
As time goes by, more assertion will be added, but only if I or someone else actually need them.
I have no intention of creating a generic bloated library just because of false completeness requirement.
