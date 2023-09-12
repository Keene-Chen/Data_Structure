/**
 * @file    : list_queue.h
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:29:50
 * @details : list_queue
 */

#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "list.h"

typedef LLIST QUEUE;

QUEUE *list_queue_create(int initsize);

void list_queue_destroy(QUEUE *queue);

int list_queue_enqueue(QUEUE *queue, void *data);

int list_queue_dequeue(QUEUE *queue, void *data);

int list_queue_size(QUEUE *queue);

#endif // __LIST_QUEUE_H__