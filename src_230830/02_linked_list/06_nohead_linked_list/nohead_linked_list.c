/**
 * @file    : nohead_linked_list.c
 * @author  : KeeneChen
 * @date    : 2023.08.28-20:47:23
 * @details : nohead_linked_list
 */

#include "nohead_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief  list_insert 链表插入
 * @param  list **l 链表头指针的地址,二级指针是为了修改一级指针的值,需要判断一级指针是否为空
 * @param  datatype *data 插入的数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int list_insert(list **l, datatype *data)
{
    if (l == NULL)
        return -1;
    if (data == NULL)
        return -1;

    list *new_node = malloc(sizeof(list));
    if (new_node == NULL)
        return -1;

    new_node->data = data;
    new_node->next = NULL;

    new_node->next = *l;
    *l             = new_node;

    return 0;
}

/**
 * @brief  list_delete 链表删除
 * @param  list **l 链表头指针的地址
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int list_delete(list **l)
{
    if (*l == NULL)
        return -1;

    list *p = *l;
    if (!p) {
        return -1;
    }

    *l = p->next;
    free(p);
    return 0;
}

/**
 * @brief  list_destroy 链表销毁
 * @param  list **l 链表头指针的地址
 * @return void
 */
void list_destroy(list **l)
{
    if (*l == NULL)
        return;

    list *p = *l;
    while (p != NULL) {
        list *tmp = p;
        p         = p->next;
        free(tmp);
    }
}

/**
 * @brief  list_display 链表打印
 * @param  list *l 链表头指针
 * @param  void (*print_cb)(datatype *data) 打印回调函数
 * @return void
 */
void list_display(list *l, void (*print_cb)(datatype *data))
{
    if (l == NULL)
        exit(EXIT_FAILURE);

    list *p = l;
    while (p != NULL) {
        print_cb(p->data);
        p = p->next;
    }
    printf("\n");
}
