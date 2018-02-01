/*
** EPITECH PROJECT, 2018
** main test
** File description:
** test main for the malloc library
*/

#include "include/malloc.h"

int main()
{
	int *tab = NULL;
	char *str = NULL;

	tab = malloc(sizeof(int) * 10);
	str = malloc(sizeof(char *) * 10);
        show_alloc_mem();

	return (0);
}
