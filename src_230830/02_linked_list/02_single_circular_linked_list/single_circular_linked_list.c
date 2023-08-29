/**
 * @file    : single_circular_linked_list.c
 * @author  : KeeneChen
 * @date    : 2023.08.29-14:07:10
 * @details : 循环单链表实现API
 * !bug     : 顺序插入和按值删除与预期不符
 */

#include "single_circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief  循环单链表初始化
 * @return linkedlist 循环单链表
 */
linkedlist list_init(void)
{
    struct list *cllist = malloc(sizeof(struct list));
    if (cllist == NULL) {
        return NULL;
    }

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = NULL;
    new_node->next = NULL;

    cllist->head = cllist->tail = new_node;
    cllist->tail->next          = cllist->head;
    cllist->size                = 0;

    return cllist;
}

/**
 * @brief  尾插法插入结点
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_tail_insert(linkedlist list, void *data)
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        return -1;
    new_node->data = data;
    new_node->next = NULL;

    struct list *cllist = list;
    cllist->tail->next  = new_node;     // 将该结点插入
    cllist->tail        = new_node;     // 更改管理结点中尾结点的指向
    cllist->tail->next  = cllist->head; // 重新形成环状
    cllist->size++;                     // 将有效结点数加一

    return 0;
}

/**
 * @brief  尾插法插入结点
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_head_insert(linkedlist list, void *data)
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        return -1;
    new_node->data = data;
    new_node->next = NULL;

    struct list *cllist = list;
    // 将结点插入
    new_node->next     = cllist->head->next;
    cllist->head->next = new_node;
    // 如果这是一个有效结点，那么需要更改管理结点中尾指针的指向
    if (cllist->head == cllist->tail) {
        cllist->tail = new_node;
    }
    cllist->size++; // 有效结点数加一

    return 0;
}

/**
 * @brief  尾删结点
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_tail_delete(linkedlist list)
{
    if (list == NULL)
        return -1;

    struct list *cllist = list;
    // 如果没有可删除的有效结点则退出
    if (cllist->size == 0)
        return -1;

    // 查找要删除结点的上一结点
    struct node *temp = cllist->head;
    while (temp->next != cllist->tail) {
        temp = temp->next;
    }

    // 删除尾结点
    free(cllist->tail);

    // 将之前查找到的结点(倒数第二个结点)设置为新的尾结点
    cllist->tail       = temp;
    cllist->tail->next = cllist->head; // 重新形成环
    cllist->size--;                    // 有效结点数减一

    return 0;
}

/**
 * @brief  头删结点
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_head_delete(linkedlist list)
{
    if (list == NULL)
        return -1;

    struct list *cllist = list;
    // 如果没有有效结点可删除则退出
    if (cllist->size == 0)
        return -1;

    // 删除有效头结点
    struct node *temp  = cllist->head->next;
    cllist->head->next = temp->next;
    free(temp);

    // 如果此时链表内只有一个有效结点，那么需要改变尾指针的指向
    if (cllist->size == 1) {
        cllist->tail = cllist->head;
    }
    cllist->size--; // 将有效结点数减一

    return 0;
}

/**
 * @brief  排序插入
 * @param  linkedlist 循环单链表
 * @param  void *data 待插入数据
 * @param  int (*compare_cb)(void *value1, void *value2) 比较函数
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_order_insert(linkedlist list, void *data, int (*compare_cb)(void *value1, void *value2))
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct list *cllist = list;
    // 如果链表为空，那么进行尾插
    if (cllist->size == 0) {
        list_tail_insert(cllist, data);
        return 0;
    }

    // 否则寻找结点的插入位置
    struct node *temp = cllist->head;
    while (temp->next != cllist->tail) {
        temp = temp->next;
    }

    // 如果插入位置在尾部，那么进行尾插，否则在中间插入
    if (temp->next == cllist->tail && compare_cb(temp->next->data, data)) {
        list_tail_insert(cllist, data); // 尾插
    }
    else {
        // 中间插入
        struct node *new_node = malloc(sizeof(struct node));
        if (new_node == NULL)
            return -1;
        new_node->data = data;

        new_node->next = temp->next;
        temp->next     = new_node;

        cllist->size++;
    }

    return 0;
}

/**
 * @brief  按值删除
 * @param  linkedlist 循环单链表
 * @param  void *data 待删除数据
 * @param  int (*compare_cb)(void *value1, void *value2) 比较函数
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_val_delete(linkedlist list, void *data, int (*compare_cb)(void *value1, void *value2))
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct list *cllist = list;
    // 如果链表为空，那么退出
    if (cllist->size == 0)
        return -1;

    // 查找要删除结点的位置
    // 从有效结点的首位置进行查找
    struct node *temp = cllist->head;
    while (temp != cllist->head && compare_cb(temp->data, data))
        temp = temp->next;

    // 如果没有查找到则无需删除
    if (temp == NULL) {
        printf("未找到要删除的数据\n");
        return -1;
    }
    // 如果要删除结点是尾结点，那么可进行尾删
    if (temp == cllist->tail) {
        list_tail_delete(list);
    }
    else // 如果在中间位置，那么把要删除结点的下一结点拷贝到当前要删除结点，然后删除下一结点
    {
        struct node *new_node = temp->next;
        // 把要删除结点的下一结点拷贝到当前要删除结点
        temp->data = new_node->data;
        temp->next = new_node->next;
        // 删除下一结点
        free(new_node);
        cllist->size--; // 有效结点数减一
    }

    return 0;
}

/**
 * @brief  清空链表
 * @param  linkedlist 循环单链表
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_clear(linkedlist list)
{
    if (list == NULL)
        return -1;

    struct list *cllist = list;
    struct node *temp   = cllist->head->next; // 指向第一个有效结点
    while (temp != cllist->head)              // 将所有有效结点释放清除
    {
        cllist->head->next = temp->next;
        free(temp);
        temp = cllist->head->next;
    }
    // 设置管理结点中的尾结点指向和头结点的指针域指向
    cllist->tail       = cllist->head;
    cllist->tail->next = cllist->head;
    cllist->size       = 0; // 有效结点数为0

    return 0;
}

/**
 * @brief 销毁链表
 * @param  linkedlist 循环单链表
 * @return int 销毁是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_destroy(linkedlist list)
{
    if (list == NULL) {
        return -1;
    }

    struct list *cllist = list;
    list_clear(cllist);
    free(cllist->head); // 清除头结点
    cllist->head = cllist->tail = NULL;

    return 0;
}

/**
 * @brief  遍历链表
 * @param  linkedlist 循环单链表
 * @param  void (*print_cb)(void *data) 打印函数
 * @return int 遍历是否成功
 * @retval 0   成功
 * @retval -1  失败
 */
int list_foreach(linkedlist list, void (*print_cb)(void *data))
{
    if (list == NULL)
        return -1;

    struct list *cllist = list;
    struct node *temp   = cllist->head->next; // 指向有效结点部分
    while (temp != cllist->head)              // 将有效结点内的数据输出
    {
        print_cb(temp->data);
        temp = temp->next; // 下移
    }
    printf("NULL\n\n");
    return 0;
}

/**
 * @brief  获取链表长度
 * @param  linkedlist 循环单链表
 * @return int 链表长度
 * @retval >=0 链表长度
 * @retval -1  失败
 */
int list_get_size(linkedlist list)
{
    if (list == NULL)
        return -1;

    struct list *cllist = list;
    return cllist->size;
}