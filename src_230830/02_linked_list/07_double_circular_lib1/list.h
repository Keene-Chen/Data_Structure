/**
 * @file    : list.h
 * @author  : KeeneChen
 * @date    : 2023.08.31-09:39:39
 * @details : 双向循环链表库封装—01
 * create 创建链表
 * insert 链表插入结点（头插/尾插）
 * find 查找链表中的结点
 * delete 删除链表中的结点
 * fetch 获取并删除链表中的结点
 * travel 遍历链表中的结点
 * @todo : 链表排序、链表逆序、获取链表第一个有效结点、获取链表最后一个有效结点
 */

#ifndef __LIST_H__
#define __LIST_H__

/* 插入模式 */
#define HEAD_INSERT 1
#define TAIL_INSERT 2

/**
 * 函数指针定义回调函数类型
 * 用于用户输出和用户结构体比较
 */
typedef void llist_print(const void *data);
typedef int llist_compare(const void *value1, const void *value2);

/* 有效结点结构体 */
struct llist_node_st {
    void *data; // 万能指针接收用户数据
    struct llist_node_st *prev;
    struct llist_node_st *next;
};

/* 带头链表结构体 */
typedef struct llist {
    int size; // 存储有效结点需要内存分配大小
    struct llist_node_st head;
} LLIST;

/**
 * @brief  llist_create 创建带头结点管理的链表
 * @param  int initsize 用户数据结构体大小
 * @return LLIST *list 指向链表的指针
 */
LLIST *llist_create(int initsize);

/**
 * @brief  llist_destroy 销毁链表
 * @param  LLIST *list 指向链表的指针
 * @return void
 */
void llist_destroy(LLIST *list);

/**
 * @brief  llist_insert 链表插入有效结点
 * @param  LLIST *list 指向链表的指针
 * @param  const void *data 用户数据
 * @param  int mode 插入模式
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int llist_insert(LLIST *list, const void *data, int mode);

/**
 * @brief  llist_find 查找链表中的有效结点
 * @param  LLIST *list 指向链表的指针
 * @param  const void *key 待查找的值
 * @param  llist_compare *compare 用户数据比较函数
 * @return void* 是否查找到有效结点
 * @retval NULL 未查找到
 * @retval 非空  查找到
 */
void *llist_find(LLIST *list, void *key, llist_compare *compare);

/**
 * @brief  llist_delete 删除链表中的有效结点
 * @param  LLIST *list 指向链表的指针
 * @param  const void *key 待删除的值
 * @param  llist_compare *compare 用户数据比较函数
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int llist_delete(LLIST *list, void *key, llist_compare *compare);

/**
 * @brief  llist_fetch 获取并删除链表中的有效结点
 * @param  LLIST *list 指向链表的指针
 * @param  const void *key 待删除的值
 * @param  llist_compare *compare 用户数据比较函数
 * @param  void *data 获取到的有效结点
 * @return int 获取并删除是否成功
 * @retval 0   获取并删除成功
 * @retval -1  获取并删除失败
 */
int llist_fetch(LLIST *list, void *key, llist_compare *compare, void *data);

/**
 * @brief  llist_travel 遍历链表中的有效结点
 * @param  LLIST *list 指向链表的指针
 * @param  llist_print *print_cb 用户打印函数
 * @return int 遍历是否成功
 * @retval 0   遍历成功
 * @retval -1  遍历失败
 */
int llist_travel(LLIST *list, llist_print *print_cb);

/**
 * @brief  llist_get_size 获取链表长度
 * @param  LLIST *list 指向链表的指针
 * @return int 链表长度
 */
int llist_get_size(LLIST *list);

#endif // __LIST_H__