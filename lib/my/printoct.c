/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printhex
*/


#include <stdlib.h>
void	my_putchar(char c);
void	print_str(char *str);
int my_strlen(char const *str)
{
	int i = 0;
	while (str[i] != '\0') {
		i = i + 1;
	}
	return i;
	
}

void	*my_revstr(char *str)
{
	int i = 0;
	int x = 0;
	int j;
	while (str[i] != '\0') {
		i = i + 1;
	}
	j = i;
	i = i - 1;
	char rts[j];
	for (; x <= j; x = x + 1) {
		rts[x] = str[i];
		i = i - 1;
	}
	x = 0;
	for (; x <= j; x = x + 1) {
		str[x] = rts[x];
	}
	return (0);
}

void	print_oct(unsigned int nb)
{
	char *res = malloc(sizeof(char) * nb);
	int i = 0;
	

	if (nb == 0)
		my_putchar(0);
	while (nb != 0) {
		res[i] = (nb % 8) + 48;
		i++;
		nb = nb / 8;
	}
	my_revstr(res);
	print_str(res);
}
