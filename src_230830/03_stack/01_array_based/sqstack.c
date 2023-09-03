/**
 * @file    : sqstack.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:47:06
 * @details : sqstack
 */

#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sqstack *stack_create(void)
{
    sqstack *stack = (sqstack *)malloc(sizeof(sqstack));
    if (stack == NULL)
        return NULL;
    stack->top = -1; // 栈没有任何元素

    return stack;
}

void stack_destroy(sqstack *sqstack)
{
    free(sqstack);
    sqstack = NULL;
}

int stack_isempty(sqstack *sqstack)
{
    return (sqstack->top == -1);
}

int stack_push(sqstack *sqstack, datatype *data)
{
    // 栈判满
    if (sqstack->top == (MAXSIZE - 1))
        return -1;
    sqstack->data[++(sqstack->top)] = *data;

    return 0;
}

int stack_pop(sqstack *sqstack, datatype *data)
{
    // 栈判空
    if (stack_isempty(sqstack))
        return -1;
    *data = sqstack->data[(sqstack->top)--];

    return 0;
}

int stack_top(sqstack *sqstack, datatype *data)
{
    // 栈判空
    if (stack_isempty(sqstack))
        return -1;
    *data = sqstack->data[sqstack->top];

    return 0;
}

int stack_travel(sqstack *sqstack)
{
    // 栈为空就不遍历
    if (stack_isempty(sqstack))
        return -1;
    for (int i = 0; i <= sqstack->top; i++) {
        printf("%d ", sqstack->data[i]);
    }
    printf("\n");

    return 0;
}