/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-20 13:55:54
*/
#include <list.h>

void print_ll(env **head) 
{
	env *he = *head;
	while (he) {
		my_printf("%s\n", he->line);
		he = he->next;
	}
}