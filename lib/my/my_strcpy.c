/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
**
*/
char	*my_strcpy(char *dest, char const *src)
{
	int i = 0;
	while(src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	while(dest[i] != '\0') {
		dest[i	] = '\0';
		i = i + 1 ;
	}
	return (dest);
}
