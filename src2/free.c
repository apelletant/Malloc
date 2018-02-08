/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free function
*/

#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void putstr(char *str);
void putnbr(unsigned long nbr);

static int update_place()
{
	block_t *tmp = g_head;

	while (tmp && tmp->next != g_last) {
		tmp = tmp->next;
	}
	if (tmp) {
		tmp->next = NULL;
		g_last = tmp;
	}
	return (1);
}

//void free(void *ptr)
//{
//	block_t *block;
//
//	if (!ptr) {
//		return;
//	}
//	pthread_mutex_lock(&mutex);
//	block = (block_t *)ptr - 1;
//
//	block->free = 1;
//	if (block == g_last) {
//		while (g_last != g_head && g_last->free == 1) {
//			update_place();
//			if ((sbrk(0) - ((void *)(g_last + 1) + g_last->size)) >= 4096)
//				sbrk(-4096);
//		}
////		if (g_last == g_head && g_last->free == 1) {
////			putstr("close list\n");
////			g_head = NULL;
////			g_last = NULL;
////		}
//	}
//	pthread_mutex_unlock(&mutex);
//}

void free(void *ptr)
{
	void *last_pos;
	block_t *new;

	if (!ptr)
		return;
	pthread_mutex_lock(&mutex);
	new = (block_t*)ptr - 1;
	last_pos = sbrk(0);
	if ((char *)ptr + new->size == last_pos) {
		update_place();
		while (sbrk(0) - ((void *)(g_last + 1) + g_last->size) >= 4096)
			sbrk(-4096);
		//sbrk(-BLOCK_SIZE - new->size);
		pthread_mutex_unlock(&mutex);
		return;
	}
	new->free = 1;
	pthread_mutex_unlock(&mutex);
}
