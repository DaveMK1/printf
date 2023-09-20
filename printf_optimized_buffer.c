#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += print_int(va_arg(args, int));
			else if (*format == 'u')
				count += print_unsigned_int(va_arg(args, unsigned int));
			else if (*format == 'o')
				count += print_octal(va_arg(args, unsigned int));
			else if (*format == 'x')
				count += print_hexadecimal(va_arg(args, unsigned int));
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'H';
	char *str = "Hello, World!";
	int integer = 42;
	unsigned int uinteger = 12345;

	_printf("%c\n", ch);
	_printf("%s\n", str);
	_printf("%d\n", integer);
	_printf("%u\n", uinteger);
	_printf("%o\n", uinteger);
	_printf("%x\n", uinteger);

	return (0);
}
