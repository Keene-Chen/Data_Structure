/**
 * @file    : list.h
 * @author  : KeeneChen
 * @date    : 2023.09.13-14:08:50
 * @details : list
 */

#ifndef __LIST_H___
#define __LIST_H___

struct node_st {
    void *data;
    struct node_st *next;
};
typedef struct node_st List;
typedef void (*print_cb)(void *data);
typedef int (*compare_cb)(void *data1, void *data2);

List *list_init();

void list_destory(List *list);

int list_tail_insert(List *list, void *data);

int list_travel(List *list, print_cb print);

int list_delete(List *list, void *data, compare_cb compare_equl);

int list_reverse(List *list);

int list_bubble_sort(List *list, compare_cb compare);

List *list_merge(List *list1, List *list2, compare_cb compare);

int list_has_cycle(List *list);

#endif //__LIST_H___