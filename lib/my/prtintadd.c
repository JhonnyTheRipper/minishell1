/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printadd
*/


#include <stdlib.h>
void	my_putchar(char c);
char	*my_revstr(char *str);
void	print_str(char *str);
int my_strlen(char const *str);

void	print_address(unsigned long long nb)
{
	print_str("Ox");
	char *res = malloc(sizeof(char) * 12);
	long i = 0;

	while (nb != 0) {
		if ((nb % 16) < 10) {
			res[i] = (nb % 16) + 48;
		} else {
			res[i] = (nb % 16) + 87;
		}
		i++;
		nb = nb / 16;
	}
	my_revstr(res);
	print_str(res);
}
