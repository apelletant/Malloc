/*
** EPITECH PROJECT, 2018
** main test
** File description:
** test main for the malloc library
*/

#include <unistd.h>

#include <string.h>
#include <string.h>
#include "include/malloc.h"

int main()
{
	int *tab = NULL;
	char *str = NULL;
	char *str2 = NULL;

	tab = malloc(sizeof(int) * 10);
	str = malloc(sizeof(char *) * 5);
	str2 = malloc(sizeof(char *) * 5);
	str2 = realloc(str2, 15);
	show_alloc_mem();
	free(tab);
	free(str);
	return (0);
}
