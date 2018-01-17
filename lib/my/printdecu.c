/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printdecu
*/

void  my_putchar(char c);
int my_put_nbr(int nb);
void print_decu(unsigned int nb)
{
	unsigned int	mod;

	if (nb >= 10) {
		mod = (nb % 10);
		nb = (nb - mod) / 10;
		my_put_nbr(nb);
		my_putchar(48 + mod);
	} else
		my_putchar(48 + nb % 10);
}
