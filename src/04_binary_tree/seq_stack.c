/**
 * @file    : seq_stack.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:45:27
 * @details : seq_stack
 */

#include "seq_stack.h"

seq_stack seq_stack_init(void)
{
    seq_stack_t *stack = malloc(sizeof(seq_stack_t));
    if (stack == NULL)
        return NULL;

    memset(stack->data, 0x00, sizeof(stack->data));
    stack->size = 0;

    return stack;
}

void seq_stack_destory(seq_stack stack)
{
    isNULL(stack);

    free(stack);
    stack = NULL;
}

void seq_stack_push(seq_stack stack, void *value)
{
    isNULL(stack);
    isNULL(value);

    seq_stack_t *sstack = stack;
    if (sstack->size == MAX_SIZE)
        return;

    sstack->data[sstack->size] = value;
    sstack->size++;
}

void seq_stack_pop(seq_stack stack)
{
    isNULL(stack);

    seq_stack_t *sstack = stack;
    if (sstack->size == 0)
        return;

    sstack->data[sstack->size - 1] = NULL;
    sstack->size--;
}

void *seq_stack_top(seq_stack stack)
{
    if (stack == NULL)
        return NULL;
    seq_stack_t *sstack = stack;
    if (sstack->size == 0)
        return NULL;

    return sstack->data[sstack->size - 1];
}

int seq_stack_size(seq_stack stack)
{
    if (stack == NULL)
        return -1;
    seq_stack_t *sstack = stack;
    return sstack->size;
}

int seq_stack_isEmpty(seq_stack stack)
{
    if (stack == NULL)
        return -1;
    seq_stack_t *sstack = stack;
    if (sstack->size == 0)
        return 1;
    return 0;
}

const char *seq_stack_get_version(void)
{
    return VERSION;
}