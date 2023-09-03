/**
 * @file    : queue.h
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:28:09
 * @details : 顺序循环队列
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))
#endif

#define MAXSIZE 5
typedef int datatype;

typedef struct queue_node {
    datatype data[MAXSIZE];
    int front;
    int rear;
    int size;
} queue;

queue *queue_create();

void queue_destroy(queue *queue);

int queue_is_empty(queue *queue);

// 入队
int queue_enqueue(queue *queue, datatype *data);

int queue_dequeue(queue *queue, datatype *data);

int queue_travel(queue *queue);

int queue_clear(queue *queue);

int queue_size(queue *queue);

#endif // __QUEUE_H__