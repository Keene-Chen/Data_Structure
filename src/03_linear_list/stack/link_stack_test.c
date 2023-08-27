/**
 * @file    : link_stack_test.c
 * @author  : KeeneChen
 * @date    : 2022.08.31-20:48:00
 * @details : link_stack_test
 */

#include "link_stack.h"

typedef struct {
    void *node;
    char name[20];
    int age;
} Student;

int main(void)
{
    link_stack stack = link_stack_init();

    Student stu1 = { NULL, "张三", 1 };
    Student stu2 = { NULL, "李四", 2 };
    Student stu3 = { NULL, "王五", 3 };
    Student stu4 = { NULL, "赵六", 4 };
    link_stack_push(stack, &stu1);
    link_stack_push(stack, &stu2);
    link_stack_push(stack, &stu3);
    link_stack_push(stack, &stu4);

    printf("栈大小:%d\n", link_stack_size(stack));

    while (link_stack_isEmpty(stack) == 0) {
        Student *p = link_stack_top(stack);
        printf("name:%s age:%d\n", p->name, p->age);

        link_stack_pop(stack);
    }

    printf("栈大小:%d\n", link_stack_size(stack));

    link_stack_destory(stack);

    return 0;
}