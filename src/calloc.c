/*
** EPITECH PROJECT, 2021
** psu_2017_malloc
** File description:
** Created by invicta,
*/

#include <string.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
	void *ptr = NULL;

	ptr = malloc(nmemb * size);
	memset(ptr, 0, nmemb * size);
	return (ptr);
}