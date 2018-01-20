/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-19 15:29:29
*/
#include <list.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

env *get_nth(env* head, int n)
{
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter ++;
	}
	return head;
}

void push(env **head, char *str)
{
	env *tmp = (env*) malloc(sizeof(env));
	tmp->line = str;
	tmp->next = (*head);
	(*head) = tmp;
}

void pop(env **head)
{
	env* prev = NULL;
	if (head == NULL)
		return;
	prev = (*head);
	(*head) = (*head)->next;
	free (prev);
}

void delete_nth(env **head, int n)
{
	if (n == 0)
		return;
	else {
		env *prev = get_nth(*head, n-1);
		env *elm = prev->next;
		prev->next = elm->next;
		free (elm);
	}
}

void arr_to_list(env **head, char **arr, size_t size)
{
	size_t i = size - 1;
	if (arr == NULL || size == 0)
		return;
	do {
		push (head, arr[i]);
	} while (i-- != 0);
}
