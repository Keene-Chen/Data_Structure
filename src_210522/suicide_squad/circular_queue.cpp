#include "circular_queue.h"
// 队列操作是先进先出，且每次删除队首，队尾进

// 置空队
void Iniqueue(SequeNode p)
{
    p->front = 0;
    p->rear  = 0;
}

int AddQueue(SequeNode p, int n) // 入队
{
    if ((p->rear + 1) % n == p->front) {
        return 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            p->rear          = (p->rear + 1) % n;
            p->data[p->rear] = i;
            // printf("--%d",p->data[p->rear]);
        }
        return 1;
    }
}

int outQueue(SequeNode p, int n, int m)
{
    int temp = 0, k = 0, Temp[MAX_SIZE];
    if (p->rear == (p->front + 1) % n) {
        return 0;
    }
    else {
        p->front = (p->front + 1) % n;
        for (int i = 0; i < n; i++) {
            while (temp < m) // 找到被删除结点的后一结点
            {
                p->front = (p->front + 1) % n;
                if (p->front == 0) // 当头结点的下标是0时改变其下标
                {
                    p->front = n;
                }
                if (p->data[p->front - 1] != 0) // 非零结点时让temp++
                    temp++;
            }
            Temp[i]               = p->data[p->front - 1];
            p->data[p->front - 1] = 0; // 把找到的那个结点置零
            // printf("--%d",Temp[i]);
            temp = 0;
        }
        return Temp[n - 1];
    }
}