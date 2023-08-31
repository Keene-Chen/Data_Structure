/**
 * @file    : list.c
 * @author  : KeeneChen
 * @date    : 2023.08.31-09:39:42
 * @details : 双向循环链表库封装—01
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LLIST *llist_create(int initsize)
{
    LLIST *new;

    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;

    new->size      = initsize;
    new->head.data = NULL;
    new->head.prev = &new->head; // 闭环
    new->head.next = &new->head;

    return new;
}

void llist_destroy(LLIST *list)
{
    struct llist_node_st *cur, *next;
    for (cur = &list->head; cur != &list->head; cur = next) {
        next = cur->next; // 获取下一个结点
        free(cur->data);
        free(cur);
    }
    free(list);
}

int llist_insert(LLIST *list, const void *data, int mode)
{
    struct llist_node_st *newnode;

    newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
        return -1;
    newnode->data = malloc(list->size);
    if (newnode == NULL)
        return -1;
    memcpy(newnode->data, data, list->size);

    // 判断是头插还是尾插
    if (mode == HEAD_INSERT) {
        newnode->prev = &list->head;
        newnode->next = list->head.next;
    }
    else if (mode == TAIL_INSERT) {
        newnode->prev = list->head.prev;
        newnode->next = &list->head;
    }
    else {
        return -1;
    }
    newnode->prev->next = newnode;
    newnode->next->prev = newnode;

    return 0;
}

static struct llist_node_st *find_(LLIST *list, void *key, llist_compare *compare)
{
    struct llist_node_st *cur;

    // 遍历查找比较用户值与有效结点的值是否相等,相等返回有效结点,不等返回头结点
    for (cur = list->head.next; cur != &list->head; cur = cur->next) {
        if (compare(key, cur->data) == 0)
            break;
    }

    return cur;
}

void *llist_find(LLIST *list, void *key, llist_compare *compare)
{
    return find_(list, key, compare)->data;
}

int llist_delete(LLIST *list, void *key, llist_compare *compare)
{
    struct llist_node_st *node;

    node = find_(list, key, compare);
    if (node == &list->head)
        return -1;

    node->prev->next = node->next; // 断链
    node->next->prev = node->prev;

    free(node->data);
    free(node);

    return 0;
}

int llist_fetch(LLIST *list, void *key, llist_compare *compare, void *data)
{
    struct llist_node_st *node;

    node = find_(list, key, compare);
    if (node == &list->head)
        return -1;

    // 先断链然后将查找到的有效结点赋值给用户后在销毁有效结点
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (data != NULL)
        memcpy(data, node->data, list->size);

    free(node->data);
    free(node);

    return 0;
}

int llist_travel(LLIST *list, llist_print *print_cb)
{
    struct llist_node_st *cur;

    for (cur = list->head.next; cur != &list->head; cur = cur->next) {
        // 由于不知道用户的数据结构,所有需要用户自行处理打印
        print_cb(cur->data);
    }
    printf("\n\n");

    return 0;
}

int llist_get_size(LLIST *list)
{
    struct llist_node_st *cur;
    int count = 0;

    for (cur = list->head.next; cur != &list->head; cur = cur->next)
        count++;

    return count;
}