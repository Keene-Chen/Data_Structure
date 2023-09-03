/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:29:19
 * @details : main
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 创建顺序循环队列
    queue *queue = queue_create();

    // 入队
    datatype arr[] = { 1, 2, 3, 4 };
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        queue_enqueue(queue, &arr[i]);
    }
    queue_travel(queue);

    // 队列满时无法入队
    datatype temp = 5;
    int ret       = queue_enqueue(queue, &temp);
    if (ret != 0) {
        printf("enqueue is full\n");
    }
    else {
        queue_travel(queue);
    }

    // 出队
    queue_dequeue(queue, &temp);
    printf("出队元素: %d\n", temp);
    queue_travel(queue);

    printf("环形队列大小: %d\n", queue_size(queue));

    ret = queue_clear(queue);
    if (ret == 0)
        printf("队列为空\n");
    queue_travel(queue);

    // 销毁队列
    queue_destroy(queue);

    return 0;
}