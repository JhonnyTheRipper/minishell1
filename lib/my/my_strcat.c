/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>

int	my_strlen(char const *str);
char	*my_strcat(char *dest, char const *src)
{
	int counter = my_strlen(dest);
	int x = 0;
	int i = 0;
	int max = my_strlen(dest);
	int z = 0;
	char *res = malloc(sizeof(char)* my_strlen(src) + my_strlen(dest) + 2);
	while (src[i]) {
		dest[counter] = src[i];
		i ++;
		counter ++;
	}
	return dest;
}
