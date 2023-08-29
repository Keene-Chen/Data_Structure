/**
 * @file    : nohead_linked_list.h
 * @author  : KeeneChen
 * @date    : 2023.08.28-20:47:19
 * @details : nohead_linked_list
 */

#ifndef __NOHEAD_LINKED_LIST_H__
#define __NOHEAD_LINKED_LIST_H__

typedef void datatype;

typedef struct node_st {
    datatype *data;
    struct node_st *next;
} list;

/**
 * @brief  list_insert 链表插入
 * @param  list **l 链表头指针的地址,二级指针是为了修改一级指针的值,需要判断一级指针是否为空
 * @param  datatype *data 插入的数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int list_insert(list **l, datatype *data);

/**
 * @brief  list_delete 链表删除
 * @param  list **l 链表头指针的地址
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int list_delete(list **l);

/**
 * @brief  list_destroy 链表销毁
 * @param  list **l 链表头指针的地址
 * @return void
 */
void list_destroy(list **l);

/**
 * @brief  list_display 链表打印
 * @param  list *l 链表头指针
 * @param  void (*print_cb)(datatype *data) 打印回调函数
 * @return void
 */
void list_display(list *l, void (*print_cb)(datatype *data));

#endif // __NOHEAD_LINKED_LIST_H__