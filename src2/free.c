/*
** EPITECH PROJECT, 2018
** lib_malloc
** File description:
** free source code
*/

#include <unistd.h>
#include "malloc.h"

int validate_ptr_address(void *ptr)
{
	t_block *head = find_head();
	if (head) {
		if ((t_block *)ptr > head && ptr < sbrk(0)) {
			return (ptr == (get_block_by_ptr_address(ptr))->ptr);
		}
	}
	return (0);
}

void free(void *ptr)
{
	t_block *tmp = NULL;

	if (validate_ptr_address(ptr)) {
		tmp = get_block_by_ptr_address(ptr);
		tmp->free = 1;
		if (tmp->ptr != ptr)
			return;

		if (tmp->prev && tmp->prev->free) {
			tmp = block_union(tmp->prev);
		}
		if (tmp->next) {
			tmp = block_union(tmp);
		}
	} else {
		if (tmp->prev) {
			tmp->prev->next = NULL;
		} else {
			brk(tmp);
		}
	}
}
