/*
**EPITECH PROJECT, 2017
**File description:
**my_printf()
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


void print_char(int c);
void print_dec(int nb);
void  print_decu(unsigned int nb);
void  print_oct(unsigned int nb);
void  print_hex(unsigned int nb, int mm);
void  print_str(char *str);
int my_strlen(char const *str);
void my_printf(const char *format, ...);
void print_exp(int nb, int mm);
void sorter(char *format, int strcounter, va_list list);
void  print_special_str(char *str);
void  print_bin(unsigned int nb);

void sorter(char *format, int strcounter, va_list list)
{
	for(; strcounter < my_strlen(format); strcounter++) {
		if (format[strcounter] == '%' && format[strcounter+1] == 's') {
			print_str(va_arg(list, char*));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'S') {
			print_special_str(va_arg(list, char*));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'd') {
			print_dec(va_arg(list, int));
			strcounter += 2;
			return (sorter(format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'i') {
			print_dec(va_arg(list, int));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'u') {
			print_decu(va_arg(list, int));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'o') {
			print_oct(va_arg(list, unsigned int));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'x') {
			print_hex(va_arg(list, unsigned int), 0);
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'X') {
			print_hex(va_arg(list, unsigned int), 0);
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == 'b') {
			print_bin(va_arg(list, unsigned int));
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == 92 && format[strcounter+1] == 'n') {
			my_putchar(10);
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		if (format[strcounter] == '%' && format[strcounter+1] == '%') {
			my_putchar('%');
			strcounter += 2;
			return (sorter (format, strcounter, list));
		}
		else {
			my_putchar(format[strcounter]);
		}
	}
}
