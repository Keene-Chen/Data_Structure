#include "sequence_table.h"

CNode CreateCirCleNode(int n) // 往顺序表中读入数据
{
    CNode cn;
    cn = new CirCleNode;
    for (int i = 0; i < n; i++) {
        cn->data[i] = i + 1;
    }
    cn->last = n;
    return cn;
}

int PushCirCleNode(CNode cn, int m) // 顺序表出队
{
    int count = 0, i = 0, num = 0, j = 0, Temp[MAX_SIZE];
    while (count < cn->last) {
        while (num < m && count < cn->last) {
            i = i % cn->last + 1; // 约瑟夫环的每轮起始位置
            if (cn->data[i - 1])  // 非0的时候让计数器自加
            {
                num++;
            }
        }
        count++;
        Temp[j++]       = cn->data[i - 1];
        cn->data[i - 1] = 0; // 出队的时候置为0
        num             = 0; // 计数器清零
    }
    return Temp[cn->last - 1];
}