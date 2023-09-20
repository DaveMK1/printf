#include "main.h"

/**
 * print_reverse - Print a string in reverse
 * @args: The va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	int length = 0;

	while (str[length] != '\0')
		length++;

	for (int i = length - 1; i >= 0; i--)
	{
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
