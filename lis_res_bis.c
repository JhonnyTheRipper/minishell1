/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-17 10:10:55
*/
#include <list.h>

void print_ll(const env *head) {
	while (head) {
		my_printf("%s\n", head->line);
		head = head->next;
	}
}