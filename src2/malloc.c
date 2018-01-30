/*
** EPITECH PROJECT, 2018
** lib malloc
** File description:
** malloc source code
*/

#include <stddef.h>
#include <unistd.h>
#include "malloc.h"

void *find_head()
{
	static t_block *head = NULL;
	t_block *ret = NULL;

	if (head == NULL) {
		head = sbrk(align_pointer(sizeof(t_block)));
		if (head != (void *) -1) {
			head->prev = NULL;
			head->next = NULL;
			head->size = 0;
			head->free = 0;
			head->ptr = NULL;
		}
		else
			ret = head;
	}
	return (ret);
}


t_block *find_block(t_block **last, size_t size)
{

	t_block *tmp = find_head();
	t_block *ret = NULL;


	if (tmp != NULL) {
		while (tmp && (tmp->free == 0 || tmp->size < size)) {
			*last = tmp;
			tmp = tmp->next;
		}
		ret = tmp;
	}
	return (ret);
}

void *new_block(size_t length, t_block *last)
{
	t_block *new_block = sbrk(length);

	if (new_block == (void *) -1)
		return (NULL);
	last->next = new_block;
	new_block->prev = last;
	new_block->next = NULL;
	new_block->size = length - sizeof(t_block);
	new_block->ptr = new_block + 1;
	return (new_block);
}

void *malloc(size_t size)
{
	size_t length = align_pointer(size + sizeof(t_block));;
	t_block *last = NULL;
	t_block *block = NULL;
//	void *ret = NULL;

	if (size <= 0)
		return (NULL);

	block = find_block(&last, size);
	if (last == NULL)
		return (NULL);
	if (block == NULL) {
		block = new_block(length, last);
	}
	else if (length + sizeof(size_t) < block->size)
		split_bigger_block(block, length);
	block->free = 0;
	return (block->ptr);
}
