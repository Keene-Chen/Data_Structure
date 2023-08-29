/**
 * @file    : single_linked_list.c
 * @author  : KeeneChen
 * @date    : 2023.08.25-10:55:22
 * @details : single_linked_list
 */

#include "single_linked_list.h"

/**
 * @brief  linkedlist_init 单链表初始化
 * @return linklist(aka typedef void*) 单链表
 */
linkedlist linkedlist_init(void)
{
    // 链表初识化分配空间
    struct list *list = (struct list *)malloc(sizeof(struct list));
    if (list == NULL)
        return NULL;

    // 链表头结点为空
    list->header.data = NULL;
    list->header.next = NULL;
    list->size        = 0;

    return list;
}

/**
 * @brief  linkedlist_destory 销毁链表
 * @param  linkedlist list 链表
 * @return void
 */
void linkedlist_destory(linkedlist list)
{
    if (list == NULL)
        exit(EXIT_FAILURE);

    linkedlist_clear(list);
    free(list);
    list = NULL;
}

/**
 * @brief  linkedlist_insert 链表插入数据
 * @param  linkedlist list 链表
 * @param  int index 待插入位置
 * @param  void* data 待插入数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int linkedlist_insert(linkedlist list, int index, void *data)
{
    // 参数合法性校验
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    // 将void*转换为struct list
    struct list *llist = list;

    // 无效索引强制尾插
    if (index < 0 || index > llist->size)
        index = llist->size;

    // 查找待插入结点的前驱结点
    struct node *temp = &llist->header;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // 创建新结点
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data        = data;
    new_node->next        = NULL;

    // 使用头插法插入结点
    new_node->next = temp->next;
    temp->next     = new_node;

    // 更新链表长度
    llist->size++;

    return 0;
}

/**
 * @brief  linkedlist_insert_tail 链表尾插法插入数据
 * @param  linkedlist list 链表
 * @param  void* data 待插入数据
 * @return int 插入是否成功
 * @retval 0   插入成功
 * @retval -1  插入失败
 */
int linkedlist_insert_tail(linkedlist list, void *data)
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct list *llist = list;
    struct node *temp  = &llist->header;
    for (int i = 0; i < llist->size; i++) {
        temp = temp->next;
    }

    // 创建新结点
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data        = data;
    new_node->next        = NULL;

    // 使用尾插法插入结点
    temp->next = new_node;

    // 更新链表长度
    llist->size++;

    return 0;
}

/**
 * @brief  linkedlist_foreach 遍历链表
 * @param  linkedlist list 链表
 * @param  print_cb 带输出的回调函数
 * @return void
 */
void linkedlist_foreach(linkedlist list, void (*print_cb)(void *))
{
    if (list == NULL)
        exit(EXIT_FAILURE);

    // 使用临时结点指向头结点的指针域
    struct list *llist = list;
    struct node *temp  = llist->header.next;
    for (int i = 0; i < llist->size; i++) {
        // 由于数据为void*类型,需要用户自行定义输出样式
        print_cb(temp->data);
        temp = temp->next;
    }
}

/**
 * @brief  get_linkedlist_len 获取链表长度
 * @param  linkedlist list 链表
 * @return int 链表长度
 */
int linkedlist_get_len(linkedlist list)
{
    struct list *llist = list;

    return llist->size;
}

/**
 * @brief  linkedlist_del_by_index 根据索引删除元素
 * @param  linkedlist list 链表
 * @param  int index 待删除索引
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int linkedlist_del_by_index(linkedlist list, int index)
{
    // 校验数据合法性
    if (list == NULL)
        return -1;
    struct list *llist = list;
    if (index < 0 || index > llist->size - 1)
        return -1;

    struct node *temp = &llist->header;

    // 待删除结点的前驱结点
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // 删除结点
    struct node *new_node = temp->next;
    temp->next            = new_node->next;
    free(new_node);
    new_node = NULL;

    // 更新链表长度
    llist->size--;

    return 0;
}

/**
 * @brief  linkedlist_del_by_value 根据值删除元素
 * @param  linkedlist list 链表
 * @param  void* data 待删除的数据
 * @return int 删除是否成功
 * @retval 0   删除成功
 * @retval -1  删除失败
 */
int linkedlist_del_by_value(linkedlist list, void *data, int (*compare_cb)(void *, void *))
{
    if (list == NULL)
        return -1;
    if (data == NULL)
        return -1;

    struct list *llist = list;
    // 创建两个辅助结点用于遍历查找值
    struct node *prev = &llist->header;
    struct node *temp = prev->next;

    for (int i = 0; i < llist->size; i++) {
        if (compare_cb(temp->data, data)) {
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

    return 0;
}

/**
 * @brief  linkedlist_clear 清空链表
 * @param  linkedlist list 链表
 * @return int
 * @return int 清空是否成功
 * @retval 0   清空成功
 * @retval -1  清空失败
 */
int linkedlist_clear(linkedlist list)
{
    if (list == NULL)
        return -1;
    struct list *llist = list;
    struct node *temp  = llist->header.next;

    // 循环删除结点
    for (int i = 0; i < llist->size; i++) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    llist->header.data = NULL;
    llist->header.next = NULL;
    llist->size        = 0;

    return 0;
}

/**
 * @brief  获取链表第一个元素
 * @param  linkedlist list 链表
 * @return void
 */
void *linkedlist_first(linkedlist list)
{
    if (list == NULL)
        return NULL;
    struct list *llist = list;
    struct node *temp  = llist->header.next;
    return temp->data;
}

/**
 * @brief  获取链表最后一个元素
 * @param  linkedlist list 链表
 * @return void
 */
void *linkedlist_last(linkedlist list)
{
    if (list == NULL)
        return NULL;
    struct list *llist = list;
    struct node *temp  = &llist->header;

    // 找到链表最后一个结点
    for (int i = 0; i < llist->size; i++) {
        temp = temp->next;
    }

    return temp->data;
}

/**
 * @brief  链表反转
 * @param  linkedlist list 链表
 * @return void
 */
void linkedlist_reverse(linkedlist list)
{
    if (list == NULL)
        exit(EXIT_FAILURE);

    struct list *llist = list;
    struct node *temp  = llist->header.next;
    struct node *prev  = NULL;

    for (int i = 0; i < llist->size; i++) {
        struct node *next = temp->next;
        temp->next        = prev;
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