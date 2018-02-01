/*
** EPITECH PROJECT, 2018
** malloc lib
** File description:
** block utilities functions
*/

#include <unistd.h>
#include "malloc.h"

t_block *block_union(t_block *block)
{
	if (block->next && block->next->free) {
		block->size += BLOCK_SIZE + block->next->size;
		block->next = block->next->next;
		if (block->next) {
			block->next->prev = block;
		}
	}
	return (block);
}

t_block *extend_block_size(t_block *last, size_t size)
{
	t_block *new_block = NULL;

	new_block = sbrk(0);
	if (sbrk(BLOCK_SIZE + size) == (void*) -1) {
		return (NULL);
	}
	new_block->size = size;
	new_block->free = 0;
	new_block->ptr = new_block->data;
	new_block->next = NULL;
	new_block->prev = last;
	if (last) {
		last->next = new_block;
	}
	return (new_block);
}

void split_bigger_block(t_block *block, size_t size)
{
	t_block *new_block = NULL;

	new_block = (t_block*)(block->data + size);
	new_block->size = block->size + size - BLOCK_SIZE;
	new_block->next = block->next;
	new_block->prev = block;
	new_block->free = 1;
	new_block->ptr = new_block->data;
	block->size = size;
	block->next = new_block;
	if (new_block->next) {
		new_block->next->prev = new_block;
	}
}

t_block *get_block_by_ptr_address(void *ptr)
{
	char *tmp = NULL;

	tmp = ptr;
	ptr = tmp -= BLOCK_SIZE;
	return (ptr);
}

void get_block_copy(t_block *src_block, t_block *dst_block)
{
	size_t index = 0;
	int *src_data = NULL;
	int *dst_data = NULL;

	src_data = src_block->ptr;
	dst_data = dst_block->ptr;
	while (index * 4 < src_block->size && index * 4 < dst_block->size ) {
		dst_data[index] = src_data[index];
		index++;
	}
}
