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
		return (-1);

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
				if (format[1] == 'b')
				{
					unsigned int n = va_arg(argl, unsigned int);
					char _str[32];
					int len = 0;
					int i;

					for (i = 31; i >= 0; i--)
					{
						_str[len++] = (n & (1 << i)) ? '1' : '0';
					}
					write(1, _str, len);
					nxter += len;

					format++;
				}
				else
				{
					char *ptr = va_arg(argl, char *);
					int strlen_ = 0;

					while (ptr[strlen_] != '\0')
						strlen_++;

					write(1, ptr, strlen_);
					nxter += strlen_;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(argl, int);
				char num_str[12];
				int len = sprintf(num_str, "%d", num);

				write(1, num_str, len);
				nxter += len;
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(argl, unsigned int);
				char num_str[12];

				int len = sprintf(num_str, "%u", num);
				write(1, num_str, len);
				nxter += len;
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(argl, unsigned int);
				char num_str[12];

				int len = sprintf(num_str, "%o", num);
				write(1, num_str, len);
				nxter += len;
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(argl, unsigned int);
				char num_str[12];

				int len = sprintf(num_str, "%x", num);
				write(1, num_str, len);
				nxter += len;
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(argl, unsigned int);
			char num_str[12];

			int len = sprintf(num_str, "%X", num);
			write(1, num_str, len);
			nxter += len;
			}
		}
		format++;
	}

	va_end(argl);
	return (nxter);
}
