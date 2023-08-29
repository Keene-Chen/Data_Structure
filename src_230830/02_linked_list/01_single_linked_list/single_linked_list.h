/**
 * @file    : single_linked_list.h
 * @author  : KeeneChen
 * @date    : 2023.08.25-10:51:51
 * @details : single_linked_list
 */

#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 打印链表长度 */
#define SHOW(x)                                         \
    do {                                                \
        printf("\n---- %s ----\n", x);                  \
        printf("size: %d\n", linkedlist_get_len(list)); \
    } while (0);

/* 链表结点 */
struct node {
    void *data;
    struct node *next;
};

/* 链表 */
struct list {
    struct node header;
    int size;
};

/**
 * 重命名链表,防止用户修改
 * void* 是无法直接使用的,需要强制转换
 */
typedef void *linkedlist;

/**
 * @brief  linkedlist_init 单链表初始化
 * @return linklist(aka typedef void*) 单链表
 */
linkedlist linkedlist_init(void);

/**
 * @brief  linkedlist_destory 销毁链表
 * @param  linkedlist list 链表
 * @return void
 */
void linkedlist_destory(linkedlist list);

/**
 * @brief  linkedlist_insert 链表插入数据
 * @param  linkedlist list 链表
 * @param  int index 待插入位置
 * @param  void* data 待插入数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int linkedlist_insert(linkedlist list, int index, void *data);

/**
 * @brief  linkedlist_insert_tail 链表尾插法插入数据
 * @param  linkedlist list 链表
 * @param  void* data 待插入数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int linkedlist_insert_tail(linkedlist list, void *data);

/**
 * @brief  linkedlist_foreach 遍历链表
 * @param  linkedlist list 链表
 * @param  print_cb 带输出的回调函数
 * @return void
 */
void linkedlist_foreach(linkedlist list, void (*print_cb)(void *));

/**
 * @brief  get_linkedlist_len 获取链表长度
 * @param  linkedlist list 链表
 * @return int 链表长度
 */
int linkedlist_get_len(linkedlist list);

/**
 * @brief  linkedlist_del_by_index 根据索引删除元素
 * @param  linkedlist list 链表
 * @param  int index 待删除索引
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int linkedlist_del_by_index(linkedlist list, int index);

/**
 * @brief  linkedlist_del_by_value 根据值删除元素
 * @param  linkedlist list 链表
 * @param  void* data 待删除的数据
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int linkedlist_del_by_value(linkedlist list, void *data, int (*compare_cb)(void *, void *));

/**
 * @brief  linkedlist_clear 清空链表
 * @param  linkedlist list 链表
 * @return int
 * @return int 清空是否成功
 * @retval 0   清空成功
 * @retval -1  清空失败
 */
int linkedlist_clear(linkedlist list);

/**
 * @brief  获取链表第一个元素
 * @param  linkedlist list 链表
 * @return void
 */
void *linkedlist_first(linkedlist list);

/**
 * @brief  获取链表最后一个元素
 * @param  linkedlist list 链表
 * @return void
 */
void *linkedlist_last(linkedlist list);

/**
 * @brief  链表反转
 * @param  linkedlist list 链表
 * @return void
 */
void linkedlist_reverse(linkedlist list);
#endif // __SINGLE_LINKED_LIST_H__