/**
 * @file    : link_queue.h
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:51:46
 * @details : link_queue
 */

#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isNULL(x)    \
    if ((x) == NULL) \
        return;

// 结点结构体
typedef struct queue_node_s {
    struct queue_node_s *next;
} queue_node_t;

// 队列结构体
typedef struct link_queue_s {
    queue_node_t header;
    int size;
    queue_node_t *tail;
} link_queue_t;

typedef void *link_queue;

link_queue link_queue_init();
void link_queue_push(link_queue queue, void *value);
void link_queue_pop(link_queue queue);
int link_queue_size(link_queue queue);
int link_queue_isEmpty(link_queue queue);
void *link_queue_front(link_queue queue);
void *link_queue_back(link_queue queue);
void link_queue_destory(link_queue queue);

#endif // __LINK_QUEUE_H__