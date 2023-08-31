#include "double_circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief  list_create 初始化链表,创建头结点用来管理链表
 * @param  int initsize 有效结点 malloc 大小
 * @return linkedlist 带头结点的链表
 */
linkedlist list_create(int initsize)
{
    // 校验参数是否合法
    if (initsize == 0)
        return NULL;

    // 初始化带头结点的链表
    struct list *llist = (struct list *)malloc(sizeof(struct list));
    if (llist == NULL)
        return NULL;
    llist->head = (struct node *)malloc(sizeof(struct node));

    llist->size       = initsize; // 记录有效结点待分配大小
    llist->head->data = NULL;     // 防止野指针
    llist->head->prev = llist->head;
    llist->head->next = llist->head; // 闭环

    return llist;
}

/**
 * @brief  list_destroy 释放链表
 * @param  linedlist list 带头链表
 * @return void
 */
void list_destroy(linkedlist list)
{
    if (list == NULL)
        exit(EXIT_FAILURE);

    // 将void*转换为带头结点的链表结构
    struct list *llist = list;

    // 创建临时结点操作链表
    struct node *cur, *next;
    for (cur = llist->head; cur != llist->head; cur = next) {
        next = cur->next; // 保存下一结点地址
        free(cur->data);  // 释放当前结点的数据源
        free(cur);        // 释放当前结点
    }
    free(llist);
}

/**
 * @brief  list_insert 链表插入
 * @param  linedlist list 带头链表
 * @param  void *data 待插入数据
 * @param  int mode 插入模式
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int list_insert(linkedlist list, void *data, int mode)
{
    // 参数合法性校验
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;
    if (mode == HEAD_INSERT && mode == TAIL_INSERT)
        mode = HEAD_INSERT;

    struct list *llist = (struct list *)list;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
        return -1;
    //! new_node->data = (void *)malloc(sizeof(llist->size));
    //! 由于真实的数据结构被隐藏了,无法使用sizeof得出用户传来的结构大小
    new_node->data = (void *)malloc(llist->size);
    if (new_node->data == NULL)
        return -1;
    // new_node->data = data;
    memcpy(new_node->data, data, llist->size);

    // 判断插入模式
    if (mode == HEAD_INSERT) {
        // 头插
        new_node->prev = llist->head;
        new_node->next = llist->head->next;
        // new_node->prev->next = new_node;
        // new_node->next->prev = new_node;
    }
    else if (mode == TAIL_INSERT) {
        // 尾插
        new_node->prev = llist->head->prev;
        new_node->next = llist->head;
        // new_node->prev->next = new_node;
        // new_node->next->prev = new_node;
    }
    else {
        return -1;
    }
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;

    return 0;
}

/**
 * @brief  find_ 辅助函数
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return 是否查找到对应key值的结点
 * @retval struct node * 指针
 * @retval list->head 头结点
 */
static struct node *find_(linkedlist list, void *key, node_compare *compare_cb)
{
    struct list *llist = list;
    struct node *temp  = llist->head;

    // !BUG 待修改 while 方式遍历
    // while (temp->next != llist->head) {
    //     temp = temp->next;
    //     if (compare_cb(key, temp->next->data))
    //         break;
    // }
    // return temp->next;

    struct node *cur = NULL;
    for (cur = llist->head->next; cur != llist->head; cur = cur->next) {
        if (compare_cb(key, cur->data))
            break;
    }
    return cur;
}

/**
 * @brief  list_find 查找链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return void* 是否查找到对应 key 值的结点
 * @retval 非空  查找到对应 key 值的结点
 * @retval NULL 未查找到
 */
void *list_find(linkedlist list, void *key, node_compare *compare_cb)
{
    if (list == NULL)
        return NULL;
    if (key == NULL)
        return NULL;
    if (compare_cb == NULL)
        return NULL;

    return find_(list, key, compare_cb)->data;
}

/**
 * @brief  list_delete 删除链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int list_delete(linkedlist list, void *key, node_compare *compare_cb)
{
    if (list == NULL)
        return -1;
    if (key == NULL)
        return -1;
    if (compare_cb == NULL)
        return -1;

    struct list *llist = list;

    struct node *temp = find_(list, key, compare_cb);
    if (temp == llist->head)
        return -1;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp->data);
    free(temp);

    return 0;
}

/**
 * @brief  list_fetch 获取并删除链表中的值
 * @param  linedlist list 带头链表
 * @param  void *key 带比较的值
 * @param  node_compare *compare_cb 用户传来的比较函数指针
 * @return int 是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_fetch(linkedlist list, void *key, node_compare *compare_cb, void *data)
{
    if (list == NULL)
        return -1;
    if (key == NULL)
        return -1;
    if (compare_cb == NULL)
        return -1;

    struct list *llist = list;

    struct node *temp = find_(list, key, compare_cb);
    if (temp == llist->head)
        return -1;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp != NULL)
        memcpy(data, temp->data, llist->size);
    free(temp->data);
    free(temp);

    return 0;
}

/**
 * @brief  list_foreach 遍历链表中的值
 * @param  linedlist list 带头链表
 * @param  node_print *print_cb 用户传来的打印函数
 * @return int 遍历是否成功
 * @retval 0   遍历成功
 * @retval -1  遍历失败
 */
int list_foreach(linkedlist list, node_print *print_cb)
{
    if (list == NULL)
        return -1;
    if (print_cb == NULL)
        return -1;

    struct list *llist = (struct list *)list;
    struct node *cur   = NULL;
    for (cur = llist->head->next; cur != llist->head; cur = cur->next) {
        print_cb(cur->data);
    }
    printf("\n\n");

    return 0;
}
