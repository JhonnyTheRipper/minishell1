/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Vladnm
** @Last Modified time: 2017-11-10 10:19:37
*/
int my_put_nbr(int nb);
void	my_putchar(char c);

int intsize(int nb)
{
	if (nb > 1000000000)
		return 10;
	if (nb > 100000000)
		return 9;
	if (nb > 10000000)
		return 8;
	if (nb > 1000000)
		return 7;
	if (nb > 100000)
		return 6;
	if (nb > 10000)
		return 5;
	if (nb > 1000)
		return 4;
	if (nb > 100)
		return 3;
	if (nb > 10)
		return 2;
	if (nb > 1)
		return 1;
	return 0;
}

int my_compute_power_rec(int nb, int p)
{
	int resultat;

	if (p == 0) {
		return (1);
	}
	if (p < 0) {
		return (0);
	}
	resultat = nb * my_compute_power_rec(nb, p - 1);
	return (resultat);
}

void print_exp(int nb, int mm)
{
	int size;
	int pow;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb == 0)
		my_putchar('0');
	else {
		size = intsize(nb);
		pow = my_compute_power_rec(10, size) / 10;
		my_put_nbr(nb/pow);
		my_putchar('.');
		my_put_nbr(nb % pow);
		if (mm == 0)
			my_putchar('e');
		else
			my_putchar('E');
		my_put_nbr(size-1);
	}
}
