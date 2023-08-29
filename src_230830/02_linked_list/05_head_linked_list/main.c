/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.08.27-11:38:09
 * @details : main
 */

#include "head_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// 获取随机整数
static inline int get_rand_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// 比较函数
static inline int compare_int(datatype *a, datatype *b)
{
    return *(int *)a < *(int *)b;
}

int main(void)
{
    list *l = list_create();

    int arr[] = { [3] = 4, 2, 1, 5, 3 };
    arr[0]    = get_rand_int(1, 10);
    arr[1]    = get_rand_int(3, 10);
    arr[2]    = get_rand_int(1, 10);

    list_insert_at(l, 0, &arr[0]);
    list_insert_at(l, 2, &arr[2]);
    list_insert_at(l, 1, &arr[1]);

    for (int i = 3; i < sizeof(arr) / sizeof(arr[0]); i++) {
        list_order_insert(l, &arr[i], compare_int);
    }

    list_display(l);

    int num = 0;
    list_delete_at(l, 2, &num);
    printf("%d\n", num);
    list_display(l);

    list_delete(l, &arr[0], compare_int);
    list_display(l);

    list_destroy(l);

    return 0;
}