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
void  print_oct(unsigned int nb, char *base);
void  print_hex(unsigned int nb, char *base, int mm);
void  print_str(char *str);
int my_strlen(char const *str);
void my_printf(const char *format, ...);
void print_exp(int nb, int mm);
void sorter(char *format, int strcounter, va_list list);
void  print_special_str(char *str);
void  print_bin(unsigned int nb, char *base);

void  my_putchar(char c)
{
  write(1, &c, 1);
}

int flag_counter(const char *format)
{
	int counter = 0;
	int toreturn = 0;

	while (format[counter] != '\0') {
		if (format[counter] == 37) {
			toreturn++;
		}
		counter++;
	}
	return (toreturn);
}

void my_printf(const char *format, ...)
{
	int strcounter = 0;
	int nb = flag_counter(format);
	va_list list;
	va_start(list, nb);
	sorter(format, strcounter, list);
}
