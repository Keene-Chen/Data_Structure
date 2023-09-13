/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.13-14:04:35
 * @details : main
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

struct student {
    int id;
    char name[32];
    double score;
};

static void print_stu(void *data)
{
    struct student *stu = data;
    printf("%d %s %.2f\n", stu->id, stu->name, stu->score);
}

static int compare_stu(void *data1, void *data2)
{
    struct student *stu1 = data1;
    struct student *stu2 = data2;

    return (stu1->id <= stu2->id);
    // return strcmp(stu1->name, stu2->name) < 0;
    // return (stu1->score <= stu2->score);
}

static int compare_equl(void *data1, void *data2)
{
    struct student *stu1 = data1;
    struct student *stu2 = data2;

    return (stu1->id == stu2->id);
}

int main(void)
{
    struct student stu[] = {
        { 0, "stu_00", 15.6 }, { 2, "stu_02", 12.2 }, { 3, "stu_03", 34.6 },
        { 4, "stu_04", 75.6 }, { 9, "stu_09", 89.6 }, { 7, "stu_07", 62.6 },
        { 8, "stu_08", 56.6 }, { 1, "stu_01", 87.6 }, { 6, "stu_06", 27.6 },
        { 5, "stu_05", 95.6 },
    };
    struct student stu1 = { 10, "stu_01", 87.6 };

    List *list1 = list_init();
    List *list2 = list_init();

    for (int i = 0; i < ARRAY_SIZE(stu) - 5; i++) {
        list_tail_insert(list1, &stu[i]);
        list_tail_insert(list2, &stu[i + 5]);
    }

    printf("插入后的链表: \n");
    list_travel(list1, print_stu);

    printf("删除链表中的结点\n");
    int ret = list_delete(list1, &stu[1], compare_equl);
    if (ret)
        printf("未找到结点\n");
    else
        list_travel(list1, print_stu);

    printf("反转后的链表: \n");
    list_reverse(list1);
    list_travel(list1, print_stu);

    printf("排序后的链表1: \n");
    list_bubble_sort(list1, compare_stu);
    list_bubble_sort(list2, compare_stu);
    list_travel(list1, print_stu);
    printf("排序后的链表2: \n");
    list_travel(list2, print_stu);

    List *list3 = list_merge(list1, list2, compare_stu);
    printf("合并后的链表: \n");
    list_travel(list3, print_stu);

    ret = list_has_cycle(list3);
    if (ret)
        printf("链表无环\n");
    else
        printf("链表有环\n");

    list_destory(list3);

    return 0;
}