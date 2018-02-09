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
	block_t *tmp = NULL;

	tmp = g_head;
	printf("break: 0x%lX\n", (size_t)sbrk(0));
	while (tmp) {
		if (tmp->free == 0) {
			printf("0x%lX - 0x%lX : %lu bytes\n",
				((size_t)tmp + BLOCK_SIZE),
				((size_t)tmp + BLOCK_SIZE) + tmp->size,
				tmp->size);
			tmp = tmp->next;
		}
	}
}
