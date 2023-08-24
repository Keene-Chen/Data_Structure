#include "array.h"

int Array(int n, int m)
{
    int i, temp, j;
    int k = 0; // 假设从第一个开始报数
    int Jsp[MAX_SIZE];
    for (i = 0; i < n; i++) {
        Jsp[i] = i + 1;
    }
    for (i = n; i >= 1; i--) {
        k    = (k + m - 1) % i; // 用数组的下标构造一个虚假循环
        temp = Jsp[k];          // temp保存要出队的值
        for (j = k; j < i; j++) // 将k以后的数组往前移
        {
            Jsp[j] = Jsp[j + 1];
        }
    }
    return temp;
}