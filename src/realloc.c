/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc function
*/

#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <zconf.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = NULL;
	block_t *block_tmp = (block_t *)ptr -1;

	if (!ptr) {
		return (malloc(size));
	}
	if (size == 0 && block_tmp != NULL){
		free(block_tmp);
		return(NULL);
	}
	if (block_tmp->size >= size) {
		return ptr;
	}
	new_ptr = malloc(size);
	if (!new_ptr) {
		return (NULL);
	}
	memcpy(new_ptr, ptr, block_tmp->size);
	free(ptr);
	return (new_ptr);
}
