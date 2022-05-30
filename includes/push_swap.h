#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct node {
	char		*value;
	struct node *next;
} node;

int check_digit(int argc, char **argv);
int check_repeted(int argc, char **argv);
int check_args(int argc, char **argv);
int check_interger_limits(int argc, char **argv);

#endif