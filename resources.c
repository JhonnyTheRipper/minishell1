/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-20 13:47:26
*/
#include <list.h>
#include <stdio.h>

char *copy(char *line)
{
	char *res = malloc(sizeof(char) * my_strlen(line));
	int i = 0;
	int d = 0;
	while (line[i] != '/')
		i++;
	while (line[i]) {
		res[d] = line[i];
		d++;
		i++;
	}
	while (res[d]) {
		res[d] = 0;
		d++;
	}
	return res;
}

char *replace(char *dest, char *src)
{
	char *res = malloc(sizeof(char) * my_strlen(src));
	int i = 0;
	while (src[i]) {
		res[i] = src[i];
		i++;
	}
	return res;
}

int special_comp(char *name, char *where)
{
	int i = 0;
	int d = 0;
	while (where[i] != '=' && where[i] != 0) {
		if (where[i] == name[i])
			d++;
		i++;
	}
	if (d == my_strlen(name))
		return 1;
	return 0;
}

void my_setenv(char *name, char *param, env **head)
{
	printf("SE %s\n", name);
}

int my_unsetenv(char *name, const env **head)
{
	int i = 0;
	env *he = *head;
	while (he) {
		if (special_comp(name, he->line) == 1)
			break;
		i++;
		he = he->next;
	}
	if (he->next == NULL)
		return;

	env *prev = get_nth(*head, i-1);
	env *elm = prev->next;
	prev->next = elm->next;
	free (elm);
}

int get_size(char **ev)
{
	int i = 0;
	while (ev[i])
		i++;
	return i;
}