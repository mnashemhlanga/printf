#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
void format_values(va_list list, const char *format, int *printed, int *count)
void format_int(va_list list, int *printed)
void format_string(va_list list, int *printed, char sr)
#endif
