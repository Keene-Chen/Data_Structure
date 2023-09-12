/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.12-18:46:36
 * @details : main
 */

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct student stu;
    struct node_st *btree = NULL;

    int arr[] = { 5, 3, 7, 2, 4, 1, 6, 9, 8 };
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        stu.id = arr[i];
        snprintf(stu.name, sizeof(stu.name), "stu_%02d", arr[i]);
        stu.age = rand() % 100;
        btree_insert(&btree, &stu);
    }

    level_travel_list_queue(btree);

    return 0;
}