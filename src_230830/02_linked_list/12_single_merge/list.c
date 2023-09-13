/**
 * @file    : list.c
 * @author  : KeeneChen
 * @date    : 2023.09.13-13:18:06
 * @details : 单链表合并、冒泡、反转
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief  list_init 链表初始化
 * @return List *list 带头结点的单链表
 * @note 1.创建新结点并用于表示头结点
 *       2.初始化结点并返回
 */
List *list_init()
{
    List *head = malloc(sizeof(List));
    if (head == NULL)
        return NULL;

    head->data = NULL;
    head->next = NULL;

    return head;
}

/**
 * @brief  list_destory 释放链表包括头结点
 * @param  List *list 带头结点的单链表
 * @return void
 * @note 1.检测参数合法性
 *       2.使用临时指针遍历单链表
 *       3.创建node指针指向遍历当前的指针,防止断链
 *       4.释放当前结点
 */
void list_destory(List *list)
{
    if (list == NULL)
        return;

    List *temp = list;
    while (temp != NULL) {
        List *node = temp;
        temp       = temp->next;
        free(node);
    }
}

/**
 * @brief  list_tail_insert 链表尾插
 * @param  List *list 带头结点的单链表
 * @param  void *data 插入数据
 * @return int 插入是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note 1.检测参数合法性
 *       2.使用临时指针遍历链表,遍历到最后一个结点
 *       3.创建新结点并初始化
 *       4.将链表最后一个结点指向新结点完成插入
 */
int list_tail_insert(List *list, void *data)
{
    if (list == NULL || data == NULL)
        return -1;

    List *temp = list;
    while (temp->next) {
        temp = temp->next;
    }

    List *node = malloc(sizeof(List));
    node->data = data;
    node->next = NULL;

    temp->next = node;

    return 0;
}

/**
 * @brief  list_delete 删除链表中的结点
 * @param  List *list 带头结点的单链表
 * @param  void *data 插入数据
 * @param  compare_cb compare 比较结点数据是否相等
 * @return int 删除是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note 1.检测参数合法性
 *       2.使用临时指针遍历链表,查找待删除结点的前驱结点
 *       3.如果找到就退出循环,否则一直遍历到链表末尾
 *       4.判断结点是否为链表末尾,是就删除，否就返回-1表示未查找到数据
 */
int list_delete(List *list, void *data, compare_cb compare)
{
    if (list == NULL || data == NULL || compare == NULL)
        return -1;

    List *temp = list;
    while (temp->next) {
        if (compare(temp->next->data, data))
            break;
        temp = temp->next;
    }

    if (temp->next) {
        List *cur  = temp->next;
        temp->next = cur->next;
        free(cur);
    }
    else {
        return -1;
    }

    return 0;
}

/**
 * @brief  list_travel 遍历链表中的数据
 * @param  List *list 带头结点的单链表
 * @param  print_cb print 打印回调函数,
 *                        由于不知道用户数据结构只能将打印操作交给用户
 * @return int 遍历是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note 1.检测参数合法性
 *       2.使用临时指针遍历链表
 *       3.打印链表数据,注意错开头结点的数据
 */
int list_travel(List *list, print_cb print)
{
    if (list == NULL || print == NULL)
        return -1;

    List *temp = list;
    while (temp->next) {
        print(temp->next->data);
        temp = temp->next;
    }

    return 0;
}

/**
 * @brief  list_reverse 反转单链表
 * @param  List *list 带头结点的单链表
 * @return int 反转是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note
 * 1.首先,判断传入的链表指针list是否为NULL,如果是则返回-1,表示链表为空
 * 2.创建两个辅助指针cur和prev,分别用来记录当前节点和上一个节点的指针
 * 3.进入循环,循环条件为cur不为NULL
 * 4.在循环内部,首先记录当前节点的下一个节点指针为next,然后将当前节点的next指针指向上一个节点prev,完成反转
 * 5.判断next是否为NULL,如果是则表示已经到达链表末尾,跳出循环
 * 6.更新prev为当前节点cur,将cur更新为next,继续循环
 * 7.循环结束后,将原链表的头节点的next指针指向反转后的链表的头节点
 * 8.返回0,表示操作成功
 */
