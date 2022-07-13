#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<unistd.h>
#include "main.h"

/**
 * _printf - print any formated string
 * @format: string format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count = 0, printed = 0;

	if (!format)
		return (-1);
	va_start(list, format);
	while (format && format[count])
	{
		if (format[count] == '%')
		{
			if (format[count + 1] == '\0')
				return (-1);
			format_values(list, format, &printed, &count);
		}
		else
		{
			_putchar(format[count]);
			printed += 1;
			count += 1;
		}
	}
	va_end(list);
	return (printed);
}
/**
 * format_values - format string
 * @list: list of args
 * @format: format string
 * @printed: number of chars printed
 * @count: count iterator
 * Return: pointer to func that correspond to operator
 */
void format_values(va_list list, const char *format, int *printed, int *count)
{
	int f = 0, tobi = 0, tooc = 0;
	unsigned int num = 0;

	switch (format[*count + 1])
	{
		case '%':
			_putchar(format[*count + 1]);
			*printed += 1;
			break;
		case 'c':
			_putchar(va_arg(list, int));
			*printed += 1;
			break;
		case 's':
			format_string(list, printed, 's');
			break;
		case 'd': case 'i':
			format_int(list, printed);
			break;
		case 'b':
			num = va_arg(list, unsigned int);
			tobi = _tobinoct(num, 0, 2);
			*printed  += tobi;
			break;
		default:
			*count += 1;
			*printed += 1;
			_putchar('%');
			f = 1;
	}
	if (!f)
		*count += 2;
}
/**
 * main - Entry point
 *
 * Return: Always -0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}

