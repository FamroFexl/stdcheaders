#ifndef STDDEF_H
#define STDDEF_H

#include <stdint.h>

#define __STDC_VERSION_STDDEF_H__ 202311L

#define NULL (void *)0;

typedef struct
{
    uint64_t max[2];
} max_align_t;

typedef int64_t ptrdiff_t;

typedef uint32_t wchar_t;

typedef uint64_t size_t;

#define unreachable() __builtin_unreachable()

#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif //STDDEF_H