int list_reverse(List *list)
{
    if (list == NULL)
        return -1;

    List *cur  = list->next;
    List *prev = NULL;

    while (cur) {
        List *next = cur->next;
        cur->next  = prev;
        if (next == NULL)
            break;

        prev       = cur;
        cur        = next;
        next       = next->next;
        list->next = cur;
    }

    return 0;
}

/**
 * @brief  list_bubble_sort 排序单链表
 * @param  List *list 带头结点的单链表
 * @return int 排序是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note
 * 1.校验参数合法性
 * 2.初始化计数器 count 为0,以及三个指针变量 p、q、temp
 * 3.使用指针 p 遍历整个链表,并递增计数器 count,以确定链表的长度
 * 4.接下来,使用两层循环进行冒泡排序外层循环从0到count-1,用于迭代需要比较和交换的元素对
 * 5.内层循环从0到count-i-1,用于比较相邻元素的值并进行排序在每次比较中,使用回调函数
 *   compare 比较 q 指针指向的元素和 p 指针指向的元素
 * 6.如果 compare返回的结果为假（0）,
 *   则交换 q 和 p 指针指向的元素的位置,即交换它们的 next值
 * 7.进行交换后,更新 temp、q、p 的值,将它们分别指向下一个元素的位置
 * 8.循环结束后,链表中的元素已按照指定的比较函数进行了排序
 * 9.函数返回0表示排序成功
 */
int list_bubble_sort(List *list, compare_cb compare)
{
    if (list == NULL)
        return -1;

    int count = 0;
    List *p, *q, *temp;

    p = list;
    while (p->next) {
        count++;
        p = p->next;
    }

    for (int i = 0; i < count - 1; i++) {
        temp = list;
        q    = list->next;
        p    = q->next;

        for (int j = 0; j < count - i - 1; j++) {
            if (!compare(q->data, p->data)) {
                q->next    = p->next;
                p->next    = q;
                temp->next = p;
            }
            temp = temp->next;
            q    = temp->next;
            p    = q->next;
        }
    }

    return 0;
}

/**
 * @brief  list_merge 合并单链表
 * @param  List *list 带头结点的单链表
 * @return int  合并是否成功
 * @retval 0   成功
 * @retval -1  失败
 * @note
 * 1.检验参数合法性
 * 2.创建新头结点 head,并将其指针赋值给 prev,用于记录合并后的链表
 * 3.分别将 list1 和 list2 的下一个节点指针赋值给 p1 和 p2,用于遍历两个链表
 * 4.进入循环,条件是 p1 和 p2 都不为 NULL在每次迭代中,使用 compare 函数进行比较
 *   p1->data 和 p2->data
 * 5.如果 compare 函数返回真（表示 p1->data 小于
 *   p2->data）,则将 prev->next 指向 p1,然后将 p1 指针向后移动一位
 * 6.如果 compare 函数返回假（表示 p1->data 大于等于 p2->data）,
     则将 prev->next 指向 p2,然后将 p2 * 指针向后移动一位
 * 7.在每次迭代的末尾,将 prev 向后移动
 * 8.循环结束后,检查 p1 和 p2 是否还有剩余的节点如果有,
 *   将剩余节点连接到合并后链表的末尾
 * 9.返回合并后的链表 head
 */
List *list_merge(List *list1, List *list2, compare_cb compare)
{
    if (list1 == NULL || list2 == NULL)
        return NULL;

    List *head = malloc(sizeof(List));
    List *prev = head;
    List *p1   = list1->next;
    List *p2   = list2->next;

    while (p1 && p2) {
        if (compare(p1->data, p2->data)) {
            prev->next = p1;
            p1         = p1->next;
        }
        else {
            prev->next = p2;
            p2         = p2->next;
        }
        prev = prev->next;
    }
    prev->next = p1 ? p1 : p2;

    return head;
}

int list_has_cycle(List *list)
{
    List *fast = list;
    List *slow = list;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return 0;
    }

    return -1;
}