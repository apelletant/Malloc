/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc function
*/

#include <unistd.h>

#include <string.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
/*	void *tmp;
	block_t *new_block = NULL;

	if (!ptr)
		return (malloc(size));
	if (size == 0 && ptr != NULL) {
		free(ptr);
		return (NULL);
	}
	new_block = (block_t*)ptr - 1;
	if (new_block->size >= size)
		return (ptr);
	tmp = malloc(size);
	if (tmp) {
		memcpy(tmp, ptr, new_block->size);
		free(ptr);
	}
	return (tmp);*/
	block_t *block_tmp = (block_t *)ptr -1;
        void *new_ptr = NULL;

	if (!ptr) {
		return (malloc(size));
	}
	if (block_tmp->size >= size) {
		return block_tmp;
	}
	new_ptr = malloc(size);
	if (!new_ptr) {
		return (NULL);
	}
	memcpy(new_ptr, ptr, block_tmp->size);
	free(ptr);
	return (new_ptr);
}
