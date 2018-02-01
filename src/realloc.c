/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** realloc function
*/

#include <stddef.h>
#include <string.h>
#include <pthread.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *realloc(void *ptr, size_t size)
{
/*	size_t new_size = align_pointer(size);
	t_block *tmp_block = NULL;

	pthread_mutex_lock(&mutex);
	if (!ptr) {
		pthread_mutex_unlock(&mutex);
		return (malloc(new_size));
	}
	else if (size <= 0) {
		free(ptr);
	} else {
		tmp_block = malloc(new_size);
		if (!tmp_block) {
		pthread_mutex_unlock(&mutex);
			return (NULL);
		} else {
			memcpy(ptr, tmp_block, new_size);
			free(ptr);
		}
	}
	pthread_mutex_unlock(&mutex);*/
	return (malloc(size));
}
