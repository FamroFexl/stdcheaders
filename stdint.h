#ifndef STDINT_H
#define STDINT_H

#define __STDC_VERSION_STDINT_H__ 202311L

/**
 * Integer Types
 */

// Exact-width integer types
typedef __signed__ char      int8_t;
typedef unsigned char        uint8_t;

typedef __signed__ short     int16_t;
typedef unsigned short       uint16_t;

typedef __signed__ int       int32_t;
typedef unsigned int         uint32_t;

typedef __signed__ long long int64_t;
typedef unsigned long long   uint64_t;

// Minimum-width integer types
typedef int8_t   int_least8_t;
typedef uint8_t  uint_least8_t;

typedef int16_t  int_least16_t;
typedef uint16_t uint_least16_t;

typedef int32_t  int_least32_t;
typedef uint32_t uint_least32_t;

typedef int64_t  int_least64_t;
typedef uint64_t uint_least64_t;

// Fastest minimum-width integer types
typedef int32_t  int_fast8_t;
typedef uint32_t uint_fast8_t;

typedef int32_t  int_fast16_t;
typedef uint32_t uint_fast16_t;

typedef int32_t  int_fast32_t;
typedef uint32_t uint_fast32_t;

typedef int64_t  int_fast64_t;
typedef uint64_t uint_fast64_t;

// Integer types capable of holding object pointers
typedef int64_t  intptr_t;
typedef uint64_t uintptr_t;

//Greatest-width integer types
typedef int64_t  intmax_t;
typedef uint64_t uintmax_t;

/**
 * Macros for Integer Constant Expressions
 */

// Macros for minimum-width integer constant expressions
#define INT8_C(value)    value
#define UINT8_C(value)   value ## U

#define INT16_C(value)   value
#define UINT16_C(value)  value ## U

#define INT32_C(value)   value
#define UINT32_C(value)  value ## U

#define INT64_C(value)   value ## LL
#define UINT64_C(value)  value ## ULL

// Macros for greatest-width integer constant expressions
#define INTMAX_C(value)  value ## LL
#define UINTMAX_C(value) value ## ULL

/**
 * Limits of Specified-Width Integer Types
 */

// Limits of exact-width integer types
#define INT8_MAX   INT8_C(127)
#define INT8_MIN   INT8_C((-INT8_MAX)-1)
#define UINT8_MAX  UINT8_C(INT8_MAX*2)

#define INT16_MAX  INT16_C(32767)
#define INT16_MIN  INT16_C((-INT16_MAX)-1)
#define UINT16_MAX UINT16_C(INT16_MAX*2)

#define INT32_MAX  INT32_C(2147483647)
#define INT32_MIN  INT32_C((-INT32_MAX)-1)
#define UINT32_MAX UINT32_C(INT32_MAX*2)

#define INT64_MAX  INT64_C(9223372036854775807)
#define INT64_MIN  INT64_C((-INT64_MAX)-1)
#define UINT64_MAX UINT64_C(INT64_MAX*2)

// Limits of minimum-width integer types
#define INT_LEAST8_MIN   INT8_MIN
#define INT_LEAST8_MAX   INT8_MAX
#define UINT_LEAST8_MAX  UINT8_MAX

#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST16_MAX  INT16_MAX
#define UINT_LEAST16_MAX UINT16_MAX

#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST32_MAX  INT32_MAX
#define UINT_LEAST32_MAX UINT32_MAX

#define INT_LEAST64_MIN  INT64_MIN
#define INT_LEAST64_MAX  INT64_MAX
#define UINT_LEAST64_MAX UINT64_MAX

// Limits of fastest minimum-width integer types
#define INT_FAST8_MIN   INT32_MIN
#define INT_FAST8_MAX   INT32_MAX
#define UINT_FAST8_MAX  UINT32_MAX

#define INT_FAST16_MIN  INT32_MIN
#define INT_FAST16_MAX  INT32_MAX
#define UINT_FAST16_MAX UINT32_MAX

