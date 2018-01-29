/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** malloc header file
*/

#ifndef MALLOC_H_
	#define MALLOC_H_

	#include <stddef.h>

	extern void *g_head;

	typedef struct __attribute((__packed__)) s_block
	{
		size_t size;
		int free;
		char data[1];
		void *ptr;
	        struct s_block *next;
	        struct s_block *prev;
	} t_block;

	#ifndef BLOCK_SIZE_
		#define BLOCK_SIZE sizeof(t_block)
	#endif /* BLOC_SIZE_ */

	void	*malloc(size_t size);
	size_t align_pointer(size_t size);
	void split_bigger_block(t_block *block, size_t size);
	t_block *extend_block_size(t_block *last, size_t size);
	t_block *block_union(t_block *block);
	t_block *get_block_by_ptr_address(void *ptr);
	int validate_ptr_address(void *ptr);
	void free(void *ptr);
	void show_alloc_mem();
#endif /* MALLOC_H_ */
