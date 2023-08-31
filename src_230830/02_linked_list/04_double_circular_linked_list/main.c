#include "double_circular_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char name[32];
    int age;
};

static void print_struct(void *data)
{
    struct student *temp = data;
    printf("%s %d <--> ", temp->name, temp->age);
}

static int compare_struct(void *value1, void *value2)
{
    struct student *temp1 = value1;
    struct student *temp2 = value2;

    return (strcmp(temp1->name, temp2->name) == 0) && (temp1->age == temp2->age);
}

int main(void)
{
    srand(time(NULL));

    // 创建头结点管理链表
    linkedlist list = list_create(sizeof(struct student));
    if (list == NULL)
        exit(EXIT_FAILURE);

    // 头插链表
    struct student stu[5] = { 0 };
    int ret               = 0;
    for (int i = 0; i < 5; i++) {
        sprintf(stu[i].name, "stu_%02d", i);
        stu[i].age = rand() % 100;
        ret        = list_insert(list, &stu[i], TAIL_INSERT);
        if (ret)
            exit(EXIT_FAILURE);
    }
    printf("插入后的链表: \n");
    list_foreach(list, print_struct);

    // 查找结点
    struct student stu1  = { "ss", 34 };
    struct student *temp = list_find(list, &stu1, compare_struct);
    if (temp == NULL)
        printf("未查找到结点\n");
    else
        printf("%s\n", temp->name);

    // 删除结点
    // list_delete(list, &stu[0], compare_struct);
    printf("删除后的链表: \n");
    list_foreach(list, print_struct);

    // 获取结点
    struct student temp1;
    ret = list_fetch(list, &stu[1], compare_struct, &temp1);
    printf("%d\n", ret);
    printf("name: %s age: %d\n", temp1.name, temp1.age);

    // 销毁链表
    list_destroy(list);

    return 0;
}