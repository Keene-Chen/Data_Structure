/**
 * @file    : list.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-12:50:57
 * @details : list
 */

#include "list.h"

linklist list_init(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    if (list == NULL)
        return NULL;

    list->header.data = NULL;
    list->header.next = NULL;
    list->size        = 0;

    return list;
}

void list_destory(linklist list)
{
    isNULL(list);
    list_clear(list);
    free(list);
    list = NULL;
}

void list_insert(linklist list, int index, void *value)
{
    isNULL(list);
    isNULL(value);

    // 将list还原为linklist_t
    list_t *llist = list;

    // 无效索引强制尾插
    if (index < 0 || index > llist->size)
        index = llist->size;

    // 找到插入结点的前驱结点
    node_t *temp = &llist->header;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // 创建一个新结点
    node_t *node = malloc(sizeof(node_t));
    node->data   = value;
    node->next   = NULL;

    // 插入结点,尾插,插入顺序不能改变
    node->next = temp->next;
    temp->next = node;

    // 更新链表长度
    llist->size++;
}

void list_foreach(linklist list, void (*print_cb)(void *))
{
    isNULL(list);

    // 将list还原为list_t
    list_t *llist = list;

    // 使用临时结点指向头结点的指针域
    node_t *temp = llist->header.next;
    for (int i = 0; i < llist->size; i++) {
        print_cb(temp->data);
        temp = temp->next;
    }
}

void list_delete_by_index(linklist list, int index)
{
    isNULL(list);
    list_t *llist = list;
    if (index < 0 || index > llist->size - 1)
        return;

    node_t *temp = &llist->header;

    // 找到插入结点的前驱结点
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // 删除结点
    node_t *delete = temp->next;
    temp->next     = delete->next;
    free(delete);
    delete = NULL;

    // 更新链表长度
    llist->size--;
}

void list_delete_by_value(linklist list, void *value, int (*compare_cb)(void *, void *))
{
    isNULL(list);
    isNULL(value);

    list_t *llist = list;
    // 创建两个辅助结点用于遍历查找值
    node_t *prev = &llist->header;
    node_t *temp = prev->next;

    for (int i = 0; i < llist->size; i++) {
        // 使用回调函数比较用户传的值
        if (compare_cb(temp->data, value)) {
            // 删除结点
            prev->next = temp->next;
            free(temp);
            temp = NULL;

            // 更新链表长度
            llist->size--;
            break;
        }
        else {
            // 未找到结点,指针后移
            prev = temp;
            temp = temp->next;
        }
    }
}

void list_clear(linklist list)
{
    isNULL(list);
    list_t *llist = list;
    node_t *temp  = llist->header.next;

    // 循环删除结点
    for (int i = 0; i < llist->size; i++) {
        node_t *next = temp->next;
        free(temp);
        temp = next;
    }

    llist->header.data = NULL;
    llist->header.next = NULL;
    llist->size        = 0;
}

int list_get_size(linklist list)
{
    if (list == NULL)
        return -1;
    list_t *llist = list;
    return llist->size;
}

void *list_first(linklist list)
{
    if (list == NULL)
        return NULL;
    list_t *llist = list;
    node_t *temp  = llist->header.next;
    return temp->data;
}

void *list_last(linklist list)
{
    if (list == NULL)
        return NULL;
    list_t *llist = list;
    node_t *temp  = &llist->header;

    // 找到链表最后一个结点
    for (int i = 0; i < llist->size; i++) {
        temp = temp->next;
    }

    return temp->data;
}

void list_reverse(linklist list)
{
    isNULL(list);
    list_t *llist = list;
    node_t *temp  = llist->header.next;
    node_t *prev  = NULL;

    for (int i = 0; i < llist->size; i++) {
        node_t *next = temp->next;
        temp->next   = prev;
        // 此时判断 next 是否为 NULL，如果成立则退出循环
        if (next == NULL) {
            break;
        }
        // 整体向后移动 3 个指针
        prev = temp;
        temp = next;
        next = next->next;
        // 最后修改 head 头指针的指向
        llist->header.next = temp;
    }
}

char *list_get_version()
{
    return VERSION;
}