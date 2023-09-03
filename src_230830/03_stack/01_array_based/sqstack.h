/**
 * @file    : sqstack.h
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:46:54
 * @details : sqstack
 */

#ifndef __SQSTACK_H__
#define __SQSTACK_H__

#define MAXSIZE 5
typedef int datatype;

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

typedef struct node_st {
    datatype data[MAXSIZE];
    int top;
} sqstack;

sqstack *stack_create(void);

void stack_destroy(sqstack *sqstack);

int stack_isempty(sqstack *sqstack);

int stack_push(sqstack *sqstack, datatype *data);

int stack_pop(sqstack *sqstack, datatype *data);

int stack_top(sqstack *sqstack, datatype *data);

int stack_travel(sqstack *sqstack);

#endif // __SQSTACK_H__