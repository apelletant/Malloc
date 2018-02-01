/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** function used to align pointer
*/

#include <stddef.h>

size_t align_pointer(size_t size)
{
	return ((size + 3) & ~3);
}
