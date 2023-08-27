/**
 * @file    : list_test.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-12:52:25
 * @details : list_test
 */

#include "list.h"

typedef struct tagStudent {
    char name[20];
    int age;
} Student;

void print_cb(void *value)
{
    Student *p = value;
    printf("name:%s age:%d\n", p->name, p->age);
}

int compare_cb(void *value1, void *value2)
{
    Student *p1 = value1;
    Student *p2 = value2;
    return (strcmp(p1->name, p1->name) == 0) && (p1->age == p2->age);
}

void test_struct(void)
{
    Student stu1 = { "张三", 1 };
    Student stu2 = { "李四", 2 };
    Student stu3 = { "王五", 3 };
    Student stu4 = { "赵六", 4 };

    linklist list = list_init();
    list_insert(list, 0, &stu1);
    list_insert(list, 1, &stu2);
    list_insert(list, 2, &stu3);
    list_insert(list, -1, &stu4);
    printf("----插入数据----\n");
    list_foreach(list, print_cb);
    printf("链表长度:%d\n", list_get_size(list));

    printf("\n----链表逆序----\n");
    list_reverse(list);
    list_foreach(list, print_cb);
    printf("链表长度:%d\n", list_get_size(list));

    list_delete_by_index(list, 0);
    list_delete_by_value(list, &stu3, compare_cb);
    printf("\n----删除数据----\n");
    list_foreach(list, print_cb);
    printf("链表长度:%d\n", list_get_size(list));

    printf("\n----获取链表第一个和最后一个结点数据----\n");
    Student *temp = list_first(list);
    printf("name:%s age:%d\n", temp->name, temp->age);
    temp = list_last(list);
    printf("name:%s age:%d\n", temp->name, temp->age);

    printf("\n----清空链表----\n");
    list_clear(list);
    printf("链表长度:%d\n", list_get_size(list));

    printf("%s\n", list_get_version());

    list_destory(list);
}

int main(void)
{
    test_struct();

    // TODO: 测试int类型

    return 0;
}