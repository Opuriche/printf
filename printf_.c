#include "main.h"

/**
 * _printf - Custom printf function
 * @format: the format string
 * Return: the number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			put_char(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				put_char(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				while (*s)
				{
					put_char(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				put_char('%');
				count++;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
