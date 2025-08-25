#ifndef COMMON_H_DEF
#define COMMON_H_DEF

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

#define true 1
#define false 0
#define NULL ((void *)0)
#define align_up(value, align) __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
#define offsetof(type, member) __builtin_offsetof(type, member)

void putchar(char ch);
void mini_printf(const char *format, ...);
void print_int(va_list *vargs);
void print_string(va_list *vargs);
void print_hex(va_list *vargs);

void boot(void);
void kernel_main(void);

void *memset(void *buf, char c, size_t n);

#endif
