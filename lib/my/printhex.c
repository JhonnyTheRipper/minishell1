/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printhex
*/
//wololo
#include <stdlib.h>
void	my_putchar(char c);
char	*my_revstr(char *str);
void	print_str(char *str);
int my_strlen(char const *str);

void	print_hex(unsigned int nb, int mm)
{
        char *res = malloc(sizeof(char) * nb);
	int i = 0;
	
	if (mm == 1)
		mm = 55;
	if (nb == 0) {
		my_putchar('0');
	} else if (mm == 0){
		mm = 87;
	}
	while (nb != 0) {
		if ((nb % 16) < 10) {
			res[i] = (nb % 16) + 48;
		} else {
			res[i] = (nb % 16) + mm;
		}
		i++;
		nb = nb / 16;
	}
	my_revstr(res);
	print_str(res);
}
