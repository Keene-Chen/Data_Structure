/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.28-20:47:28
 * @details : main
 */

#include "nohead_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student {
    char name[32];
    int age;
};

static void print_struct(datatype *stu)
{
    struct student *s = stu;
    printf("name: %s, age: %d\n", s->name, s->age);
}

int main(void)
{
    srand(time(NULL));
    list *l = NULL;
    struct student stu[5];

    for (int i = 0; i < 5; i++) {
        sprintf(stu[i].name, "stu_%02d", i);
        stu[i].age = rand() % 100;

        list_insert(&l, &stu[i]);
    }

    list_display(l, print_struct);
    list_delete(&l);
    list_display(l, print_struct);
    list_destroy(&l);

    return 0;
}