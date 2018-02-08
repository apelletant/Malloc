/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** malloc header file
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stddef.h>

typedef struct  block_s
{
	size_t size;
	int free;
	struct block_s *next;
} block_t;

block_t *g_head;
block_t *g_last;

#ifndef BLOCK_SIZE_
	#define BLOCK_SIZE sizeof(block_t)
#endif /* BLOC_SIZE_ */

	size_t	align_size(size_t size);
	block_t *get_empty_block(size_t size);
	block_t *extend_memmory(block_t *block, void *ptr, size_t size);
	void	show_alloc_mem();
	void	*malloc(size_t size);
	void	free(void *ptr);
	void	*realloc(void *ptr, size_t size);
	void *calloc(size_t nmemb, size_t size);

#endif /* MALLOC_H_ */
