/**
 * @file    : list_stack.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:46:13
 * @details : list_stack
 */

#include "list_stack.h"
#include <stdlib.h>

STACK *list_stack_create(int initsize)
{
    return llist_create(initsize);
}

void list_stack_destroy(STACK *stack)
{
    llist_destroy(stack);
}

int list_stack_push(STACK *stack, void *data)
{
    int ret = llist_insert(stack, data, HEAD_INSERT);
    if (ret)
        return ret;

    return 0;
}

static int always_macth(const void *data1, const void *data2)
{
    return 0;
}

int list_stack_pop(STACK *stack, void *data)
{
    int ret = llist_fetch(stack, NULL, always_macth, data);
    if (ret)
        return ret;

    return 0;
}
