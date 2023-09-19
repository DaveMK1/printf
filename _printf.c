#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{       
        int count = 0;
        
        va_list args;
        
        if (format == NULL)
                return (-1);
        
        va_start(args, format);
        
        for (int i = 0; format[i] != '\0'; i++)
        {       
                if (format[i] == '%')
                {       
                        i++;
                        if (format[i] == 'c')
                        {       
                                char c = va_arg(args, int);
                                write(1, &c, 1);
                                count++;
                        }       
                        else if (format[i] == 's')
                        {       
                                char *str = va_arg(args, char *);
                                int j = 0;
                                while (str[j] != '\0')
                                {       
                                        write(1, &str[j], 1);
                                        count++;
                                        j++;
                                }       
                        }       
                        else if (format[i] == '%')
                        {       
                                write(1, "%", 1);
                                count++;
                        }       
                }       
                else
                {       
                        write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return count;
}
