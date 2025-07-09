#ifndef STDATOMIC_H
#define STDATOMIC_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define __STDC_VERSION_STDATOMIC_H__ 202311L

typedef _Atomic(bool)               atomic_bool;
typedef _Atomic(int8_t)             atomic_schar;
typedef _Atomic(uint8_t)            atomic_uchar;
typedef _Atomic(int16_t)            atomic_short;
typedef _Atomic(uint16_t)           atomic_ushort;
typedef _Atomic(int32_t)            atomic_int;
typedef _Atomic(uint32_t)           atomic_uint;
typedef _Atomic(int64_t)            atomic_long;
typedef _Atomic(uint64_t)           atomic_ulong;
typedef _Atomic(int64_t)            atomic_llong;
typedef _Atomic(uint64_t)           atomic_ullong;
// Support is not provided for char8_t, char16_t, or char32_t
typedef _Atomic(wchar_t)            atomic_wchar_t;
typedef _Atomic(int_least8_t)       atomic_int_least8_t;
typedef _Atomic(uint_least8_t)      atomic_uint_least8_t;
typedef _Atomic(int_least16_t)      atomic_int_least16_t;
typedef _Atomic(uint_least16_t)     atomic_uint_least16_t;
typedef _Atomic(int_least32_t)      atomic_int_least32_t;
typedef _Atomic(uint_least32_t)     atomic_uint_least32_t;
typedef _Atomic(int_least64_t)      atomic_int_least64_t;
typedef _Atomic(uint_least64_t)     atomic_uint_least64_t;
typedef _Atomic(int_fast8_t)        atomic_int_fast8_t;
typedef _Atomic(uint_fast8_t)       atomic_uint_fast8_t;
typedef _Atomic(int_fast16_t)       atomic_int_fast16_t;
typedef _Atomic(uint_fast16_t)      atomic_uint_fast16_t;
typedef _Atomic(int_fast32_t)       atomic_int_fast32_t;
typedef _Atomic(uint_fast32_t)      atomic_uint_fast32_t;
typedef _Atomic(int_fast64_t)       atomic_int_fast64_t;
typedef _Atomic(uint_fast64_t)      atomic_uint_fast64_t;
typedef _Atomic(intptr_t)           atomic_intptr_t;
typedef _Atomic(uintptr_t)          atomic_uintptr_t;
typedef _Atomic(size_t)             atomic_size_t;
typedef _Atomic(ptrdiff_t)          atomic_ptrdiff_t;
typedef _Atomic(intmax_t)           atomic_intmax_t;
typedef _Atomic(uintmax_t)          atomic_uintmax_t;

#define ATOMIC_BOOL_LOCK_FREE __atomic_always_lock_free(sizeof(bool), 0)
#define ATOMIC_CHAR_LOCK_FREE __atomic_always_lock_free(sizeof(char), 0)
// Support is not provided for CHAR8_t, CHAR16_t, or CHAR32_t
#define ATOMIC_WCHAR_T_LOCK_FREE __atomic_always_lock_free(sizeof(wchar_t), 0)
#define ATOMIC_SHORT_LOCK_FREE __atomic_always_lock_free(sizeof(short), 0)
#define ATOMIC_INT_LOCK_FREE __atomic_always_lock_free(sizeof(int), 0)
#define ATOMIC_LONG_LOCK_FREE __atomic_always_lock_free(sizeof(long), 0)
#define ATOMIC_LLONG_LOCK_FREE __atomic_always_lock_free(sizeof(long long), 0)
#define ATOMIC_POINTER_LOCK_FREE __atomic_always_lock_free(sizeof(uintptr_t), 0)

#define ATOMIC_FLAG_INIT {0}
typedef atomic_bool atomic_flag;

typedef enum {
    memory_order_relaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST
} memory_order;

