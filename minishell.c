/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-24 10:12:14
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <include/my.h>
#include <string.h>
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

int spe_strcmp(char *to_com, char *str)
{
	int i = 0;
	int m = 0;
	while (str[i]) {
		if (to_com[i] == str[i])
			m++;
		i++;
	}
	if (m == my_strlen(to_com))
		return 0;
	else return 1;
}

int parse(char *com)
{
	if (my_strcmp(com, "cd") == 0) {
		return 1;
	}
	if (spe_strcmp(com, "setenv") == 0) {
		return 2;
	}
	if (spe_strcmp(com, "unsetenv") == 0) {
		return 3;
	}
	if (my_strcmp(com, "env") == 0) {
		return 4;
	}
	if (my_strcmp(com, "printenv") == 0) {
		return 4;
	}
	else return 5;
}

char *shatp(char *str, env **head)
{
	if (str[0] == 0 || str[0] != '-')
		return str;
	char cwd[1024];
	env *he = *head;
	char *res;
	while (he->line[0] != 'O' && he->line[1] != 'L') {
		he = he->next;
	}
	res = copy(he->line);
	getcwd(cwd, sizeof(cwd));
	char *temp = malloc(sizeof(char) * my_strlen(cwd) + 9);
	temp = my_strcat(temp, "OLDPWD=");
	temp = my_strcat(temp, cwd);
	he->line = replace(temp);
	free (temp);
	return res;
}

void stuff(char *comands, char **ev, env **head)
{
	char **coms = my_str_to_word_array(comands);
	int ret;
	char *dir;
	switch(parse(coms[0])) {
		case 1:
			dir = shatp(coms[1], head);
			if (ret = chdir(dir) != 0)
				my_printf("%s: %s\n",dir, strerror(errno));
				break;
		case 2:
			my_setenv(coms[1], coms[2], head);
			break;
		case 3:
			my_unsetenv(coms[1], head);
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
	int i = get_size(ev);
	env* head = NULL;
	arr_to_list(&head, ev, i);
	while (1) {
		my_printf(YELLOW"[username@userprofile] $> "RESET);
		getline(&buffer, &size, stdin);
		if (my_strcmp(buffer, "exit\n") == 0)
			break;
		else
			stuff(buffer, ev, &head);
	}
	destroy_list(&head);
	ev = temp;
	return 0;
}