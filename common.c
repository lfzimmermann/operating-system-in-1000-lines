#include "common.h"

void mini_printf(const char *format, ...) {
  va_list vargs;

  va_start(vargs, format); // start va_list after arguments 'format'

  // TODO: error handling
  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
      case '\0':
        putchar('%');
        goto end;

      case '%':
        putchar('%');
        break;

      case 's':
        print_string(vargs);
        break;

      case 'd':
        print_int(vargs);
        break;

      case 'x':
        unsigned int value = va_arg(vargs, unsigned int);
        putchar('0');
        putchar('x');
        for (int i = 7; i >= 0; i--) {
          unsigned nybble = (value >> (i * 4)) & 0xf;
          putchar("0123456789abcdef"[nybble]);
        }
        break;
      }
    } else {
      putchar(*format);
    }
    format++;
  }

end:
  va_end(vargs);
}

void print_string(va_list vargs) {
  const char *s =
      va_arg(vargs, const char *); // fetch next argument as 'const char *'
  while (*s) {
    putchar(*s);
    s++;
  }
}

void print_int(va_list vargs) {
  int value = va_arg(vargs, int);
  if (value < 0) {
    putchar('-');
    value = -value;
  }
  unsigned int divisor = 1;

  while ((int)(value / divisor) > 9) {
    divisor *= 10;
  }

  while (divisor > 0) {
    putchar('0' + value / divisor);
    value %= divisor;
    divisor /= 10;
  }
}