#define atomic_init(obj, value) __c11_atomic_init(obj, value)
#define atomic_thread_fence(order) __c11_atomic_thread_fence(order)
#define atomic_signal_fence(order) __c11_atomic_signal_fence(order)
#define atomic_is_lock_free(obj) __c11_atomic_is_lock_free(obj)
#define atomic_store_explicit(obj, desired, order) __c11_atomic_store(obj, desired, order)
#define atomic_store(obj, desired) atomic_store_explicit(obj, desired, memory_order_seq_cst)
#define atomic_load_explicit(obj, order) __c11_atomic_load(obj, order)
#define atomic_load(obj) atomic_load_explicit(obj, memory_order_seq_cst)
#define atomic_exchange_explicit(obj, desired, order) __c11_atomic_exchange(obj, desired, order)
#define atomic_exchange(obj, desired) atomic_exchange_explicit(obj, desired, memory_order_seq_cst)
#define atomic_compare_exchange_strong_explicit(obj, expected, desired, sorder, forder) \
    __c11_atomic_compare_exchange_strong(obj, expected, desired, sorder, forder)
#define atomic_compare_exchange_strong(obj, expected, desired) \
    atomic_compare_exchange_strong_explicit(obj, expected, desired, memory_order_seq_cst, memory_order_seq_cst)
#define atomic_compare_exchange_weak_explicit(obj, expected, desired, soder, forder) \
    __c11_atomic_compare_exchange_weak(obj, expected, desired, soder, forder)
#define atomic_compare_exchange_weak(obj, expected, desired) \
    atomic_compare_exchange_weak_explicit(obj, expected, desired, memory_order_seq_cst, memory_order_seq_cst)
#define atomic_fetch_add_explicit(obj, operand, order) \
    __c11_atomic_fetch_add(obj, operand, order)
#define atomic_fetch_add(obj, operand) \
    atomic_fetch_add_explicit(obj, operand, memory_order_seq_cst)
#define atomic_fetch_sub_explicit(obj, operand, order) \
    __c11_atomic_fetch_sub(obj, operand, order)
#define atomic_fetch_sub(obj, operand) \
    atomic_fetch_sub(obj, operand, memory_order_seq_cst)
#define atomic_fetch_or_explicit(obj, operand, order) \
    __c11_atomic_fetch_or(obj, operand, order)
#define atomic_fetch_or(obj, operand) \
    atomic_fetch_or_explicit(obj, operand, memory_order_seq_cst)
#define atomic_fetch_xor_explicit(obj, operand, order) \
    __c11_atomic_fetch_xor(obj, operand, order)
#define atomic_fetch_xor(obj, operand) \
    atomic_fetch_xor_explicit(obj, operand, memory_order_seq_cst)
#define atomic_fetch_and_explicit(obj, operand, order) \
    __c11_atomic_fetch_and(obj, operand, order)
#define atomic_fetch_and(obj, operand) \
    atomic_fetch_and_explicit(obj, operand, memory_order_seq_cst)
#define atomic_fetch_nand_explicit(obj, operand, order) \
    __c11_atomic_fetch_nand(obj, operand, order)
#define atomic_fetch_nand(obj, operand) \
    __c11_atomic_fetch_nand(obj, operand, memory_order_seq_cst)
#define atomic_fetch_min_explicit(obj, operand, order) \
    __c11_atomic_fetch_min(obj, operand, order)
#define atomic_fetch_min(obj, operand) \
    atomic_fetch_min_explicit(obj, operand, memory_order_seq_cst)
#define atomic_fetch_max_explicit(obj, operand, order) \
    __c11_atomic_fetch_max(obj, operand, order)
#define atomic_fetch_max(obj, operand) \
    atomic_fetch_max_explicit(obj, operand, memory_order_seq_cst)
#define atomic_flag_test_and_set_explicit(flag, order) atomic_exchange_explicit(flag, true, order)
#define atomic_flag_test_and_set(flag) atomic_flag_test_and_set(flag, memory_order_seq_cst)
#define atomic_flag_clear_explicit(flag, order) atomic_store_explicit(flag, false, order)
#define atomic_flag_clear(flag) atomic_flag_clear_explicit(flag, memory_order_seq_cst)


static uint64_t kill_dependency(uint64_t x) {
    __asm__ volatile ("" : "+r" (x));
    return x;
}


#endif //STDATOMIC_H
