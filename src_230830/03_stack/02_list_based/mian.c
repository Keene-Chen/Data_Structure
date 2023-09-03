/**
 * @file    : mian.c
 * @author  : KeeneChen
 * @date    : 2023.09.03-11:46:05
 * @details : mian
 */

#include "list_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct student {
        char name[32];
        int age;
    };
    struct student stu[] = { { "KeeneChen1", 18 }, { "KeeneChen2", 18 }, { "KeeneChen3", 18 } },
                   temp  = { 0 };

    STACK *stack = list_stack_create(sizeof(struct student));
    list_stack_push(stack, &stu[0]);
    list_stack_push(stack, &stu[1]);
    list_stack_push(stack, &stu[2]);

    while (list_stack_pop(stack, &temp) == 0) {
        printf("pop: name: %s age: %d\n", temp.name, temp.age);
    }

    list_stack_destroy(stack);

    return 0;
}