/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** malloc header file
*/

#ifndef MALLOC_H_
	#define MALLOC_H_

	#include <stddef.h>

	typedef struct s_block
	{
		size_t size;
		int free;
	        struct s_block *next;
		struct s_block *prev;
	} t_block;

	#ifndef BLOCK_SIZE_
		#define BLOCK_SIZE sizeof(t_block)
	#endif /* BLOC_SIZE_ */
#endif /* MALLOC_H_ */
