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

static void update_place()
{
	block_t *tmp = g_head;

	if (g_head == g_last) {
		g_head = NULL;
		g_last = NULL;
	} else {
		while (tmp) {
			if (tmp->next == g_last) {
				tmp->next = NULL;
				g_last = tmp;
			}
			tmp = tmp->next;
		}
	}
}

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
		sbrk(-BLOCK_SIZE - new->size);
		pthread_mutex_unlock(&mutex);
		return;
	}
	new->free = 1;
	pthread_mutex_unlock(&mutex);
}
