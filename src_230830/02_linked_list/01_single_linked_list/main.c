/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.25-10:55:25
 * @details : main
 */

#include "single_linked_list.h"

static inline void print_int(void *arg)
{
    printf("%d -> ", *(int *)arg);
}

static inline int compare_int(void *value1, void *value2)
{
    return value1 == value2;
}

void test_int(int *arr)
{
    // 链表初始化
    linkedlist *list = linkedlist_init();
    SHOW("linkedlist_init");

    // 链表插入值
    linkedlist_insert(list, 0, &arr[0]);
    linkedlist_insert(list, 2, &arr[1]);
    linkedlist_insert(list, 1, &arr[2]);
    linkedlist_insert(list, 3, &arr[3]);
    linkedlist_insert(list, 4, &arr[4]);
    SHOW("linkedlist_insert");
    linkedlist_foreach(list, print_int);
    printf("NULL\n");

    // 链表根据索引删除元素
    linkedlist_del_by_index(list, 0);
    SHOW("linkedlist_del_by_index");
    linkedlist_foreach(list, print_int);
    printf("NULL\n");

    // 链表根据值删除元素
    linkedlist_del_by_value(list, &arr[3], compare_int);
    SHOW("linkedlist_del_by_value");
    linkedlist_foreach(list, print_int);
    printf("NULL\n");

    // 获取链表第一个元素
    int *temp1 = linkedlist_first(list);
    printf("first: %d\n", *temp1);

    // 获取链表最后一个元素
    int *temp2 = linkedlist_last(list);
    printf("last: %d\n", *temp2);

    // 链表反转
    linkedlist_reverse(list);
    SHOW("linkedlist_reverse");
    linkedlist_foreach(list, print_int);
    printf("NULL\n");

    // 链表清空
    linkedlist_clear(list);
    SHOW("linkedlist_clear");
    linkedlist_foreach(list, print_int);
    printf("NULL\n");

    // 链表销毁
    linkedlist_destory(list);
}

/***********************************************************************/

struct student {
    char name[20];
    int age;
};

static inline void print_struct(void *arg)
{
    struct student *stu = arg;

    printf("name: %s age: %d\n", stu->name, stu->age);
}

static inline int compare_struct(void *value1, void *value2)
{
    struct student *stu1 = value1;
    struct student *stu2 = value2;

    return (strcmp(stu1->name, stu2->name) == 0) && stu1->age == stu2->age;
}

void test_struct(struct student *stu)
{
    // 链表初始化
    linkedlist *list = linkedlist_init();
    SHOW("linkedlist_init");

    // 链表插入值
    linkedlist_insert(list, 0, &stu[0]);
    linkedlist_insert(list, 2, &stu[1]);
    linkedlist_insert(list, 1, &stu[2]);
    linkedlist_insert(list, 3, &stu[3]);
    linkedlist_insert(list, 4, &stu[4]);
    SHOW("linkedlist_insert");
    linkedlist_foreach(list, print_struct);
    printf("NULL\n");

    // 链表根据索引删除元素
    linkedlist_del_by_index(list, 0);
    SHOW("linkedlist_del_by_index");
    linkedlist_foreach(list, print_struct);
    printf("NULL\n");

    // 链表根据值删除元素
    linkedlist_del_by_value(list, &stu[3], compare_struct);
    SHOW("linkedlist_del_by_value");
    linkedlist_foreach(list, print_struct);
    printf("NULL\n");

    // 获取链表第一个元素
    struct student *temp1 = linkedlist_first(list);
    printf("first: %s %d\n", temp1->name, temp1->age);

    // 获取链表最后一个元素
    struct student *temp2 = linkedlist_last(list);
    printf("last: %s %d\n", temp2->name, temp2->age);

    // 链表反转
    linkedlist_reverse(list);
    SHOW("linkedlist_reverse");
    linkedlist_foreach(list, print_struct);
    printf("NULL\n");

    // 链表清空
    linkedlist_clear(list);
    SHOW("linkedlist_clear");
    linkedlist_foreach(list, print_struct);
    printf("NULL\n");

    // 链表销毁
    linkedlist_destory(list);
}

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5 };
    // test_int(arr);

    struct student stu[5] = { { "张三", 10 },
                              { "李四", 20 },
                              { "王五", 30 },
                              { "赵六", 40 },
                              { "孙七", 50 } };
    test_struct(stu);

    return 0;
}