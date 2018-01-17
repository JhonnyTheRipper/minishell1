/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printbin
*/

#include <stdlib.h>
void	print_str(char *str);
char	*my_revstr(char *str);
void	my_putchar(char c);
int	my_strlen(char const *str);

void	print_bin(unsigned int nb)
{
	char *res = malloc(sizeof(char) * nb);
	int i = 0;
	

	if (nb == 0)
		my_putchar(0);
	while (nb != 0) {
		res[i] = (nb % 2) + 48;
		i++;
		nb = nb / 2;
	}
	my_revstr(res);
	print_str(res);
}
