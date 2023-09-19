#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

/**
 * struct FormatSpec - Structure to represent a format specifier
 * @specifier: The format specifier character
 * @func: A function pointer to the corresponding print function
 */
typedef struct FormatSpec
{
    char specifier;
    int (*func)(va_list, char *, int, int, int, int);
} FormatSpec;

/**
 * struct Flags - Structure to represent format flags
 * @minus: Minus flag
 * @plus: Plus flag
 * @zero: Zero flag
 * @hash: Hash flag
 * @space: Space flag
 */
typedef struct Flags
{
    unsigned int minus : 1;
    unsigned int plus : 1;
    unsigned int zero : 1;
    unsigned int hash : 1;
    unsigned int space : 1;
} Flags;

/**
 * struct FormatData - Structure to hold format data
 * @flags: Format flags
 * @width: Field width
 * @precision: Precision specifier
 * @size: Size specifier
 */
typedef struct FormatData
{
    Flags flags;
    int width;
    int precision;
    int size;
} FormatData;

int _printf(const char *format, ...);

/* Print functions for different specifiers */
int print_char(va_list args, char *buffer, FormatData format);
int print_string(va_list args, char *buffer, FormatData format);
int print_percent(va_list args, char *buffer, FormatData format);
int print_integer(va_list args, char *buffer, FormatData format);
int print_unsigned(va_list args, char *buffer, FormatData format);
int print_binary(va_list args, char *buffer, FormatData format);
int print_octal(va_list args, char *buffer, FormatData format);
int print_hexadecimal(va_list args, char *buffer, FormatData format);
int print_pointer(va_list args, char *buffer, FormatData format);
int print_reverse(va_list args, char *buffer, FormatData format);
int print_rot13(va_list args, char *buffer, FormatData format);

#endif /* PRINTF_H */

