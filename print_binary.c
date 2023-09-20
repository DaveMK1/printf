#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_unsigned - Print an unsigned integer
 * @args: The va_list containing the unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		char digit = (num / divisor) + '0';

		write(1, &digit, 1);
		count++;
		num %= divisor;
		divisor /= 10;
	}
	return (count);
}
