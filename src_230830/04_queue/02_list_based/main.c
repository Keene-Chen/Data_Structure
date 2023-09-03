/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-19:30:05
 * @details : main
 */

#include "list_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct student {
        char name[32];
        int age;
    };
    struct student stu[] = { { "KeeneChen1", 20 }, { "KeeneChen2", 21 }, { "KeeneChen3", 22 } },
                   temp  = { 0 };

    QUEUE *queue = list_queue_create(sizeof(struct student));

    for (int i = 0; i < sizeof(stu) / sizeof(*stu); i++) {
        list_queue_enqueue(queue, &stu[i]);
    }
    printf("链式队列大小: %d\n", list_queue_size(queue));

    while (list_queue_dequeue(queue, &temp) == 0) {
        printf("name: %s, age: %d\n", temp.name, temp.age);
    }
    printf("链式队列大小: %d\n", list_queue_size(queue));

    list_queue_destroy(queue);

    return 0;
}