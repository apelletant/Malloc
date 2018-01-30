/*
** EPITECH PROJECT, 2018
** malloc lib
** File description:
** show alloc function
*/

#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

void show_alloc_mem()
{
	t_block *tmp = NULL;

	tmp = find_head();
	printf("break: %p\n", sbrk(0));
	if (tmp) {
		while (tmp) {
			if (tmp->free == 0) {
				printf("%p - %p : %zu octets\n", &tmp->data,
				       &tmp->data + tmp->size, tmp->size);
				tmp = tmp->next;
			}
		}
	}
}
