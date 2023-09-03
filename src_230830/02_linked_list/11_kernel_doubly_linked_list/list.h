/**
 * @file    : list.h
 * @author  : KeeneChen
 * @date    : 2023.08.31-20:20:39
 * @details : linux kernel doubly linked list
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

/* kernel 链表结点结构体 */
struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) \
    {                        \
        &(name), &(name)     \
    }

#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

/* 初始化头结点 */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->prev = list;
    list->next = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    next->prev = new;
    new->next  = next;
    new->prev  = prev;
    prev->next = new;
}

/* 向链表中添加结点 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

/* 向链表中添加结点 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

/* 删除链表中的结点 */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

static inline void __list_del_clearprev(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    entry->prev = NULL;
}

static inline void __list_del_entry(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
}

#define POISON_POINTER_DELTA 0
#define LIST_POISON1         ((void *)0x100 + POISON_POINTER_DELTA)
#define LIST_POISON2         ((void *)0x122 + POISON_POINTER_DELTA)

static inline void list_del(struct list_head *entry)
{
    __list_del_entry(entry);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}

/* 遍历链表 */
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member)              \
    ({                                               \
        void *__mptr = (void *)(ptr);                \
        ((type *)(__mptr - offsetof(type, member))); \
    })
#define list_entry(ptr, type, member) container_of(ptr, type, member)
#define list_for_each(pos, head)      for (pos = (head)->next; pos != (head); pos = pos->next)

#endif // __LIST_H__