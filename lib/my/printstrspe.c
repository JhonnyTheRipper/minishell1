/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** prrintstrspe
*/


#include <stdlib.h>
void	print_soct(unsigned int nb);
char	*my_revstr(char *str);
int my_strlen(char const *str);
void	my_putchar(char c);
void	print_str(char *str);

void	print_special_str(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] == 127 ) {
			print_soct(str[i]);
			i++;
		}
		my_putchar(str[i]);
		i++;
	}
}

void	print_soct(unsigned int nb)
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
	my_putchar(92);
	if (my_strlen(res) == 3)
		print_str(res);
	if (my_strlen(res) == 2) {
		my_putchar('0');
		print_str(res);
	} else if (my_strlen(res) == 1) {
		my_putchar('0');
		my_putchar('0');
		print_str(res);
	}
}
