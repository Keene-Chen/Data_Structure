/**
 * @file    : dynamic_array.c
 * @author  : KeeneChen
 * @date    : 2023.08.24-18:13:42
 * @details : 动态数组
 */

#include "dynamic_array.h"

/**
 * @brief  dynarr_init 初始化动态数组
 * @param  int capacity 容量大小
 * @return struct dynamic_array* 动态数组指针
 */
struct dynamic_array *dynarr_init(int capacity)
{
    // 判段容量是否合法
    if (capacity < 0)
        return NULL;

    // 申请堆区空间
    struct dynamic_array *array = malloc(sizeof(struct dynamic_array));
    // 判断是否申请成功
    if (array == NULL)
        return NULL;

    // 初始化数组
    array->p_addr   = malloc(sizeof(void *) * capacity);
    array->capacity = capacity;
    array->size     = 0;

    return array;
}

/**
 * @brief  dynarr_destroy 销毁动态数组
 * @param  struct dynamic_array* 动态数组指针
 * @return void
 */
void dynarr_destroy(struct dynamic_array *array)
{
    if (array == NULL)
        exit(EXIT_FAILURE);

    free(array->p_addr);
    array->p_addr = NULL; // 防止野指针
    free(array);
    array = NULL;
}

/**
 * @brief  dynarr_insert 插入数据,自动扩容
 * @param  struct dynamic_array* 动态数组指针
 * @param  int index 在index处插入数据
 * @param  void*  value 待插入数据
 * @return int 插入是否成功
 * @retval 0  插入成功
 * @retval -1 插入失败
 */
int dynarr_insert(struct dynamic_array *array, int index, void *value)
{
    // 校验参数是否符合要求
    if (array == NULL)
        return -1;
    if (value == NULL)
        return -1;
    // 索引是否越界,越界就尾插
    if (index < 0 || index > array->size)
        index = array->size;

    // 判断动态数组是否占满,如果占满需扩容
    if (array->capacity == array->size) {
        // 1.创建新的容量大小是原来的两倍
        int new_capacity = array->capacity * 2;
        // 2.创建新空间中转原来数组中的数据
        void **temp = malloc(sizeof(void *) * new_capacity);
        memcpy(temp, array->p_addr, sizeof(void *) * array->capacity);
        // 3.释放原始数据
        free(array->p_addr);
        // 4.修改指针指向
        array->p_addr = temp;
        // 5.修改容量为扩展后的容量
        array->capacity = new_capacity;
    }

    // 插入数据
    for (int i = array->size - 1; i >= index; i--) {
        // 从尾部移动数组中的元素,留出待插入数据的空间
        array->p_addr[i + 1] = array->p_addr[i];
    }
    array->p_addr[index] = value;
    array->size++;

    return 0;
}

/**
 * @brief  dynarr_foreach 遍历动态数组
 * @param  struct dynamic_array* 动态数组指针
 * @param  print_cb 遍历输出的回调函数
 * @return void
 */
void dynarr_foreach(struct dynamic_array *array, void (*print_cb)(void *arg))
{
    if (array == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < array->size; i++) {
        // printf("%c\n", *(char *)array->p_addr[i]);
        // 由于数据是void*不清楚具体类型,所以遍历数据的操作应该交给调用者,库只能确保遍历数组不负责具体如何输出显示
        print_cb(array->p_addr[i]);
    }
}

/**
 * @brief  dynarr_del_by_index 根据索引删除元素
 * @param  struct dynamic_array* 动态数组指针
 * @param  int index 要删除位置的索引
 * @return int 是否成功
 * @retval 0  删除成功
 * @retval -1 删除失败
 */
int dynarr_del_by_index(struct dynamic_array *array, int index)
{
    // 参数合法性校验
    if (array == NULL)
        return -1;
    if (index < 0 || index > array->size - 1)
        return -1;

    // ? 数据前移一位,逻辑上的删除,只是访问不到而已
    for (int i = index; i < array->size - 1; i++)
        array->p_addr[i] = array->p_addr[i + 1];

    array->size--;

    return 0;
}

/**
 * @brief  dynarr_del_by_value 根据值删除元素
 * @param  struct dynamic_array* 动态数组指针
 * @param  void *value 要删除值
 * @return int 是否成功
 * @retval 0  删除成功
 * @retval -1 删除失败
 */
int dynarr_del_by_value(struct dynamic_array *array, void *value, int (*compare_cb)(void *, void *))
{
    // 参数合法性校验
    if (array == NULL)
        return -1;
    if (value == NULL)
        return -1;

    for (int i = 0; i < array->size; i++) {
        if (compare_cb(array->p_addr[i], value)) {
            dynarr_del_by_index(array, i);
            break;
        }
    }

    return 0;
}

/**
 * @brief  dynarr_first 返回动态数组中第一个元素
 * @param  struct dynamic_array* 动态数组指针
 * @return void* 元素值
 */
void *dynarr_first(struct dynamic_array *array)
{
    return array->p_addr[0];
}

/**
 * @brief  dynarr_last 返回动态数组中最后一个元素
 * @param  struct dynamic_array* 动态数组指针
 * @return void* 元素值
 */
void *dynarr_last(struct dynamic_array *array)
{
    return array->p_addr[array->size - 1];
}