#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


/**
 * struct format - A structure representing a format specifier and its
 * corresponding conversion function.
 * @id: The format specifier string.
 * @f: Pointer to the conversion function associated with the format
 * specifier.
 *
 * Description: This structure associates a format specifier (such as "%s",
 * "%c", etc.) with a function pointer that performs the conversion and
 * printing for that format specifier.
 */
typedef struct format
{
	char *id;         /* Format specifier string */
	int (*f)();       /* Pointer to conversion function */
} convert_match;




int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int printf_char(va_list val);
int printf_string(va_list val);
int printf_37(void);
int printf_int(va_list args);
int printf_dec(va_list args);

#endif
