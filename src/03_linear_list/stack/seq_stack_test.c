/**
 * @file    : seq_stack_test.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:45:21
 * @details : seq_stack_test
 */

#include "seq_stack.h"

typedef struct tagStudent {
    char name[20];
    int age;
} Student;

int main(void)
{
    seq_stack stack = seq_stack_init();

    Student stu1 = { "张三", 1 };
    Student stu2 = { "李四", 2 };
    Student stu3 = { "王五", 3 };
    Student stu4 = { "赵六", 4 };
    seq_stack_push(stack, &stu1);
    seq_stack_push(stack, &stu2);
    seq_stack_push(stack, &stu3);
    seq_stack_push(stack, &stu4);

    printf("栈大小:%d\n", seq_stack_size(stack));
    while (seq_stack_isEmpty(stack) == 0) {
        Student *p = seq_stack_top(stack);
        printf("name:%s age:%d\n", p->name, p->age);
        seq_stack_pop(stack);
    }
    printf("栈大小:%d\n", seq_stack_size(stack));

    seq_stack_destory(stack);

    return 0;
}