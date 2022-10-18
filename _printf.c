#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int f = 0, w = 0, p = 0, s = 0, ii = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[ii++] = format[i];
			if (ii == BUFF_SIZE)
				print_buffer(buffer, &ii);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &ii);
			/*f = get_flags(format, &i);
			w = get_width(format, &i, ap);
			p = get_precision(format, &i, ap);
			s = get_size(format, &i);*/
			++i;
			printed = handle_print(format, &i, ap, buffer,
				f, w, p, s);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &ii);
	va_end(ap);
	return (printed_chars);
}
