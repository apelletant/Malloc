/*
** EPITECH PROJECT, 2018
** lib malloc
** File description:
** malloc source code
*/

#include <stddef.h>
#include <unistd.h>
#include "malloc.h"

t_block *find_free_space(t_block *head, t_block **last_block, size_t size)
{
	t_block *tmp = head;

	while (tmp) {
		if (tmp->free && tmp->size >= size) {
			return (tmp);
		}
		tmp->prev = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

t_block *get_more_space(t_block *last_block, size_t size)
{
	t_block *new_block = NULL;
	void *request;

	new_block = sbrk(0);
	request = sbrk(size + BLOCK_SIZE);
	if (request == (void *) -1)
		return (NULL);
	if (last_block) {
		last_block->prev = last_block;
		last_block->next = new_block;
	}
        new_block->size = size;
	new_block->next = NULL;
	new_block->prev = last_block;
	new_block->free = 0;
	return (new_block);
}

void	*malloc(size_t size)
{
	
	if (size == 0)
		return NULL;
	return (ptr);
}