#define INT_FAST32_MIN  INT32_MIN
#define INT_FAST32_MAX  INT32_MAX
#define UINT_FAST32_MAX UINT32_MAX

#define INT_FAST64_MIN  INT64_MIN
#define INT_FAST64_MAX  INT64_MAX
#define UINT_FAST64_MAX UINT64_MAX

// Limits of integer types capable of holding object pointers
#define INTPTR_MIN  INT64_MIN
#define INTPTR_MAX  INT64_MAX
#define UINTPTR_MAX UINT64_MAX

// Limits of greatest-width integer types
#define INTMAX_MIN  INT64_MIN
#define INTMAX_MAX  INT64_MAX
#define UINTMAX_MAX UINT64_MAX

/**
 * Limits of Other Integer Types
 */

// Limits of ptrdiff_t
#define PTRDIFF_MIN INT64_MIN
#define PTRDIFF_MAX INT64_MAX

// Limits of sig_atomic_t
#define SIG_ATOMIC_MIN INT32_MIN
#define SIG_ATOMIC_MAX INT32_MAX

// Limit of size_t
#define SIZE_MAX UINT64_MAX

// Limits of wchar_t
#define WCHAR_MIN 0
#define WCHAR_MAX UINT32_MAX

// Limits of wint_t
#define WINT_MIN INT32_MIN
#define WINT_MAX INT32_MAX

/**
 * Widths of Specified-Width Integer Types
 */

// Widths of exact-width integer types
#define INT8_WIDTH   1
#define UINT8_WIDTH  INT8_WIDTH

#define INT16_WIDTH  2
#define UINT16_WIDTH INT16_WIDTH

#define INT32_WIDTH  4
#define UINT32_WIDTH INT32_WIDTH

#define INT64_WIDTH  8
#define UINT64_WIDTH INT64_WIDTH

// Widths of minimum-width integer types
#define INT_LEAST8_WIDTH   INT8_WIDTH
#define UINT_LEAST8_WIDTH  UINT8_WIDTH

#define INT_LEAST16_WIDTH  INT16_WIDTH
#define UINT_LEAST16_WIDTH UINT16_WIDTH

#define INT_LEAST32_WIDTH  INT32_WIDTH
#define UINT_LEAST32_WIDTH UINT32_WIDTH

#define INT_LEAST64_WIDTH  INT64_WIDTH
#define UINT_LEAST64_WIDTH UINT64_WIDTH

// Widths of fastest minimum-width integer types
#define INT_FAST8_WIDTH   INT32_WIDTH
#define UINT_FAST8_WIDTH  UINT32_WIDTH

#define INT_FAST16_WIDTH  INT32_WIDTH
#define UINT_FAST16_WIDTH UINT32_WIDTH

#define INT_FAST32_WIDTH  INT32_WIDTH
#define UINT_FAST32_WIDTH UINT32_WIDTH

#define INT_FAST64_WIDTH  INT64_WIDTH
#define UINT_FAST64_WIDTH UINT64_WIDTH

// Widths of integer types capable of holding object pointers
#define INTPTR_WIDTH  INT64_WIDTH
#define UINTPTR_WIDTH UINT64_WIDTH

// Widths of greatest-width integer types
#define INTMAX_WIDTH  INT64_WIDTH
#define UINTMAX_WIDTH UINT64_WIDTH

/**
 * Widths of Other Integer Types
 */

// Width of ptrdiff_t
#define PTRDIFF_WIDTH INT64_WIDTH

// Width of sig_atomic_t
#define SIG_ATOMIC_WIDTH INT32_WIDTH

// Width of size_t
#define SIZE_WIDTH UINT64_WIDTH

// Width of wchar_t
#define WCHAR_WIDTH UINT32_WIDTH

// Width of wint_t
#define WINT_WIDTH INT32_WIDTH

#endif //STDINT_H
