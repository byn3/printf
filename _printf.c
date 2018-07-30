#include "holberton.h"
#include <stdio.h>
//#define BUFF_SIZE 1024

/**
* _printf - our own printf function
* @format: A character string, composed of zero of more directives
*
* Description: Writes a formatted string to the standard output
* Return: an integer. The number of characters printed excluding the null byte
*/

int _printf(const char *format, ...)
{
	va_list argu;
	int i = 0, count = 0;
	char *s;

	//buffer = malloc(BUFF_SIZE);
	//if (!buffer)
	//	return (-1);
/* need to check if % is given and next character isn't one of the interpreted cases */
/* should give error */

	va_start(argu, format);
	while (format && format[i])
	{
		if(*(format + i) == '%' && (format[i + 1]))
		{
			switch (format[i + 1])
			{
				i++;	
				case 'c':
					_putchar(va_arg(argu, int));
					i++;
					count++;
					break;
				case 'i':
					print_number(va_arg(argu, int));
					i++;
					count++;
					break;
				case 'f':
					printf("%f", (float) va_arg(argu, double));
					break;
				case 's':
					s = va_arg(argu,  char *);
					if (s == NULL)
					{
						printf("(nil)");
						break;
					}
					write(1, s, _strlen(s));
					i++;
					count += _strlen(s);
					break;
				case 'd':
					print_number(va_arg(argu, int));
					i++;
					count++;
					break;
				case '%':
/* counts one too many times, should count only one % */
					write(1, &format[i + 1], 1);
					i++;
					break;
				case 'b':
					break;
//				default:
/* what do to if error occurs? */
			//		printf("error\n");
			//		return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(argu);
	_putchar('\n');
	printf("number of characters printed: %i\n", count);
	return (0);
}
int main(void)
{
	printf("string: %s\n", "hello");
	_printf("string: %s\n", "hello");
        printf("char: %c\n", 'h');
        _printf("char: %c\n", 'h');
        printf("int: %i\n", 45);
        _printf("int: %i\n", 45);
        printf("deci: %d\n", 33);
        _printf("deci: %d\n", 33);
        printf("%i + %i = %i\n", 3, 5, 3 + 5);
        _printf("%i + %i = %i\n", 3, 5, 3 + 5);
	printf("two mod: %%\n");
	_printf("two mod: %%\n");
}
