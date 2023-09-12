/**
 * @file    : list_queue.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:29:58
 * @details : list_queue
 */

#include "list_queue.h"
#include <stdio.h>
#include <stdlib.h>

QUEUE *list_queue_create(int initsize)
{
    QUEUE *queue = llist_create(initsize);
    if (queue == NULL)
        return NULL;

    return queue;
}

void list_queue_destroy(QUEUE *queue)
{
    llist_destroy(queue);
}

int list_queue_enqueue(QUEUE *queue, void *data)
{
    return llist_insert(queue, data, TAIL_INSERT);
}

static int always_match(const void *data1, const void *data2)
{
    return 0;
}

int list_queue_dequeue(QUEUE *queue, void *data)
{
    return llist_fetch(queue, NULL, always_match, data);
}

int list_queue_size(QUEUE *queue)
{
    return llist_get_size(queue);
}
