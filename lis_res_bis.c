/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-22 10:53:54
*/
#include <include/my.h>

void print_ll(env **head) 
{
	env *he = *head;
	while (he) {
		my_printf("%s\n", he->line);
		he = he->next;
	}
}

env* getLast(env *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}