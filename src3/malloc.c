/*
** EPITECH PROJECT, 2018
** lib malloc
** File description:
** malloc source code
*/

#include <stddef.h>
#include <unistd.h>
#include "malloc.h"

	void *g_head = NULL;

static t_block *find_block(t_block **last, size_t size)
{
	t_block *tmp = g_head;

	while (tmp && !(tmp->free && tmp->size >= size)) {
		*last = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

int validate_ptr_address(void *ptr)
{
	if (g_head) {
		if (ptr > g_head && ptr < sbrk(0)) {
			return (ptr == (get_block_by_ptr_address(ptr))->ptr);
		}
	}
	return (0);
}

void *malloc(size_t size)
{
	t_block *new_block = NULL;
	static t_block *last = NULL;
	size_t length;

	if (size > 0)
		length = align_pointer(size);
	else
		return (NULL);

	if (!last) {
		new_block = sbrk(length);
		if (new_block == (void *) -1) {
			return (NULL);
		}
		new_block->next = NULL;
		new_block->prev = NULL;
		new_block->size = length - BLOCK_SIZE;
		new_block->ptr = new_block->data;
		new_block->free = 0;
	}
	else {
		
	}
	return (new_block->data);
}
