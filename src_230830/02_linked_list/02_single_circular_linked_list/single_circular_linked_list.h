/**
 * @file    : single_circular_linked_list.h
 * @author  : KeeneChen
 * @date    : 2023.08.29-14:07:04
 * @details : single_circular_linked_list
 */

#ifndef __SINGLE_CIRCULAR_LINKED_LIST_H__
#define __SINGLE_CIRCULAR_LINKED_LIST_H__

struct node {
    void *data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
    int size;
};

typedef void *linkedlist;

/**
 * @brief  循环单链表初始化
 * @return linkedlist 循环单链表
 */
linkedlist list_init(void);

/**
 * @brief  尾插法插入结点
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_tail_insert(linkedlist list, void *data);

/**
 * @brief  尾插法插入结点
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_head_insert(linkedlist list, void *data);

/**
 * @brief  尾删结点
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_tail_delete(linkedlist list);

/**
 * @brief  头删结点
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_head_delete(linkedlist list);

/**
 * @brief  排序插入
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @param  int (*compare_cb)(void *value1, void *value2) 比较函数
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_order_insert(linkedlist list, void *data, int (*compare_cb)(void *value1, void *value2));

/**
 * @brief  按值删除
 * @param  linkedlist 循环单链表
 * @param  void *data 待删除数据
 * @param  int (*compare_cb)(void *value1, void *value2) 比较函数
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_val_delete(linkedlist list, void *data, int (*compare_cb)(void *value1, void *value2));

/**
 * @brief  清空链表
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_clear(linkedlist list);

/**
 * @brief 销毁链表
 * @param  linkedlist 循环单链表
 * @return int 销毁是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_destroy(linkedlist list);

/**
 * @brief  遍历链表
 * @param  linkedlist 循环单链表
 * @param  void (*print_cb)(void *data) 打印函数
 * @return int 遍历是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_foreach(linkedlist list, void (*print_cb)(void *data));

/**
 * @brief  获取链表长度
 * @param  linkedlist 循环单链表
 * @return int 链表长度
 * @retval >=0 链表长度
 * @retval -1  失败
 */
int list_get_size(linkedlist list);
#endif // __SINGLE_CIRCULAR_LINKED_LIST_H__