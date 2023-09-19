#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print_func - Struct for conversion specifiers and their functions
 * @specifier: Conversion specifier
 * @func: Corresponding function
 */

typedef struct print_func
{
    char *specifier;
    int (*func)(va_list);
} print_func_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_plus(va_list args);
int print_space(va_list args);
int print_hash(va_list args);
int print_long(va_list args);
int print_short(va_list args);
int print_decimal(va_list args);
int print_unsigned_decimal(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_width(va_list args);
int print_precision(va_list args);
int print_zero_flag(va_list args);
int print_minus_flag(va_list args);
int print_reversed_string(va_list args);
int print_rot13_string(va_list args);

#endif /* MAIN_H */
