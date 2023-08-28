/**
 * @file    : link_stack.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:47:36
 * @details : link_stack
 */

#include "link_stack.h"

link_stack link_stack_init(void)
{
    link_stack_t *stack = malloc(sizeof(link_stack_t));
    if (stack == NULL)
        return NULL;
    stack->header.next = NULL;
    stack->size        = 0;

    return stack;
}

void link_stack_destory(link_stack stack)
{
    isNULL(stack);
    free(stack);
    stack = NULL;
}

void link_stack_push(link_stack stack, void *value)
{
    isNULL(stack);
    isNULL(value);

    link_stack_t *lstack = stack;
    stack_node_t *temp   = value; // 使用用户数据的前4个字节存储指针域

    // 修改指针指向,使用链表头插法
    temp->next          = lstack->header.next;
    lstack->header.next = temp;

    // 更新链表长度
    lstack->size++;
}

void link_stack_pop(link_stack stack)
{
    isNULL(stack);
    link_stack_t *lstack = stack;
    if (lstack->size == 0)
        return;

    // 修改指针指向,使用链表从头删除
    struct stack_node_s *first = lstack->header.next;
    lstack->header.next        = first->next;

    lstack->size--;
}

void *link_stack_top(link_stack stack)
{
    if (stack == NULL)
        return NULL;
    link_stack_t *lstack = stack;
    if (lstack->size == 0)
        return NULL;
    return lstack->header.next;
}

int link_stack_size(link_stack stack)
{
    if (stack == NULL)
        return -1;
    link_stack_t *lstack = stack;
    return lstack->size;
}

int link_stack_isEmpty(link_stack stack)
{
    if (stack == NULL)
        return -1;
    link_stack_t *lstack = stack;
    if (lstack->size == 0)
        return 1;

    return 0;
}

const char *link_stack_get_version(void)
{
    return VERSION;
}