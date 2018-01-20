#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
typedef struct env {
	char *line;
	struct env *next;
} env;
/*int spe_strcmp(char *to_com, char *str);
int parse(char *com);
void stuff(char *comands, char **ev, env **head);
char *check(char *params);
int calculate(char **params);
int exec(char **params, char **ev);
int special_comp(char *name, char *where);
void my_setenv(char *name, char *param, env **head);
int get_size(char **ev);
env *get_nth(env* head, int n);
void push(env **head, char *str);
void pop(env **head);
void delete_nth(env **head, int n);
void arr_to_list(env **head, char **arr, size_t size);
void print_ll(const env *head);
*/
#endif