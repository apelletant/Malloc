/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** function used to align pointer
*/

#include <stddef.h>

size_t align_pointer(size_t size)
{
	return ((((size - 1) / 4 ) * 4) + 4);
}
