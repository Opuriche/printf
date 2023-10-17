#include "main.h"

/**
 * _printf - printf function
 * @format: the format
 * Return: the output
 */

int _printf(const char *format, ...)
{
	int nxter = 0;
	va_list argl;

	if (format == NULL)
		return -1;

	va_start(argl, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			nxter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				nxter++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(argl, int);

				write(1, &c, 1);
				nxter++;
			}
			else if (*format == 's')
			{
				char *ptr = va_arg(argl, char *);
				int strlen_ = 0;

				while (ptr[strlen_] != '\0')
					strlen_++;

				write(1, ptr, strlen_);
				nxter += strlen_;
			}
		}
		format++;
	}

	va_end(argl);
	return (nxter);
}
