/**
 * @file    : list_stack.h
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:46:28
 * @details : list_stack
 */

#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#include "list.h"

typedef LLIST STACK;

STACK *list_stack_create(int initsize);
void list_stack_destroy(STACK *stack);
int list_stack_push(STACK *stack, void *data);
int list_stack_pop(STACK *stack, void *data);

#endif // __LIST_STACK_H__