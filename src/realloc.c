/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc function
*/

#include <string.h>
#include <pthread.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *realloc(void *ptr, size_t size)
{
	block_t *block_tmp = (block_t *)ptr -1;
        void *new_ptr = NULL;

	pthread_mutex_lock(&mutex);
	if (!ptr) {
		pthread_mutex_unlock(&mutex);
		return (malloc(size));
	}
	if (block_tmp->size >= size) {
		pthread_mutex_unlock(&mutex);
		return block_tmp;
	}
	new_ptr = malloc(size);
	if (!new_ptr) {
		pthread_mutex_unlock(&mutex);
		return (NULL);
	}
	memcpy(new_ptr, ptr, block_tmp->size);
	free(ptr);
	pthread_mutex_unlock(&mutex);
	return (new_ptr);
}
