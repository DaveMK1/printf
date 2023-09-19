#include "main.h"
#include <unistd.h>

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num / 10)
		count += print_int(args);

	char digit = num % 10 + '0';

	write(1, &digit, 1);
	return (count + 1);
}

