/**
 * @file    : seq_queue.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:39:07
 * @details : seq_queue
 */

#include "seq_queue.h"

seq_queue seq_queue_init(void)
{
    dyn_arr_t *arr = dyn_arr_init(MAX_SIZE);
    return arr;
}

void seq_queue_destory(seq_queue queue)
{
    isNULL(queue);

    dyn_arr_destroy(queue);
}

void seq_queue_push(seq_queue queue, void *value)
{
    isNULL(queue);
    isNULL(value);

    dyn_arr_t *squeue = queue;
    if (squeue->size == MAX_SIZE)
        return;
    dyn_arr_insert(squeue, squeue->size, value);
}

void seq_queue_pop(seq_queue queue)
{
    isNULL(queue);

    dyn_arr_t *squeue = queue;
    if (squeue->size <= 0)
        return;
    dyn_arr_delete_by_index(squeue, 0);
}

void *seq_queue_front(seq_queue queue)
{
    dyn_arr_t *squeue = queue;
    return dyn_arr_first(squeue);
}

void *seq_queue_back(seq_queue queue)
{
    dyn_arr_t *squeue = queue;
    return dyn_arr_last(squeue);
}

int seq_queue_size(seq_queue queue)
{
    if (queue == NULL)
        return -1;
    dyn_arr_t *squeue = queue;
    return squeue->size;
}

int seq_queue_isEmpty(seq_queue queue)
{
    if (queue == NULL)
        return -1;

    dyn_arr_t *squeue = queue;
    if (squeue->size == 0) {
        return 1;
    }

    return 0;
}