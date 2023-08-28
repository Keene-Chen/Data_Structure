/**
 * @file    : seq_queue.h
 * @author  : KeeneChen
 * @date    : 2022.09.01-16:13:44
 * @details : seq_queue
 */

#ifndef __SEQ_QUEUE_H__
#define __SEQ_QUEUE_H__

#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION  "0.1.0"
#define MAX_SIZE 1024
#define isNULL(x)    \
    if ((x) == NULL) \
        return;

typedef void *seq_queue;

seq_queue seq_queue_init(void);
void seq_queue_destory(seq_queue queue);
void seq_queue_push(seq_queue queue, void *value);
void seq_queue_pop(seq_queue queue);
void *seq_queue_front(seq_queue queue);
void *seq_queue_back(seq_queue queue);
int seq_queue_size(seq_queue queue);
int seq_queue_isEmpty(seq_queue queue);

#endif // __SEQ_QUEUE_H__
