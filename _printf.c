#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list args;

	va_start(args, format);

	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	int printed_chars = 0;

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			int printed = handle_format_specifier(format, &i, args, buffer);

			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: The character buffer
 * @buff_ind: The current index in the buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}

