/**
 * @file    : list_merge.c
 * @author  : KeeneChen
 * @date    : 2023.09.13-09:18:14
 * @details : 有序单链表合并
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*print_cb)(void *);
typedef int (*compare_cb)(void *data1, void *data2);

struct node_st {
    void *data;
    struct node_st *next;
} *list, node;

struct student {
    int id;
    char name[32];
    double score;
};

struct node_st *list_init(void)
{
    struct node_st *head = malloc(sizeof(struct node_st));
    if (head == NULL)
        return NULL;

    head->data = NULL;
    head->next = NULL;
    return head;
}

void list_destroy(struct node_st *list)
{
    if (list == NULL)
        return;

    struct node_st *temp = list;
    while (temp != NULL) {
        struct node_st *cur = temp;
        temp                = temp->next;
        free(cur);
    }
}

int list_tail_insert(struct node_st *list, void *data)
{
    if (list == NULL || data == NULL)
        return -1;

    struct node_st *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    struct node_st *new_node = malloc(sizeof(struct node_st));
    new_node->data           = data;
    new_node->next           = NULL;

    temp->next = new_node;

    return 0;
}

int list_travel(struct node_st *list, print_cb print)
{
    if (list == NULL)
        return -1;

    struct node_st *temp = list;
    while (temp->next != NULL) {
        print(temp->next->data);
        temp = temp->next;
    }

    return 0;
}

void list_reverse(struct node_st *list)
{
    if (list == NULL)
        return;

    struct node_st *temp = list->next;
    struct node_st *prev = NULL;

    while (temp != NULL) {
        struct node_st *next = temp->next;
        temp->next           = prev;
        // 此时判断 next 是否为 NULL，如果成立则退出循环
        if (next == NULL) {
            break;
        }
        // 整体向后移动 3 个指针
        prev = temp;
        temp = next;
        next = next->next;
        // 最后修改 head 头指针的指向
        list->next = temp;
    }
}

void list_bubble_sort(struct node_st *list, compare_cb compare)
{
    int count = 0;
    struct node_st *p, *q, *head;

    p = list;
    while (p->next != NULL) {
        count++;
        p = p->next;
    }

    for (int i = 0; i < count - 1; i++) {
        head = list;
        q    = list->next;
        p    = q->next;

        for (int j = 0; j < count - i - 1; j++) {
            if (!compare(q->data, p->data)) { // 如果该结点的值大于后一个结点则交换
                q->next    = p->next;
                p->next    = q;
                head->next = p;
            }
            head = head->next;
            q    = head->next;
            p    = q->next;
        }
    }
}

struct node_st *list_merge(struct node_st *list1, struct node_st *list2, compare_cb compare)
{
    if (list1 == NULL || list2 == NULL)
        return NULL;

    struct node_st *head = malloc(sizeof(struct node_st));
    struct node_st *pre  = head;
    struct node_st *p1   = list1->next;
    struct node_st *p2   = list2->next;

    while (p1 != NULL && p2 != NULL) {
        if (compare(p1->data, p2->data)) {
            pre->next = p1;
            p1        = p1->next;
        }
        else {
            pre->next = p2;
            p2        = p2->next;
        }
        pre = pre->next;
    }
    pre->next = p1 ? p1 : p2;

    return head;
}

/************************************
 *             TEST                 *
 ************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

static void print_stu(void *data)
{
    struct student *stu = data;
    printf("%d %s %.2f\n", stu->id, stu->name, stu->score);
}

static int compare_stu(void *data1, void *data2)
{
    struct student *stu1 = data1;
    struct student *stu2 = data2;

    // return (stu1->id <= stu2->id);
    return strcmp(stu1->name, stu2->name) < 0;
    // return (stu1->score <= stu2->score);
}

int main(void)
{
    struct student stu1[] = { { 5, "stu_00", 12.0 },
                              { 2, "stu_01", 45.3 },
                              { 3, "stu_02", 56.1 },
                              { 4, "stu_03", 34.5 },
                              { 1, "stu_04", 65.7 } };
    struct student stu2[] = { { 0, "stu_05", 31.1 },
                              { 9, "stu_06", 43.2 },
                              { 7, "stu_07", 65.4 },
                              { 6, "stu_08", 61.2 },
                              { 8, "stu_09", 88.4 } };
    struct node_st *list1 = list_init();
    struct node_st *list2 = list_init();
    struct node_st *list  = NULL;

    for (int i = 0; i < ARRAY_SIZE(stu1); i++) {
        list_tail_insert(list1, &stu1[i]);
        list_tail_insert(list2, &stu2[i]);
    }

    list_bubble_sort(list1, compare_stu);
    list_bubble_sort(list2, compare_stu);

    list = list_merge(list1, list2, compare_stu);
    list_travel(list, print_stu);

    list_destroy(list);

    return 0;
}
