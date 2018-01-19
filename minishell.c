/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-19 09:50:22
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <list.h>
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

char **my_setenv(char *name, char *value, char **ev)
{
	return ev;
}

char  **my_unsetenv(char *name, char **ev)
{
	return ev;
}

int parse(char *com)
{

	if (my_strcmp(com, "cd") == 0) {
		return 1;
	}
	if (my_strcmp(com, "setenv\n") == 0) {
		return 2;
	}
	if (my_strcmp(com, "unsetenv\n") == 0) {
		return 3;
	}
	if (my_strcmp(com, "env\n") == 0) {
		return 4;
	}
	else return 5;
}

void stuff(char *comands, char **ev)
{
	char **coms = my_str_to_word_array(comands);
	int ret;
	int i = get_size(ev);
	env *head = NULL;
	arr_to_list(&head, ev, i);
	switch(parse(coms[0])) {
		case 1:
			if (ret = chdir(coms[1]) != 0)
				my_printf("%s: No such file or directory\n", coms[0]);
			break;
		case 2:
			ev = my_setenv(coms[1], coms[2], ev);
			break;
		case 3:
			ev = my_unsetenv(coms[1], ev);
			break;
		case 4:
			print_ll(head);
			break;
		case 5:
			exec(coms, ev);
			break;
	}
}

int main(int ac, char **av, char **ev)
{
	char **temp = ev;
	char *buffer;
	size_t size = 0;
	while (1) {
		my_printf(YELLOW"[username@userprofile] $> "RESET);
		getline(&buffer, &size, stdin);
		if (my_strcmp(buffer, "exit\n") == 0)
			break;
		else
			stuff(buffer, ev);
	}
	ev = temp;
	return 0;
}