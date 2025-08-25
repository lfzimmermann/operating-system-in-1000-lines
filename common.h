#pragma once

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

void putchar(char ch);
void mini_printf(const char *format, ...);
void print_int(va_list vargs);
void print_string(va_list vargs);
