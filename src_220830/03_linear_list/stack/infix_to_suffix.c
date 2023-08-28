/**
 * @file    : infix_to_suffix.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-12:01:52
 * @details : infix_to_suffix
 */

// !BUG
#include "seq_stack.h"
#include <ctype.h>

int IsHigherThan(char x, char y) // 优先级定义，'('具有最高优先级，其余同四则运算
{
    if ((x == '(') && ((y == '+') || (y == '-') || (y == '*') || (y == '/')))
        return 1;
    else if (((x == '*') || (x == '/')) && ((y == '+') || (y == '-')))
        return 1;
    else
        return 0;
}

void infix_to_suffix(char *ch, seq_stack stack)
{
    char *top_elem = NULL; // 存储栈顶元素

    while (*ch != '\0') {
        if (*ch >= '0' && *ch <= '9')
            printf("%c ", *ch);
        if (*ch == '(') {
            seq_stack_push(stack, ch);
        }
        if (*ch == ')') {
            top_elem = seq_stack_top(stack);
            while (1) {
                if (*top_elem == '(' || (seq_stack_isEmpty(stack) == 0)) {
                    printf("%c ", *top_elem);
                    seq_stack_pop(stack);
                    break;
                }
            }
            seq_stack_pop(stack);
        }
        if (*ch == '+' || *ch == '-') {
            seq_stack_push(stack, ch);
        }
        if (*ch == '*' || *ch == '/') {
            top_elem = seq_stack_top(stack);
            if (IsHigherThan(*top_elem, *ch)) {
                printf("%c ", *top_elem);
                seq_stack_pop(stack);
            }
            else {
                seq_stack_push(stack, ch);
            }
        }

        ch++;
    }
}

int main(void)
{
    // char* str = "8+(3-1)*5";
    char *str = "1+2*(4-5)";

    seq_stack stack = seq_stack_init();
    infix_to_suffix(str, stack);

    while (seq_stack_isEmpty(stack) == 0) {
        char *p = seq_stack_top(stack);
        printf("%c ", *p);
        seq_stack_pop(stack);
    }
    printf("\n");

    seq_stack_destory(stack);

    return 0;
}