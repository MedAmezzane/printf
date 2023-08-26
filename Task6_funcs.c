#include "main.h"
#include <stdint.h>
/**
 * printf_adress - Prints the hexadecimal representation of a pointer
 * @val: The va_list containing the pointer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_adress(va_list val)
{
int printed_chars = 0;
uintptr_t ptr;
int shift;
int seen_nonzero = 0;

	void *addr = va_arg(val, void *);

	if (addr == NULL)
	{
		printed_chars += _putchar('(');
		printed_chars += _putchar('n');
		printed_chars += _putchar('i');
		printed_chars += _putchar('l');
		printed_chars += _putchar(')');

		return (5);
	}

	printed_chars += _putchar('0');
	printed_chars += _putchar('x');
	ptr = (uintptr_t)addr;
	shift = (sizeof(uintptr_t) * 8) - 4;
	while (shift >= 0)
	{
		int digit = (ptr >> shift) & 0xF;

		if (digit != 0 || seen_nonzero)
		{
			printed_chars += _putchar("0123456789abcdef"[digit]);
			seen_nonzero = 1;
		}
		shift -= 4;
	}
return (printed_chars);
}

