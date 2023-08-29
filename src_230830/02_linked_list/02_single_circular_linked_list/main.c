/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.29-14:07:16
 * @details : main
 */

#include "single_circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void print_int(void *data)
{
    int *temp = (int *)data;
    printf("%d --> ", *temp);
}

static int compare_int(void *value1, void *value2)
{
    int *temp1 = (int *)value1;
    int *temp2 = (int *)value2;
    return *temp1 < *temp2;
}

static void test_int(void)
{
    linkedlist list = list_init();
    int arr[5]      = { 0 };

    // 测试随机尾插
    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 100;
        list_tail_insert(list, &arr[i]);
    }
    printf("待插入数据: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    printf("尾插后的循环单链表: \n");
    list_foreach(list, print_int);

    for (int i = 0; i < 3; i++) {
        list_tail_delete(list);
    }
    printf("尾删后的循环单链表: \n");
    list_foreach(list, print_int);

    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 100;
        list_head_insert(list, &arr[i]);
    }
    printf("头插后的循环单链表: \n");
    list_foreach(list, print_int);

    for (int i = 0; i < 3; i++) {
        list_head_delete(list);
    }
    printf("头删后的循环单链表: \n");
    list_foreach(list, print_int);

    int arr1[3] = { 1, 2, 3 };
    list_order_insert(list, &arr1[0], compare_int);
    list_order_insert(list, &arr1[2], compare_int);
    list_order_insert(list, &arr1[1], compare_int);
    printf("顺序插入后的循环单链表: \n");
    list_foreach(list, print_int);

    list_val_delete(list, &arr1[2], compare_int);
    printf("删除指定值后的循环单链表: \n");
    list_foreach(list, print_int);

    list_clear(list);
    printf("清空后的循环单链表: \n");
    list_foreach(list, print_int);

    list_destroy(list);
    printf("%d\n", list_get_size(list));
}

/*******************************************************************************/

struct student {
    char name[32];
    int age;
};

static void print_struct(void *data)
{
    struct student *temp = data;
    printf("%s %d --> ", temp->name, temp->age);
}

static int compare_struct(void *value1, void *value2)
{
    struct student *temp1 = value1;
    struct student *temp2 = value2;
    return strcmp(temp1->name, temp2->name) && temp1->age == temp2->age;
}

static void test_struct(void)
{
    struct list *list     = list_init();
    struct student arr[5] = { 0 };

    for (int i = 0; i < 5; i++) {
        sprintf(arr[i].name, "stu_%02d", i);
        arr[i].age = rand() % 100;
        list_tail_insert(list, &arr[i]);
    }
    printf("尾插后的链表: \n");
    list_foreach(list, print_struct);

    for (int i = 0; i < 3; i++) {
        list_tail_delete(list);
    }
    printf("尾删后的链表: \n");
    list_foreach(list, print_struct);

    for (int i = 0; i < 5; i++) {
        sprintf(arr[i].name, "stu_%02d", i);
        arr[i].age = rand() % 100;
        list_head_insert(list, &arr[i]);
    }
    printf("头插后的链表: \n");
    list_foreach(list, print_struct);

    for (int i = 0; i < 3; i++) {
        list_head_delete(list);
    }
    printf("头删后的链表: \n");
    list_foreach(list, print_struct);

    struct student arr1[3] = { 0 };
    sprintf(arr1[0].name, "stu_%02d", 0);
    arr1[0].age = 0;
    sprintf(arr1[1].name, "stu_%02d", 1);
    arr1[1].age = 1;
    sprintf(arr1[2].name, "stu_%02d", 2);
    arr1[2].age = 2;
    list_order_insert(list, &arr1[0], compare_struct);
    list_order_insert(list, &arr1[2], compare_struct);
    list_order_insert(list, &arr1[1], compare_struct);
    printf("顺序插入后的链表: \n");
    list_foreach(list, print_struct);

    list_val_delete(list, &arr1[2], compare_struct);
    printf("删除指定值后的链表: \n");
    list_foreach(list, print_struct);

    list_clear(list);
    printf("清空后的链表: \n");
    list_foreach(list, print_struct);

    list_destroy(list);
    printf("%d\n", list_get_size(list));
}

int main(void)
{
    srand(time(NULL));
    // test_int();
    test_struct();

    return 0;
}