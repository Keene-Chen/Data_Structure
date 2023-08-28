/**
 * @file    : vector.c
 * @author  : KeeneChen
 * @date    : 2022.08.30-15:00:51
 * @details : vector
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

/**
 * @brief  初始化顺序表
 * @param  n 顺序表大小
 * @return 顺序表
 */
Vector *init(int n)
{
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data   = (int *)malloc(sizeof(int) * n);
    vec->size   = n;
    vec->length = 0;

    return vec;
}

/**
 * @brief  销毁顺序表
 * @param  vec 待销毁顺序表
 */
void destroy(Vector *vec)
{
    if (vec == NULL)
        return;
    free(vec->data);
    free(vec);

    return;
}

/**
 * @brief  顺序表插入数据
 * 如果顺序表为空或者满，以及传入索引值越界时，不能操作顺序表
 * @param  vec 顺序表
 * @param  index 索引，从那个为在插入
 * @param  value 插入的值
 * @return 0为失败，1为成功
 */
int insert(Vector *vec, int index, int value)
{
    // 判断顺序表是否为空
    if (vec == NULL)
        return 0;
    // 判断顺序表是否为满
    if (vec->length == vec->size)
        return 0;
    // 判断索引是否越界
    if (index < 0 || index > vec->length)
        return 0;

    // 顺序表从索引位置循环向后移动一位
    for (int i = vec->length; i > index; i--) {
        vec->data[i] = vec->data[i - 1];
    }

    // 插入值
    vec->data[index] = value;
    vec->length += 1;
    return 1;
}

/**
 * @brief  顺序表删除
 * 如果顺序表为空或者长度为0，以及传入索引值越界时，不能操作顺序表
 * @param  vec 待操作顺序表
 * @param  index 待删除的索引
 * @return 0为失败，1为成功
 */
int delete(Vector *vec, int index)
{
    // 判断顺序表是否为空
    if (vec == NULL)
        return 0;
    // 判断顺序表长度
    if (vec->length == 0)
        return 0;
    // 判断索引是否越界，最后一位也没有值
    if (index < 0 || index >= vec->length)
        return 0;

    // 顺序表从索引位置循环向前移动一位
    for (int i = vec->length; i > index; i--) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

/**
 * @brief  打印顺序表
 * @param  vec 待打印顺序表
 */
void show(Vector *vec)
{
    printf("Vector(%d)=[", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0)
            printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return;
}

int main(void)
{
    srand(time(0));
    Vector *vec = init(MAX_OP);

    int op, index, value;
    for (int i = 0; i < MAX_OP; i++) {
        op    = rand() % 2;
        index = rand() % (vec->length + 1);
        value = rand() % 100;
        switch (op) {
        case 0:
            printf("insert %d at %d to vector\n", value, index);
            insert(vec, index, value);
            break;

        case 1:
            printf("delete item at %d from vector\n", index);
            delete (vec, index);
            break;
        }
        show(vec);
        printf("\n");
    }

    return 0;
}