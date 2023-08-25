#include "main.h"
/**
 * _printf - Custom implementation of the printf function.
 * @format: The format string containing format specifiers.
 * @...: Variable number of arguments to be printed.
 *
 * Return: The total number of characters printed.
 *
 * Description: This function takes a format string with format specifiers and
 * a variable number of arguments. It processes the format specifiers and print
 * the formatted output, returning the total number of characters printed.
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */

int _printf(const char *format, ...)
{
	/* Array of conversion specifiers and their corresponding functions */
	convert_match m[] = {
		{"%c", printf_char},
		{"%s", printf_string},
		{"%%", printf_37},
		{"%i", printf_int},
		{"%d", printf_dec},
		{"%b", printf_bin},
		{"%u", printf_unsigned},
		{"%o", printf_oct},
		{"%x", printf_hex},
		{"%X", printf_HEX}
	};

	va_list args; /* Variable arguments list */
	int i = 0, j, len = 0; /* Iteration and length tracking variables */

	va_start(args, format); /* Initialize variable arguments list */

	/* Handle edge cases: NULL format or format only contains '%' */
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 5;
		while (j >= 0)
		{
			/*Check if the current format matches any specifier*/
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				/*Call the corresponding function and update length*/
				len += m[j].f(args);
				i = i + 2;
				goto Here; /* Jump to the beginning of the loop */
			}
			j--;
		}
		/*If no specifier match, print the character and update length*/
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
