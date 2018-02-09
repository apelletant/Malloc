/*
** EPITECH PROJECT, 2018
** malloc lib
** File description:
** malloc
*/

#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

block_t *extend_memmory(block_t *block, void *ptr, size_t size)
{
	block = ptr;
	block->size = size;
	block->free = 0;
	block->next = NULL;
	if (!g_head)
		g_head = block;
	if (g_last)
		g_last->next = block;
	g_last = block;
	return (block);
}

block_t *get_empty_block(size_t size)
{
	block_t *tmp = g_head;

	while (tmp) {
		if (tmp->free == 1 && tmp->size >= size) {
			tmp->free = 0;
			return ((void *)(tmp + 1));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

size_t align_size(size_t size)
{
	return ((size + 0xf) & ~0xf);
}

void *malloc(size_t size)
{
	void *ret = NULL;
	void *ptr = NULL;
	block_t *new_block = NULL;
	size_t new_size = align_size(size);

	if (size == 0)
		return ret;
	pthread_mutex_lock(&mutex);
	new_block = get_empty_block(new_size);
	if (new_block != NULL) {
		ret = new_block;
	} else {
		ptr = sbrk(BLOCK_SIZE + new_size);
		if (ptr != (void *)-1) {
			new_block = extend_memmory(new_block, ptr, new_size);
			ret = (void *)(new_block + 1);
		}
	}
	pthread_mutex_unlock(&mutex);
	return ret;
}

//void *malloc(size_t size)
//{
//	void *ptr = NULL;
//	block_t *new_block = NULL;
//	size_t new_size = align_size(size);
//
//	if (size == 0)
//		return (NULL);
//	pthread_mutex_lock(&mutex);
//	new_block = get_empty_block(new_size);
//	if (new_block != NULL){
//		pthread_mutex_unlock(&mutex);
//		return (new_block);
//	}
//	ptr = sbrk(BLOCK_SIZE + new_size);
//	if (ptr == (void*) - 1){
//		pthread_mutex_unlock(&mutex);
//		return (NULL);
//	}
//	new_block = extend_memmory(new_block, ptr, new_size);
//	pthread_mutex_unlock(&mutex);
//	return ((void*)(new_block + 1));
//}
