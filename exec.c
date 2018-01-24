/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-24 11:39:31
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <include/my.h>
#include <sys/wait.h>

char *check(char *params)
{
	char *res = malloc(sizeof(char) * my_strlen(params) + 5);
	if (params[0] == '.' && params[1] == '/')
			res = params;
	else if (params[0] == '/') {
		res = params;
	} else {
		res = my_strcat(res, "/bin/");
		res = my_strcat(res, params);
	}
	return res;
}


int calculate(char **params)
{
	int i = 0;
	while (params[i]) {
		i++;
	}
	return i-1;
}

int exec(char **params, char **ev)
{
	int pid;
	char *path;
	int status;
	pid = fork();
	if (pid != 0) {
		waitpid(pid, &status, 0);
		if ( WIFEXITED(status) ) {
	}
	}
	else {
		path = check(params[0]);
		if (access(path, 0))
			my_printf("%s: command not found\n",params[0]);
		execve(path, params, ev);
		exit(0);
	}
	return 0;
}