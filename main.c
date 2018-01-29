/*
** EPITECH PROJECT, 2018
** main test
** File description:
** test main for the malloc library
*/

#include <stdio.h>
#include "malloc.h"

int main()
{
	int i = 0;
	char **tab;

	tab = malloc(sizeof(char *) * 5);
	tab[0] = malloc(sizeof(char) * (7 + 1));
	tab[0] = "bonjour";
	tab[1] = malloc(sizeof(char) * (3 + 1));
	tab[1] = "les";
	tab[2] = malloc(sizeof(char) * (4 + 1));
	tab[2] = "gens";
	tab[3] = malloc(sizeof(char) * (7 + 1));
	tab[3] = "Antoine";
	tab[4] = malloc(sizeof(char) * (7 + 1));
	tab[4] = "Kellian";

	while (i < 5) {
		printf("%s\n", tab[i]);
		free(tab[i]);
		++i;
	}
	free(tab);
	return (0);
}