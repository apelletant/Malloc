/*
** EPITECH PROJECT, 2018
** lib malloc
** File description:
** malloc source code
*/

#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

void *g_head = NULL;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
	t_block *last = NULL;
	size_t position = align_pointer(size);

	pthread_mutex_lock(&mutex);
	if (g_head) {
		last = g_head;
		new_block = find_block(&last, size);
		if (new_block) {
			if (new_block->size - position >= BLOCK_SIZE + 4)
				split_bigger_block(new_block, position);
			new_block->free = 0;
		} else {
			new_block = extend_block_size(last, position);
			if (!new_block) {
				pthread_mutex_unlock(&mutex);
				return (NULL);
			}
		}
	} else {
		new_block = extend_block_size(NULL, position);
		if (!new_block){
			pthread_mutex_unlock(&mutex);
			return (NULL);
		}
		g_head = new_block;
	}
	pthread_mutex_unlock(&mutex);
	return (new_block->data);
}
