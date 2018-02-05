/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free function
*/

#include <unistd.h>
#include "malloc.h"

static void update_place()
{
	block_t *tmp = g_head;

	if (g_head == g_last) {
		g_head = NULL;
		g_last = NULL;
	} else {
		while (tmp) {
			if (tmp->next == g_last) {
				tmp->next = NULL;
				g_last = tmp;
			}
			tmp = tmp->next;
		}
	}
}

void free(void *ptr)
{
	void *last_pos;
	block_t *new;

	if (!ptr)
		return;
	new = (block_t*)ptr - 1;
	last_pos = sbrk(0);
	if ((char *)ptr + new->size == last_pos) {
		update_place();
		sbrk(-BLOCK_SIZE - new->size);
		return;
	}
	new->free = 1;
}
