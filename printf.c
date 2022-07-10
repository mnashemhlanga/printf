#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<unistd.h>
#include "main.h"

/**
 * _printf - custom implementation of the printf function
 * @format: string containing the format specifiers
 * Return: length of printed string
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0;
	char *buff, *temp;

	buff = malloc(sizeof(char *) * strlen(format)), temp = malloc(20);
	va_start(ap, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						buff[j] = (char)va_arg(ap, int);
						j++;
						break;
					}
				case 's':
					{
						temp = va_arg(ap, char *);
						strcpy(&buff[j], temp);
						j += strlen(temp);
						break;
					}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(ap);
	return (j);
}
