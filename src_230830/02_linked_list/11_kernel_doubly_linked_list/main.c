/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.31-20:21:05
 * @details : main
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char name[32];
    int age;
    struct list_head node;
};

int main(void)
{
    srand(time(NULL));
    struct student *pstu = malloc(sizeof(struct student));
    LIST_HEAD(head);

    // 头插法
    for (int i = 0; i < 5; i++) {
        pstu = malloc(sizeof(struct student));
        snprintf(pstu->name, sizeof(pstu->name), "stu_%02d", i);
        pstu->age = rand() % 100;
        list_add(&pstu->node, &head);
    }

    // 尾插法
    for (int i = 0; i < 5; i++) {
        pstu = malloc(sizeof(struct student));
        snprintf(pstu->name, sizeof(pstu->name), "stu_%02d", i);
        pstu->age = rand() % 100;
        list_add_tail(&pstu->node, &head);
    }

    // 遍历链表
    struct list_head *cur;
    list_for_each(cur, &head)
    {
        pstu = list_entry(cur, struct student, node);
        printf("name: %s, age: %d\n", pstu->name, pstu->age);
    }
    list_del(&pstu->node);
    list_for_each(cur, &head)
    {
        pstu = list_entry(cur, struct student, node);
        printf("name: %s, age: %d\n", pstu->name, pstu->age);
    }

    struct list_head *fast = &head;
    struct list_head *slow = &head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            printf("1\n");
            break;
        }
    }

    return 0;
}