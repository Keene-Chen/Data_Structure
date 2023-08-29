/**
 * @file    : head_linked_list.c
 * @author  : KeeneChen
 * @date    : 2023.08.27-11:37:51
 * @details : head_linked_list
 */

#include "head_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list *list_create(void)
{
    list *head = malloc(sizeof(list));
    if (head == NULL) {
        printf("malloc failed!\n");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;

    return head;
}

int list_insert_at(list *l, int i, datatype *data)
{
    if (l == NULL)
        return -1;
    if (i < 0)
        return -1;
    if (data == NULL)
        return -1;

    list *head = l;
    // 遍历查找到前驱结点
    // int j      = 0;
    // while (head != NULL && j < i) {
    //     head = head->next;
    //     j++;
    // }
    for (int j = 0; head != NULL && j < i; j++) {
        head = head->next;
    }

    // 判断找到的前驱结点是否有效
    if (head) {
        list *new_node = malloc(sizeof(list));
        if (new_node == NULL)
            return -1;

        // 新结点的数据域和指针域赋值
        new_node->data = *data;
        new_node->next = NULL;

        // 头插法插入新结点
        new_node->next = head->next;
        head->next     = new_node;
    }
    else {
        return -1;
    }

    return 0;
}

int list_order_insert(list *l, datatype *data, int (*compare_cb)(datatype *, datatype *))
{
    if (l == NULL)
        return -1;
    if (data == NULL)
        return -1;
    if (compare_cb == NULL)
        return -1;

    list *head = l;
    while (head->next != NULL && compare_cb(data, &head->next->data) == 0) {
        head = head->next;
    }

    list *new_node = malloc(sizeof(list));
    if (new_node == NULL)
        return -1;

    new_node->data = *data;
    new_node->next = NULL;

    new_node->next = head->next;
    head->next     = new_node;

    return 0;
}

int list_delete_at(list *l, int i, datatype *data)
{
    if (l == NULL)
        return -1;
    if (i < 0)
        return -1;
    if (data == NULL)
        return -1;

    list *p = l;
    while (p->next != NULL && i > 0) {
        p = p->next;
        i--;
    }

    if (p->next) {
        list *tmp = p->next;
        p->next   = tmp->next;
        *data     = tmp->data;
        free(tmp);
    }
    else {
        return -1;
    }

    return 0;
}

int list_delete(list *l, datatype *data, int compare_cb(datatype *, datatype *))
{
    if (l == NULL)
        return -1;
    if (data == NULL)
        return -1;
    if (compare_cb == NULL)
        return -1;

    list *p = l;
    while (p->next != NULL && compare_cb(data, &p->next->data) != 0) {
        p = p->next;
    }

    if (p->next) {
        list *tmp = p->next;
        p->next   = tmp->next;
        free(tmp);
    }
    else {
        return -1;
    }

    return 0;
}

int list_isempty(list *l)
{
    if (l->next == NULL)
        return -1;
    return 0;
}

void list_display(list *l)
{
    if (list_isempty(l))
        exit(EXIT_FAILURE);

    list *p = l->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void list_destroy(list *l)
{
    list *p = l;
    while (p != NULL) {
        list *tmp = p;
        p         = p->next;
        free(tmp);
    }
}