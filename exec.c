/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-19 10:13:39
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int calculate(char **params)
{
	int i = 0;
	while (params[i]) {
		i++;
	}
	return i-1;
}

char **print(char **av)
{
	char **params = my_str_to_word_array(av[1]);
	int nb = calculate(params);
	int pid = getpid();
	return params;
}

int exec(char **params, char **ev)
{
	int pid;
	int status;
	int es;
	pid = fork();
	if (pid != 0) {
		waitpid(pid, &status, 0);
		if ( WIFEXITED(status) ) {
	}
	}
	else {
		char *path = malloc(sizeof(char) * my_strlen(params[0]) + 5);
		if (params[0][0] == '.' && params[0][1] == '/')
			path = params[0];
		else if (params[0][0] == '/') {
			path = params[0];
		}
		else {
			path = my_strcat(path, "/bin/");
			path = my_strcat(path, params[0]);
		}
		execve(path, params, ev);
	}
	return 0;
}