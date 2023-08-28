/**
 * @file    : dynamic_array_test.c
 * @author  : KeeneChen
 * @date    : 2022.08.30-21:20:12
 * @details : dynamic_array_test
 */

#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagStudent {
    char name[20];
    int age;
} Student;

void print_cb(void *value)
{
    Student *p = value;
    printf("name:%s age:%d\n", p->name, p->age);
}

void printint_cb(void *value)
{
    int *p = value;
    printf("%d\n", *p);
}

int compare_cb(void *value1, void *value2)
{
    Student *p1 = value1;
    Student *p2 = value2;
    return (strcmp(p1->name, p2->name) == 0) && (p1->age == p2->age);
}

void test_struct(void)
{
    dyn_arr_t *array = dyn_arr_init(2);
    printf("%d %d\n", array->capacity, array->size);

    Student stu1 = { "张三", 1 };
    Student stu2 = { "李四", 2 };
    Student stu3 = { "王五", 3 };

    dyn_arr_insert(array, 0, &stu1);
    dyn_arr_insert(array, 1, &stu2);
    dyn_arr_insert(array, -1, &stu3);
    dyn_arr_foreach(array, print_cb);
    printf("%d %d\n", array->capacity, array->size);

    dyn_arr_delete_by_index(array, 1);
    dyn_arr_delete_by_index(array, -1);
    dyn_arr_foreach(array, print_cb);
    printf("%d %d\n", array->capacity, array->size);

    dyn_arr_delete_by_value(array, &stu2, compare_cb);
    dyn_arr_foreach(array, print_cb);
    printf("%d %d\n", array->capacity, array->size);

    dyn_arr_destroy(array);
}

void test_int(void)
{
    dyn_arr_t *array = dyn_arr_init(2);
    printf("%d %d\n", array->capacity, array->size);

    int a = 10, b = 20, c = 30;

    dyn_arr_insert(array, 0, &a);
    dyn_arr_insert(array, 1, &b);
    dyn_arr_insert(array, -1, &c);
    dyn_arr_foreach(array, printint_cb);
    printf("%d %d\n", array->capacity, array->size);

    dyn_arr_delete_by_index(array, 1);
    dyn_arr_delete_by_index(array, -1);
    dyn_arr_foreach(array, printint_cb);
    printf("%d %d\n", array->capacity, array->size);
    int *temp = dyn_arr_first(array);
    printf("%d\n", *temp);
    temp = dyn_arr_last(array);
    printf("%d\n", *temp);

    dyn_arr_destroy(array);
}

int main(void)
{
    test_struct();
    return 0;
}