/**
 * @file    : dynamic_array.h
 * @author  : KeeneChen
 * @date    : 2022.08.30-15:00:51
 * @details : dynamic_array
 */

#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#define VERSION "0.1.0"

typedef struct dyn_arr_s {
    void **p_addr; // 维护堆区数组的指针
    int capacity;  // 数组容量
    int size;      // 数组大小
} dyn_arr_t;

/**
 * @brief  初始化动态数组
 * @param  capacity 初始化数组容量
 * @return dyn_arr_t* 指向结构的指针
 */
dyn_arr_t *dyn_arr_init(int capacity);

/**
 * @brief  销毁动态数组
 * @param  array 指向动态数组的指针
 * @return void
 */
void dyn_arr_destroy(dyn_arr_t *array);

/**
 * @brief  增加元素
 * @param  array 指向动态数组的指针
 * @param  index 插入索引
 * @param  value 指向插入值的指针
 * @return int 成功为0,失败为-1
 */
int dyn_arr_insert(dyn_arr_t *array, int index, void *value);

/**
 * @brief  遍历数组
 * @param  array 指向动态数组的指针
 * @param  print_cb 用于打印的回调函数
 * @return void
 */
void dyn_arr_foreach(dyn_arr_t *array, void (*print_cb)(void *));

/**
 * @brief  根据索引删除元素
 * @param  array 指向动态数组的指针
 * @param  index 插入索引
 * @return void
 */
void dyn_arr_delete_by_index(dyn_arr_t *array, int index);

/**
 * @brief  根据值删除元素
 * @note   由于无法确定类型需要用户自行提供回调函数进行比较
 * @param  array 指向动态数组的指针
 * @param  value 指向值的指针
 * @param  compare_cb 用于比较值的回调函数
 * @return void
 */
void dyn_arr_delete_by_value(dyn_arr_t *array, void *value, int (*compare_cb)(void *, void *));

/**
 * @brief  返回动态数组中的第一个/最后一个元素
 * @param  array 指向动态数组的指针
 * @return void
 */
void *dyn_arr_first(dyn_arr_t *array);
void *dyn_arr_last(dyn_arr_t *array);

#endif // __DYNAMIC_ARRAY_H__