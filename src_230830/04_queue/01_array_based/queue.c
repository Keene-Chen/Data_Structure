/**
 * @file    : queue.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:29:03
 * @details : 顺序循环队列
 * !defect  : 当前循环队列大小是固定的,可以使用动态数组改进
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue *queue_create()
{
    queue *queue = malloc(sizeof(struct queue_node));
    if (queue == NULL)
        return NULL;

    queue->front = 0;
    queue->rear  = 0;
    queue->size  = 0;

    return queue;
}

void queue_destroy(queue *queue)
{
    free(queue);
}

int queue_is_empty(queue *queue)
{
    return (queue->front == queue->rear);
}

int queue_enqueue(queue *queue, datatype *data)
{
    // 队列判满
    if ((queue->rear + 1) % MAXSIZE == queue->front)
        return -1;

    // 循环移动队尾
    queue->rear              = (queue->rear + 1) % MAXSIZE;
    queue->data[queue->rear] = *data;
    queue->size++;

    return 0;
}

int queue_dequeue(queue *queue, datatype *data)
{
    // 队列判空
    if (queue_is_empty(queue))
        return -1;

    // 循环移动队头
    queue->front = (queue->front + 1) % MAXSIZE;
    *data        = queue->data[queue->front];
    queue->size--;

    return 0;
}

int queue_travel(queue *queue)
{
    if (queue_is_empty(queue))
        return -1;

    /**
     * 循环移动队头,遍历循环队列
     * 由于判空和判满条件是一样的,所以有两种解决方法
     * 1.queue结构中添加记录队列大小的size
     * 2.使用占位符,让队头位置不存放有效结点
     */
    int count = 0;
    count     = (queue->front + 1) % MAXSIZE;
    while (count != queue->rear) {
        printf("%d ", queue->data[count]);
        count = (count + 1) % MAXSIZE;
    }
    printf("%d\n", queue->data[count]);

    return 0;
}

int queue_clear(queue *queue)
{
    queue->front = queue->rear;

    return 0;
}

int queue_size(queue *queue)
{
    return queue->size;
}