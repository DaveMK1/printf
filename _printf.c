#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: The variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c')
				count += print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(va_arg(args, int));
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
