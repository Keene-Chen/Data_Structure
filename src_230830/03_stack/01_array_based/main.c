/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:47:18
 * @details : main
 */

#include "sqstack.h"
#include <stdio.h>

int main(void)
{
    datatype arr[] = { 1, 2, 3, 4 };
    int ret        = 0;

    sqstack *stack = stack_create();
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        stack_push(stack, &arr[i]);
    }
    stack_travel(stack);

    datatype temp = 5;
    if (stack_push(stack, &temp) != 0) {
        printf("push failed\n");
    }
    else {
        stack_travel(stack);
    }

    while (stack_pop(stack, &ret) == 0) {
        printf("pop: %d\n", ret);
    }

    stack_top(stack, &ret);
    printf("top: %d\n", ret);

    stack_destroy(stack);

    return 0;
}