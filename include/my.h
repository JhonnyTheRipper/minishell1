#ifndef STRUCT_H
#define STRUCT_H
#include <stdarg.h>
#include <stdio.h>
typedef struct env {
	char *line;
	struct env *next;
} env;
int spe_strcmp(char *to_com, char *str);
int my_strlen(char *str);
void my_printf(const char *format, ...);
char *my_strcat(char *dest, char *src);
int parse(char *com);
char *shatp(char *str, env **head);
void stuff(char *comands, char **ev, env **head);
int main(int ac, char **av, char **ev);
char *check(char *params);
int calculate(char **params);
int exec(char **params, char **ev);
char *copy(char *line);
char *replace(char *src);
int special_comp(char *name, char *where);
void my_unsetenv(char *name, env **head);
int my_strcmp(char *s1, char *s2);
char	**my_str_to_word_array(char *str);
int get_size(char **ev);
int my_strncm(char *str, char *find, int n);
char *spe_cat(char *src, char *src3);
void my_setenv(char *name, char *param, env **head);
void destroy_list(env **head);
env *get_nth(env* head, int n);
void push(env **head, char *str);
void pop(env **head);
void delete_nth(env **head, int n);
void arr_to_list(env **head, char **arr, size_t size);
void print_ll(env **head);
#endif