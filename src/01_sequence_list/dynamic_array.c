/**
 * @file    : dynamic_array.c
 * @author  : KeeneChen
 * @date    : 2022.08.30-15:00:51
 * @details : dynamic_array
 */

#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

dyn_arr_t *dyn_arr_init(int capacity)
{
    if (capacity <= 0)
        return NULL;

    dyn_arr_t *array = malloc(sizeof(dyn_arr_t));
    if (array == NULL)
        return NULL;

    array->p_addr   = malloc(sizeof(void *) * capacity);
    array->capacity = capacity;
    array->size     = 0;

    return array;
}

void dyn_arr_destroy(dyn_arr_t *array)
{
    if (array == NULL)
        return;

    free(array->p_addr);
    array->p_addr = NULL;
    free(array);
    array = NULL;

    return;
}

int dyn_arr_insert(dyn_arr_t *array, int index, void *value)
{
    // 判空
    if (array == NULL)
        return -1;
    if (value == NULL)
        return -1;

    // 索引是否越界,越界就尾插
    if (index < 0 || index > array->size)
        index = array->size;

    // 判满,为满就动态扩展数组
    if (array->capacity == array->size) {
        // 创建新容量
        int new_capacity = array->capacity * 2;
        // 用temp中转原来的数据
        void **temp = malloc(sizeof(void *) * new_capacity);
        memcpy(temp, array->p_addr, sizeof(void *) * array->capacity);
        // 释放原始数据
        free(array->p_addr);
        // 修改指针指向
        array->p_addr = temp;
        // 修改容量为扩展后的容量
        array->capacity = new_capacity;
    }

    for (int i = array->size - 1; i >= index; i--)
        array->p_addr[i + 1] = array->p_addr[i];
    array->p_addr[index] = value;
    array->size++;

    return 0;
}

void dyn_arr_foreach(dyn_arr_t *array, void (*print_cb)(void *))
{
    if (array == NULL)
        return;
    if (print_cb == NULL)
        return;

    for (int i = 0; i < array->size; i++) {
        print_cb(array->p_addr[i]);
    }
}

void dyn_arr_delete_by_index(dyn_arr_t *array, int index)
{
    if (array == NULL)
        return;
    if (index < 0 || index > array->size - 1)
        return;

    for (int i = index; i < array->size - 1; i++)
        array->p_addr[i] = array->p_addr[i + 1];

    array->size--;
}

void dyn_arr_delete_by_value(dyn_arr_t *array, void *value, int (*compare_cb)(void *, void *))
{
    if (array == NULL)
        return;
    if (value == NULL)
        return;

    for (int i = 0; i < array->size; i++) {
        if (compare_cb(array->p_addr[i], value)) {
            dyn_arr_delete_by_index(array, i);
            break;
        }
    }
}

void *dyn_arr_first(dyn_arr_t *array)
{
    return array->p_addr[0];
}

void *dyn_arr_last(dyn_arr_t *array)
{
    return array->p_addr[array->size - 1];
}