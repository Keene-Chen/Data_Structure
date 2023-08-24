/**
 * Author:   hellochen
 * DateTime: 2021.04.01-11:29:53
 * Description: 顺序表的CURD操作
 */

#include "SequenceTable.h" // 顺序表结构和操作函数声明
#include <stdio.h>
#include <stdlib.h> // malloc函数原型

int main(void)
{
    /* 初始化顺序表并赋值 */
    Table t = initTable();
    for (int i = 1; i <= Size; i++) {
        t.head[i - 1] = i;
        ++t.length;
    }
    printf("原始顺序表的长度和大小:%d,%d\n", t.length, t.size);
    showTable(t);

    /* 插入操作 */
    printf(DELIMITER);
    printf("在第3个位置插入元素：26\n");
    Table a = insertTable(t, 26, 3);
    printf("插入后，顺序表的长度和大小:%d,%d\n", a.length, a.size);
    showTable(a);

    /* 删除操作 */
    printf(DELIMITER);
    printf("删除第2个位置的元素\n");
    printf("删除后，顺序表的长度和大小:%d,%d\n", a.length, a.size);
    deleteTable(a, 2);
    showTable(a);

    /* 查询操作 */
    printf(DELIMITER);
    printf("请输入要查找的值");
    int elem = 0;
    scanf("%d", &elem);
    printf("查到%d在顺序表的第%d个位置", elem, selectTable(a, elem));

    /* 修改操作 */
    printf(DELIMITER);
    printf("输入要更改的值,以及更改为\n");
    int elem1 = 0, elem2 = 0;
    scanf("%d %d", &elem1, &elem2);
    updateTable(a, elem1, elem2);
    showTable(a);

    free(t.head);
    return 0;
}

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
    for (int i = 0; i < t.length; i++) // 遍历顺序表中的元素
    {
        printf("%-4d", t.head[i]);
    }
    printf("\n");
}

Table insertTable(Table t, int elem, int addIndex)
{
    if (addIndex < 1 || addIndex > t.length) // 判断插入的下标是否满足顺序表
        printf("Insertion position is wrong!");

    if (t.length == t.size) // 判断顺序表是否还有内存存储，没有就重新申请内存
    {
        t.head = (int *)realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("realloc error!");
            return t;
        }
        t.size += 1;
    }

    for (int i = t.length - 1; i >= addIndex - 1; i--) // 从要插入下标的元素开始依次向后移动一个位置
        t.head[i + 1] = t.head[i];

    t.head[addIndex - 1] = elem; // 将元素插入到顺序表中
    t.length++;                  // 表长加一
    return t;
}

Table deleteTable(Table t, int deleteIndex)
{
    if (deleteIndex < 1 || deleteIndex > t.length) // 先判断要删除的下标是否满足顺序表
        printf("The deleted subscript doesn't exist");

    for (int i = deleteIndex; i <= t.length; i++) // 从被删除元素下标开始依次先前移动一个位置
        t.head[i - 1] = t.head[i];

    t.length--; // 表长减一
    return t;
}

int selectTable(Table t, int elem)
{
    for (int i = 0; i < t.length; i++)
        if (t.head[i] == elem)
            return i
                   + 1; // 遍历顺序表判断要查找的元素是否在表中，如果在就返回它的位置，不在就返回-1表示查找失败

    return -1;
}

Table updateTable(Table t, int elem, int updateElem)
{
    int temp = selectTable(
        t,
        elem); // 先查找顺序表中有没有这个元素，如果有就把它的下标赋值给临时变量，没有就在查找函数中返回-1
    t.head[temp - 1] = updateElem; // 将查找后元素下标对应在顺序表中的值进行修改
    return t;
}