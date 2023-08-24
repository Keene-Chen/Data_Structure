/**
 * @file    : 随机数冒泡排序.c
 * @author  : KeeneChen
 * @date    : 2023.08.24-15:43:34
 * @details : 随机数冒泡排序
 */

#include "/home/hellochen/Documents/C_Language/lib/Hello_C.h"
#include <stdio.h>

#define LEN 10

int main(void)
{
    srand((unsigned)time(NULL)); // 根据时间重播随机种子

    int a[LEN] = { 0 };

    for (int i = 0; i < LEN; i++) {
        a[i] = rand() % 100;
        usleep(1000); // 1秒=10^6微秒
    }

    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j]     = a[j + 1];
                a[j + 1] = temp;
            }

    show_array(a, LEN);

    return 0;
}
