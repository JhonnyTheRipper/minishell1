/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-21 11:10:23
*/
#include <list.h>
#include <stdio.h>
#include <stdlib.h>

int my_strncm(char *str, char *find, int n)
{
	int i = 0;
	int m = 0;
	while (i <= n) {
		if (str[i] == find[i])
			m++;
		i++;
	}
	if (m == n)
		return 0;
	else
		return 1;
}

char *spe_cat(char *src, char *src3)
{
	char *res = malloc(sizeof(char) + my_strlen(src) + my_strlen(src3) + 5);
	int i = 0;
	int d = 0;
	while (src[i]) {
		res[d++] = src[i++];
	}
	i = 0;
	res[d++] = '=';
	while (src3[i])
		res[d++] = src3[i++];
	return res;

}

void my_setenv(char *name, char *param, env **head)
{
	env *he = *head;
	char *temp = malloc(sizeof(char) + my_strlen(name) + my_strlen(param) + 5);
	while (he->next != NULL) {
		if (my_strncm(name, he->line, my_strlen(name)) == 0)
			break;
		he = he->next;
	}
	if (he->next == NULL) {
		temp = spe_cat(name, param);
		env *tmp = (env*) malloc(sizeof(env));
		tmp->line = temp;
		tmp->next = (*head);
		(*head) = tmp;
	}
	else {
		temp = spe_cat(name, param);
		he->line = replace(temp);
	}
}

void destroy_list(env **head)
{
	env *prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free (prev);
	}
	free (*head);
}