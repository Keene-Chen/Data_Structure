/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.31-15:55:18
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
};

static void print_struct(const void *data)
{
    const struct student *temp = data;
    printf("%s %d <--> ", temp->name, temp->age);
}

static int compare_int(const void *value1, const void *value2)
{
    const int *temp1            = value1;
    const struct student *temp2 = value2;

    return (*temp1 - temp2->age);
}

int main(void)
{
    srand(time(NULL));
    int ret = -1;
    LLIST *list;

    list = llist_create(sizeof(struct student));
    if (list == NULL)
        exit(EXIT_FAILURE);

    struct student stu[5] = { 0 };
    for (int i = 0; i < 5; i++) {
        sprintf(stu[i].name, "stu_%02d", i);
        stu[i].age = rand() % 100;
        ret        = list->insert(list, &stu[i], TAIL_INSERT);
        if (ret)
            exit(EXIT_FAILURE);
    }

    list->travel(list, print_struct);
    printf("当前链表长度: %d\n", list->get_size(list));

    struct student *temp = list->find(list, &stu[0].age, compare_int);
    if (temp == NULL)
        printf("未查找到结点\n");
    else
        printf("name :%s age: %d\n", temp->name, temp->age);

    list->delete (list, &stu[0].age, compare_int);
    list->travel(list, print_struct);

    printf("当前链表长度: %d\n", list->get_size(list));

    llist_destroy(list);

    return 0;
}