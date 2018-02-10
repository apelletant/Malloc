/*
** EPITECH PROJECT, 2018
** main test
** File description:
** test main for the malloc library
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "malloc.h"


void little_test(void)
{
	int *tab = NULL;

	printf("1 malloc + 1 free\n");
	tab = malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 1;
	free(tab);
}

void medium_test(void)
{
	int **tab = NULL;
	int i = 0;

	printf("100 malloc + 100 free");
	tab = malloc(sizeof(int*) * 100);
	while (i < 100) {
		tab[i] = malloc(sizeof(int));
		*(tab[i]) = i;
		i++;
	}
	i--;
	while (i >= 0) {
		free(tab[i]);
		i--;
	}
	free(tab);
}

int realloc_test(void)
{
	char *str = NULL;

	str = malloc(sizeof(char) * 2);
	str[0] = 't';
	str[1] = 'u';
	str = realloc(str, 6);
	str[2] = 't';
	str[3] = 'u';
	str[4] = '\n';
	str[5] = '\0';
	printf("\n%s\n", str);
	str = realloc(str, 3);
	str = realloc(str, 0);
	if (str != NULL) {
		free(str);
		return (0);
	}
	return (1);
}

int main(void)
{

	little_test();
	medium_test();
	if (!realloc_test())
		printf("wrong realloc\n");
	else
		printf("all tests passed\n");
	return (0);
}