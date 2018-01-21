

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
	
	for (x; x <= my_strlen(str); x++) {
		if (str[x] != '\n' && str[x] != ' ') {
			array[z][w] = str[x];
			w++;
		}
		 else if (z < max) {
				z++;
				w = 0;
		}
		if (z == max)
			break;
	}
	return (array);
	free(array);
}
