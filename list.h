#ifndef STRUCT_H
#define STRUCT_H

typedef struct env {
	char *line;
	struct env *next;
} env;

#endif