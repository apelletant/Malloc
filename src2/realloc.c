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

void putstr(char *str);
void putnbr(unsigned long nbr);

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = NULL;
	block_t *block_tmp = (block_t *)ptr -1;

//	putstr("realloc begin\n");
	if (!ptr) {
//		putstr("realloc end 2\n");
		return (malloc(size));
	}
	if (size == 0 && block_tmp != NULL){
		free(block_tmp);
//		putstr("realloc end 3\n");
		return(NULL);
	}
	if (block_tmp->size >= size) {
//		putstr("realloc end 4\n");
		return ptr;
	}
	new_ptr = malloc(size);
	if (!new_ptr) {
//		putstr("realloc end 5\n");
		return (NULL);
	}
	memcpy(new_ptr, ptr, block_tmp->size);
	free(ptr);
//	putstr("realloc end 1\n");
	return (new_ptr);
}
