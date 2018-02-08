/*
** EPITECH PROJECT, 2018
** malloc lib
** File description:
** malloc
*/

#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void putnbr(unsigned long nbr)
{
	unsigned long unit;

	unit = nbr % 10;
	nbr = nbr / 10;
	if (nbr > 0)
		putnbr(nbr);
	unit += 48;
	write(1, &unit, 1);
}

size_t align_size(size_t size)
{
	return ((size + 0xf) & ~0xf);
}

int brk_to_right(size_t length, long size_left)
{
	while (size_left <= 0) {
		if (sbrk(4096) == (void *) -1)
			return (0);
		size_left = sbrk(0) - ((void *)(g_last + 1) + length);
	}
	return (1);
}

int create_head(size_t length, long size_left)
{
	g_head = sbrk(0);
	g_last = g_head;
	if (!brk_to_right(length, size_left))
		return (0);
	g_head->free = 0;
	g_head->size = length;
	g_head->next = NULL;
	return (1);
}

int extend_list(size_t length, long size_left)
{
	if (sbrk(0) - ((void *)(g_last + 1) + g_last->size + length) > 0) {
		g_last->next = (void*)(g_last + 1) + g_last->size;
		g_last = g_last->next;
		g_last->size = length;
		g_last->next = NULL;
		g_last->free = 0;
	} else {
//		putstr("extend page\n");
		size_left = sbrk(0) - ((void *)(g_last + 1) + g_last->size + length);
		if (brk_to_right(length + g_last->size + sizeof(block_t), size_left))
			return (0);
		g_last->next = sbrk(0);
		g_last = g_last->next;
		g_last->size = length;
		g_last->free = 0;
	}
	return (1);
}

void *malloc(size_t size)
{
	void *ptr = NULL;
	long size_left = -1;
	size_t length = align_size(size);

	//putstr("malloc begin\n");
	pthread_mutex_lock(&mutex);
	if (size == 0) {
		pthread_mutex_unlock(&mutex);
		return (NULL);
	}
	if (!g_head) {
		if (!create_head(length, size_left)) {
			pthread_mutex_unlock(&mutex);
			return (NULL);
		}
	}
	else {
		size_left = sbrk(0) - ((void *)(g_last + 1) + g_last->size);
		extend_list(length, size_left);
	}
	ptr = g_last + 1;
	//putstr("malloc end\n");
	pthread_mutex_unlock(&mutex);
	return ptr;
}