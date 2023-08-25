#include "main.h"

/**
 * printf_bin - Prints the binary representation of an unsigned integer.
 * @val: A va_list containing the argument to print.
 *
 * Return: The number of characters printed.
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_bin(va_list val)
{
	int f = 0;
	int c = 0;
	int i, j = 1, k;
	unsigned int n = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((j << (31 - i)) & n);
		if (p >> (31 - i))
			f = 1;
		if (f)
		{
			k = p >> (31 - i);
			_putchar(k + 48);
			c++;
		}
	}
	if (c == 0)
	{
		c++;
		_putchar('0');
	}
	return (c);
}