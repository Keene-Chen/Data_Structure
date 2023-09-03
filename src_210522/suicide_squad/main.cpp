/**
 * Author:   KeeneChen
 * DateTime: 2022.05.19-16:30:43
 * Description: 敢死队问题
 * Command: g++ .\main.cpp .\array.cpp .\circular_queue.cpp .\recursion.cpp .\sequence_table.cpp
 * .\single_circular_list.cpp
 */

#include "array.h"
#include "circular_queue.h"
#include "recursion.h"
#include "sequence_table.h"
#include "single_circular_list.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int array[MAX_SIZE], num, Templete, push; // Templete保存递归算法的返回值
// 以下数组操作都是从下标0开始，真正的数据编号是从1开始

void function()
{
    printf("*****************************************************\n");
    printf("请输入总人数:");
    scanf("%d", &num);
    printf("*****************************************************\n");
    printf("请输入间隔人数:");
    scanf("%d", &push);
    if (num < 1 || push < 1) {
        printf("输入错误请重新输入:\n");
        exit(1);
    }
    if (num == 1) {
        printf("要使排长安全则应该从第%d号开始.\n", num);
        exit(1);
    }
    printf("*****************************************************\n");
}

int main()
{
    int flag;                 // num总人数,以push出队
    int result = 0, temp = 0; // result最后出队的人的编号
    SequeNode SNode = new Seque;

    printf("**********************敢死队问题*********************\n");
    function();
    printf("根据菜单提示选择相应的算法\n");
    printf("*****************************************************\n");
    printf("1、顺序表\n2、链表\n3、数组\n4、队列\n5、递归\n6、退出\n");
    printf("请输入对应算法：\n");

    while (scanf("%d", &flag)) {
        if (flag == 6) {
            break;
        }
        switch (flag) {
        case 1:
            CNode cnode;
            cnode  = CreateCirCleNode(num);
            result = PushCirCleNode(cnode, push);
            break;
        case 2:
            Node LNode;
            LNode  = CreteNode(num);
            result = DeleteNode(LNode, push);
            break;
        case 3:
            result = Array(num, push);
            break;
        case 4:
            Iniqueue(SNode);
            AddQueue(SNode, num);
            result = outQueue(SNode, num, push);
            break;
        case 5:
            CreateArray(num);
            SearchArray(1, push);
            result = Templete;
            break;
        default:
            result = 0;
            printf("<<请根据菜单提示操作>>\n");
            break;
        }
        if (result != 0) {
            temp = (num - result + 2) % num; // 运用数学思想求出第一个开始位置
            if (temp == 0) {
                printf("要使排长安全则应该从第%d号开始报数.\n", num);
            }
            else {
                printf("要使排长安全则应该从第%d号开始报数.\n", temp);
            }
        }
    }
    printf("*****************************************************\n");
    return 0;
}