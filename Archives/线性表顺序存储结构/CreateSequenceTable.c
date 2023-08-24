/**
 * Author:   hellochen
 * DateTime: 2021.04.01-11:29:53
 * Description: 顺序表的创建
 */

#include <stdio.h>
#include <stdlib.h>

/* variable */
#define Size 10
typedef struct {
    int *head;  // 动态数组，顺序表中的元素
    int length; // 顺序表长度
    int size;   // 顺序表大小
} Table;

/* function */
Table initTable();
void showTable(Table t);

int main(void)
{
    Table t = initTable();
    for (int i = 1; i <= Size; i++) {
        t.head[i - 1] = i;
        ++t.length;
    }
    showTable(t);

    return 0;
}

/* 初始化顺序表为空表 */
Table initTable()
{
    Table t;
    t.head = (int *)malloc(Size * sizeof(int));
    if (t.head == NULL) // !t.head
    {
        printf("Failed to create!");
        exit(0);
    }
    t.length = 0;
    t.size   = Size;
    return t;
}

void showTable(Table t)
{
    for (int i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}