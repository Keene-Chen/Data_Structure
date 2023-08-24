#include "recursion.h"

extern int array[MAX_SIZE], num, Templete, push;
// Templete保存最后的返回值,results保存下标
void CreateArray(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        array[i] = i + 1;
    }
}
int SearchArray(int n, int m) // 思路参照数组
{
    int results;
    if (n > num) {
        return 0;
    }
    else {
        if (n == 1) {
            results = 0;
        }
        results = (SearchArray(n + 1, m) + m - 1) % n;
    }
    Templete = array[results];
    for (int j = results; j < n; j++) {
        array[j] = array[j + 1];
    }
    return Templete, results;
}