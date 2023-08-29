/**
 * @file    : head_linked_list.h
 * @author  : KeeneChen
 * @date    : 2023.08.27-11:38:09
 * @details : head_linked_list
 */

#ifndef __HEAD_LINKED_LIST_H__
#define __HEAD_LINKED_LIST_H__

typedef int datatype;

typedef struct node_st {
    datatype data;
    struct node_st *next;
} list;

list *list_create(void);

int list_insert_at(list *l, int i, datatype *data);

int list_order_insert(list *l, datatype *data, int (*compare)(datatype *, datatype *));

int list_delete_at(list *l, int i, datatype *data);

int list_delete(list *l, datatype *data, int compare_cb(datatype *, datatype *));

int list_isempty(list *l);

void list_display(list *l);

void list_destroy(list *l);

#endif // __HEAD_LINKED_LIST_H__