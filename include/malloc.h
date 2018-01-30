/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** malloc header file
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stddef.h>

//void *g_head;

typedef struct __attribute__((__packed__)) s_block
{
	struct s_block *next;
	struct s_block *prev;
	size_t size;
	void *ptr;
	char data[1];
	int free;
} t_block;

#ifndef BLOCK_SIZE_
	#define BLOCK_SIZE sizeof(t_block)
#endif /* BLOC_SIZE_ */

	void *find_head();

	size_t	align_pointer(size_t size);
	t_block	*extend_block_size(t_block *last, size_t size);
	t_block	*get_block_by_ptr_address(void *ptr);

	t_block	*block_union(t_block *block);

	void	split_bigger_block(t_block *block, size_t size);
	void	free(void *ptr);
	void	show_alloc_mem();
	void	*malloc(size_t size);
	int 	validate_ptr_address(void *ptr);

#endif /* MALLOC_H_ */
