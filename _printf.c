#include "main.h"
/**
 *_printf: a print function.
 *@format: a parameter.
 *Description _printf: a function that returns no of chars.
 *return: return size of input.
 */

int _printf(const char* format, ...)
{
	const char types[] = "cs";
	char* s;
	char p;
	int i = 0,tot = 0;
	va_list ap;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i + 1])
			{
			case 'c':
				p = va_arg(ap, int);
				_putchar(p);
				sum++;
				break;
			case 's':
				s = va_arg(ap, char*);
				while (!s)
				{
					_putchar(s);
					s++;
					sum++;
				}
				break;
			}
		}
		else
		{
			p = format[i];
			_putchar(p);
			sum++;
		}
		i++;
	}
	return (sum);
}

