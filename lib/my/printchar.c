/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printchar
*/

#include <unistd.h>

void print_char(int c)
{
	write(1, &c, 1);
}
