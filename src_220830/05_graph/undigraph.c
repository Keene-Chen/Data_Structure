/**
 * @file    : undigraph.c
 * @author  : KeeneChen
 * @date    : 2022.09.03-16:24:18
 * @details : undigraph
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100;

// 顶点数组的结构体
typedef struct vertex_s {
    // 顶点的名字
    char name[9];
    // 指向临接点结构体指针
    struct edgeNode *first;
} vertex_t;

int main(void)
{

    return 0;
}