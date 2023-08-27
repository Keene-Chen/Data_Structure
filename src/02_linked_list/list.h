/**
 * @file    : list.h
 * @author  : KeeneChen
 * @date    : 2022.08.31-12:51:04
 * @details : list
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1.0"

#define isNULL(x)    \
    if ((x) == NULL) \
        return;

// 结点结构体
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

// 链表结构体
typedef struct list_s {
    node_t header;
    int size;
} list_t;

// 重命名链表结构体,防止用户修改
typedef void *linklist;

/* 单链表 API */
/**
 * @brief  初始化链表
 * @return linklist
 */
linklist list_init(void);

/**
 * @brief  销毁链表
 * @param  list 链表
 * @return void
 */
void list_destory(linklist list);

/**
 * @brief  插入元素
 * @param  list 链表
 * @param  index 插入索引
 * @param  value 插入值
 * @return void
 */
void list_insert(linklist list, int index, void *value);

/**
 * @brief  遍历链表
 * @param  list 链表
 * @param  print_cb 用于打印的回调函数
 * @return void
 */
void list_foreach(linklist list, void (*print_cb)(void *));

/**
 * @brief  根据索引删除结点
 * @param  list 链表
 * @param  index 删除索引
 * @return void
 */
void list_delete_by_index(linklist list, int index);

/**
 * @brief  根据值删除结点
 * @param  list 链表
 * @param  index 删除索引
 * @param  compare_cb 用于比较链表中元素值的回调函数
 * @return void
 */
void list_delete_by_value(linklist list, void *value, int (*compare_cb)(void *, void *));

/**
 * @brief  清空链表
 * @param  list 链表
 * @return void
 */
void list_clear(linklist list);

/**
 * @brief  获取链表长度
 * @param  list 链表
 * @return int 链表长度
 */
int list_get_size(linklist list);

/**
 * @brief  返回链表中的第一个/最后一个元素
 * @param  list 链表
 * @return void* 链表中的元素
 */
void *list_first(linklist list);
void *list_last(linklist list);

/**
 * @brief  链表逆序
 * @param  list 链表
 * @return void
 */
void list_reverse(linklist list);

char *list_get_version();

#endif // __LIST_H__