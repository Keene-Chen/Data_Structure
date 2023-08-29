/**
 * @file    : dynamic_array.h
 * @author  : KeeneChen
 * @date    : 2023.08.24-18:13:42
 * @details : 动态数组
 */

#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamic_array {
    void **p_addr; // 维护堆区数组的指针
    int capacity;  // 数组容量
    int size;      // 数组大小
};

/**
 * @brief  dynarr_init 初始化动态数组
 * @param  int capacity 容量大小
 * @return struct dynamic_array* 动态数组指针
 */
struct dynamic_array *dynarr_init(int capacity);

/**
 * @brief  dynarr_destroy 销毁动态数组
 * @param  struct dynamic_array* 动态数组指针
 * @return void
 */
void dynarr_destroy(struct dynamic_array *array);

/**
 * @brief  dynarr_insert 插入数据,自动扩容
 * @param  struct dynamic_array* 动态数组指针
 * @param  int index 在index处插入数据
 * @param  void*  value 待插入数据
 * @return int 插入是否成功
 * @retval 0  插入成功
 * @retval -1 插入失败
 */
int dynarr_insert(struct dynamic_array *array, int index, void *value);

/**
 * @brief  dynarr_foreach 遍历动态数组
 * @param  struct dynamic_array* 动态数组指针
 * @param  print_cb 遍历输出的回调函数
 * @return void
 */
void dynarr_foreach(struct dynamic_array *array, void (*print_cb)(void *arg));

/**
 * @brief  dynarr_del_by_index 根据索引删除元素
 * @param  struct dynamic_array* 动态数组指针
 * @param  int index 要删除位置的索引
 * @return int 是否成功
 * @retval 0  删除成功
 * @retval -1 删除失败
 */
int dynarr_del_by_index(struct dynamic_array *array, int index);

/**
 * @brief  dynarr_del_by_value 根据值删除元素
 * @param  struct dynamic_array* 动态数组指针
 * @param  void *value 要删除值
 * @return int 是否成功
 * @retval 0  删除成功
 * @retval -1 删除失败
 */
int dynarr_del_by_value(struct dynamic_array *array, void *value,
                        int (*compare_cb)(void *, void *));

/**
 * @brief  dynarr_first 返回动态数组中第一个元素
 * @param  struct dynamic_array* 动态数组指针
 * @return void* 元素值
 */
void *dynarr_first(struct dynamic_array *array);

/**
 * @brief  dynarr_last 返回动态数组中最后一个元素
 * @param  struct dynamic_array* 动态数组指针
 * @return void* 元素值
 */
void *dynarr_last(struct dynamic_array *array);

#endif // __DYNAMIC_ARRAY_H__