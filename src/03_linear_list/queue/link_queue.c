/**
 * @file    : link_queue.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:52:25
 * @details : link_queue
 */

#include "link_queue.h"

link_queue link_queue_init()
{
    link_queue_t *queue = malloc(sizeof(link_queue_t));
    if (queue == NULL)
        return NULL;
    queue->header.next = NULL;
    queue->tail        = &queue->header;
    queue->size        = 0;

    return queue;
}

void link_queue_destory(link_queue queue)
{
    isNULL(queue);
    free(queue);
    queue = NULL;
}

void link_queue_push(link_queue queue, void *value)
{
    isNULL(queue);
    isNULL(value);

    link_queue_t *lqueue = queue;
    queue_node_t *temp   = value;

    // 更改指针指向
    lqueue->tail->next = temp;
    temp->next         = NULL;

    // 更新新的尾节点
    lqueue->tail = temp;
    lqueue->size++;
}

void link_queue_pop(link_queue queue)
{
    isNULL(queue);

    link_queue_t *lqueue = queue;
    if (lqueue->size == 0)
        return;
    if (lqueue->size == 1) {
        lqueue->header.next = NULL;
        lqueue->tail        = &lqueue->header;
        lqueue->size--;
        return;
    }

    // 记录第一个有数据的节点
    queue_node_t *frist = lqueue->header.next;

    // 更改指针指向
    lqueue->header.next = frist->next;
    lqueue->size--;
}

int link_queue_size(link_queue queue)
{
    if (queue == NULL)
        return -1;
    link_queue_t *lqueue = queue;
    return lqueue->size;
}

int link_queue_isEmpty(link_queue queue)
{
    if (queue == NULL)
        return -1;
    link_queue_t *lqueue = queue;
    if (lqueue->size == 0)
        return 1;
    return 0;
}

void *link_queue_front(link_queue queue)
{
    if (queue == NULL)
        return NULL;
    link_queue_t *lqueue = queue;
    return lqueue->header.next;
}

void *link_queue_back(link_queue queue)
{
    if (queue == NULL)
        return NULL;
    link_queue_t *lqueue = queue;
    return lqueue->tail;
}
