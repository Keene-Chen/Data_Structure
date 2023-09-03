/**
 * @file    : list.c
 * @author  : KeeneChen
 * @date    : 2023.08.31-14:12:01
 * @details : list
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 有效结点结构体
 * ? 由于头结点数据源未使用可以使用变长结构体进行优化
 * ? C99标准支持0字节的变长数组,用于定位地址,充当占位符的作用
 * ? 也可以使用char data[1],但因为内存对齐还是占4个字节,所以在分配内存时应该减去
 */
struct llist_node_st {
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0];
};

/* 带头链表结构体 */
struct llist {
    int size; // 存储有效结点需要内存分配大小
    struct llist_node_st head;
};

LLIST *llist_create(int initsize)
{
    struct llist *new;

    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;

    new->size      = initsize;
    new->head.prev = &new->head; // 闭环
    new->head.next = &new->head;

    return new;
}

void llist_destroy(LLIST *list)
{
    struct llist *p = list;
    struct llist_node_st *cur, *next;
    for (cur = &p->head; cur != &p->head; cur = next) {
        next = cur->next; // 获取下一个结点
        free(cur);
    }
    free(p);
}

int llist_insert(LLIST *list, const void *data, int mode)
{
    struct llist *p = list;
    struct llist_node_st *newnode;

    newnode = malloc(sizeof(*newnode) + p->size);
    if (newnode == NULL)
        return -1;
    memcpy(newnode->data, data, p->size);

    // 判断是头插还是尾插
    if (mode == HEAD_INSERT) {
        newnode->prev = &p->head;
        newnode->next = p->head.next;
    }
    else if (mode == TAIL_INSERT) {
        newnode->prev = p->head.prev;
        newnode->next = &p->head;
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
    struct llist *p = list;
    struct llist_node_st *cur;

    // 遍历查找比较用户值与有效结点的值是否相等,相等返回有效结点,不等返回头结点
    for (cur = p->head.next; cur != &p->head; cur = cur->next) {
        if (compare(key, cur->data) == 0)
            break;
    }

    return cur;
}

void *llist_find(LLIST *list, void *key, llist_compare *compare)
{
    struct llist *p = list;
    struct llist_node_st *node;
    node = find_(p, key, compare);
    if (node == &p->head)
        return NULL;

    return node->data;
}

int llist_delete(LLIST *list, void *key, llist_compare *compare)
{
    struct llist *p = list;
    struct llist_node_st *node;

    node = find_(p, key, compare);
    if (node == &p->head)
        return -1;

    node->prev->next = node->next; // 断链
    node->next->prev = node->prev;

    free(node);

    return 0;
}

int llist_fetch(LLIST *list, void *key, llist_compare *compare, void *data)
{
    struct llist *p = list;
    struct llist_node_st *node;

    node = find_(list, key, compare);
    if (node == &p->head)
        return -1;

    // 先断链然后将查找到的有效结点赋值给用户后在销毁有效结点
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (data != NULL)
        memcpy(data, node->data, p->size);

    free(node);

    return 0;
}

int llist_travel(LLIST *list, llist_print *print_cb)
{
    struct llist *p = list;
    struct llist_node_st *cur;

    for (cur = p->head.next; cur != &p->head; cur = cur->next) {
        // 由于不知道用户的数据结构,所有需要用户自行处理打印
        print_cb(cur->data);
    }
    printf("\n\n");

    return 0;
}

int llist_get_size(LLIST *list)
{
    struct llist *p = list;
    struct llist_node_st *cur;
    int count = 0;

    for (cur = p->head.next; cur != &p->head; cur = cur->next)
        count++;

    return count;
}