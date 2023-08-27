/**
 * @file    : link_stack.h
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:46:29
 * @details : link_stack
 */

#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1.0"
#define isNULL(x)    \
    if ((x) == NULL) \
        return;

typedef struct stack_node_s {
    struct stack_node_s *next;
} stack_node_t;

typedef struct link_stack_s {
    stack_node_t header;
    int size;
} link_stack_t;

typedef void *link_stack;

link_stack link_stack_init(void);
void link_stack_destory(link_stack stack);
void link_stack_push(link_stack stack, void *value);
void link_stack_pop(link_stack stack);
void *link_stack_top(link_stack stack);
int link_stack_size(link_stack stack);
int link_stack_isEmpty(link_stack stack);

const char *link_stack_get_version(void);

#endif // __LINK_STACK_H__