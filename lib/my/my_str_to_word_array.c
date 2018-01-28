

/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** 
*/
#include <stdlib.h>
int my_strlen(char *str);

int my_spe(char *str)
{
	int i = 0;
	int to_return = 0;
	while (str[i]) {
		if (str[i] == ' ')
			to_return++;
		i++;
	}
	to_return++;
	return to_return;
}

int alpha(char c)
{
	if (64 < c < 91 && 96 < c < 123)
		return 0;
	else
		return 1;
}

char	**my_str_to_word_array(char *str)
{
	int counter = 0;
	int max;
	int x = counter;
	int w = 0;
	int z = 0;
	max = my_spe(str);
	char **array = (char**) malloc(sizeof(char*) * max);
	for (int p = 0; p < max; p++) {
		array[p] = (char*) malloc(sizeof(char*) * p * my_strlen(str));
	}
	while (str[x]) {
		w = 0;
		while (str[x] == ' ' || str[x] == '\t' || str[x] == 10)
			x++;
		while (str[x] != 0 && str[x] != ' ' && str[x] != 10 && str[x] != '\t') {
			array[z][w] = str[x];
			w++;
			x++;
		}
		z++;
	}
	return (array);
}
