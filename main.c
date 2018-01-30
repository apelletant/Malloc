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
	int *tab;


	tab = malloc(sizeof(int) * 5000);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[4999] = 4;
	printf("%d %d %d\n", tab[0], tab[1], tab[4999]);

	return (0);
}