#include "main.h"
/**
 * printf_S - Prints a string, replacing non-printable characters with hex escape codes
 * @val: The va_list containing the string to be printed
 * Return: The number of characters printed
 *
 * Author: MedAMEZZANE & Abdelouahed OUARRAR
 */
int printf_S(va_list val)
{
  char *str;
  int i, len = 0;
  int c;

  str = va_arg(val, char *);
  if (str == NULL)
    str = "(null)";

  /* Loop through the characters in the string */
  for (i = 0; str[i] != '\0'; i++)
  {
    /* Check if the character is non-printable */
    if (str[i] < 32 || str[i] >= 127)
    {
      _putchar('\\');
      _putchar('x');
      len += 2;
      c = str[i];

      /* Add leading zero if necessary */
      if (c < 16)
      {
        _putchar('0');
        len++;
      }

      /* Call helper function to print the hexadecimal value */
      len += printf_HEX_INT(c);
    }
    else
    {
      _putchar(str[i]);
      len++;
    }
  }
  return (len); /*Return the number of characters printed*/
}
