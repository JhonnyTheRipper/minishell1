/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printstr
*/


int my_strlen(char const *str);
void	my_putchar(char c);
void	print_str(char *str)
{
	int max = my_strlen(str);
	int i = 0;
	while (i < max)
	{
		my_putchar(str[i]);
		i++;
	}
}
