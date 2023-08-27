/**
 * @file    : seq_stack.h
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:10:47
 * @details : seq_stack
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION  "0.1.0"
#define MAX_SIZE 1024
#define isNULL(x)    \
    if ((x) == NULL) \
        return;

typedef struct seq_stack_s {
    void *data[MAX_SIZE];
    int size;
} seq_stack_t;

typedef void *seq_stack;

/**
 * @brief  初始化顺序栈
 * @return seq_stack 顺序栈
 */
seq_stack seq_stack_init(void);

/**
 * @brief  销毁顺序栈
 * @param  stack 顺序栈
 * @return void
 */
void seq_stack_destory(seq_stack stack);

/**
 * @brief  入顺序栈
 * @param  stack 顺序栈
 * @param  value 入栈数据
 * @return void
 */
void seq_stack_push(seq_stack stack, void *value);

/**
 * @brief  出顺序栈
 * @param  stack 顺序栈
 * @return void
 */
void seq_stack_pop(seq_stack stack);

/**
 * @brief  返回栈顶
 * @param  stack 顺序栈
 * @return void
 */
void *seq_stack_top(seq_stack stack);

/**
 * @brief  返回栈大小
 * @param  stack 顺序栈
 * @return int 顺序栈大小
 */
int seq_stack_size(seq_stack stack);

/**
 * @brief  是否空栈
 * @param  stack 顺序栈
 * @return int 0/-1
 */
int seq_stack_isEmpty(seq_stack stack);

const char *seq_stack_get_version(void);

#endif // __SEQ_STACK_H__