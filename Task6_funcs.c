#include "main.h"
/**
 * printf_adress - Prints the hexadecimal representation of a pointer
 * @val: The va_list containing the pointer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_adress(va_list val)
{
	void *ptr;
	char *nil_str = "(nil)";
	long int ptr_value;
	int num_printed_chars;
	int i;

	ptr = va_arg(val, void *);

	if (ptr == NULL)
	{
		for (i = 0; nil_str[i] != '\0'; i++)
		{
			_putchar(nil_str[i]);
		}
		return (i); /*Return the number of characters printed*/
	}

	ptr_value = (unsigned long int)ptr;

	_putchar('0');
	_putchar('x');

	/*Print the hexadecimal value of the pointer*/
	num_printed_chars = printf_HEX_INT(ptr_value);

	/*Return the total number of characters printed*/
	return (num_printed_chars + 2);
}
