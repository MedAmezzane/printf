#include "main.h"

/**
 * printf_unsigned - Prints an unsigned integer
 * @args: The va_list containing the unsigned integer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last = n % 10, digit, exp = 1;
	int chars_printed = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');  /*Print a negative sign*/
		num = -num;
		n = -n;
		last = -last;
		chars_printed++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0'); /*Print each digit*/
			num = num - (digit * exp);
			exp = exp / 10;
			chars_printed++;
		}
	}
	_putchar(last + '0'); /*Print the last digit*/

	return (chars_printed); /*Return the number of characters printed*/
}

/**
 * printf_oct - Prints an unsigned integer as an octal number
 * @val: The va_list containing the unsigned integer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_oct(va_list val)
{
	int i;
	int *octal_digits;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	/* Calculate the number of octal digits in the number */
	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;

	/* Allocate memory for the array to store octal digits */
	octal_digits = malloc(counter * sizeof(int));

	/* Extract and store octal digits in the array */
	for (i = 0; i < counter; i++)
	{
		octal_digits[i] = temp % 8;
		temp /= 8;
	}

	/* Print octal digits in reverse order */
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(octal_digits[i] + '0'); /*Print each octal digit*/
	}

	free(octal_digits); /*Free the allocated memory*/
	return (counter); /*Return the number of characters printed*/
}

/**
 * printf_hex - Prints an unsigned integer as a hexadecimal number
 * @val: The va_list containing the unsigned integer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_hex(va_list val)
{
	int i;
	int *hex_digits;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	/* Calculate the number of hexadecimal digits in the number */
	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;

	/* Allocate memory for the array to store hexadecimal digits */
	hex_digits = malloc(counter * sizeof(int));

	/* Extract and store hexadecimal digits in the array */
	for (i = 0; i < counter; i++)
	{
		hex_digits[i] = temp % 16;
		temp /= 16;
	}

	/* Print hexadecimal digits in reverse order */
	for (i = counter - 1; i >= 0; i--)
	{
		if (hex_digits[i] > 9)
			hex_digits[i] = hex_digits[i] + 39; /*Convert to ASCII for A-F*/
		_putchar(hex_digits[i] + '0'); /*Print each hexadecimal digit*/
	}

	free(hex_digits); /*Free the allocated memory*/
	return (counter); /*Return the number of characters printed*/
}

/**
 * printf_HEX - Prints an unsigned integer as a hexadecimal number in uppercase
 * @val: The va_list containing the unsigned integer to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_HEX(va_list val)
{
	int i;
	int *hex_digits;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	/* Calculate the number of hexadecimal digits in the number */
	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;

	/* Allocate memory for the array to store hexadecimal digits */
	hex_digits = malloc(counter * sizeof(int));

	/* Extract and store hexadecimal digits in the array */
	for (i = 0; i < counter; i++)
	{
		hex_digits[i] = temp % 16;
		temp /= 16;
	}

	/* Print hexadecimal digits in reverse order */
	for (i = counter - 1; i >= 0; i--)
	{
		if (hex_digits[i] > 9)
			hex_digits[i] = hex_digits[i] + 7; /*Convert to ASCII for A-F*/
		_putchar(hex_digits[i] + '0'); /*Print each hexadecimal digit*/
	}

	free(hex_digits); /*Free the allocated memory*/
	return (counter); /*Return the number of characters printed*/
}
