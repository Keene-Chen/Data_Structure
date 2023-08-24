#include "single_circular_list.h"

Node CreteNode(int n) // 创建不带头结点单链表
{
    Node p, q, t;
    int i;
    t = p   = new node;
    p->data = 1;
    for (i = 2; i <= n; i++) {
        q       = new node; // 申请新的结点插入链表
        q->data = i;
        p->next = q;
        p       = q;
        // printf("--%d",p->data);
    }
    p->next = t;
    return t;
}

int DeleteNode(Node nd, int m) // 出队
{
    Node t;
    int i;
    while (nd->next != nd) {
        for (i = 1; i < m - 1; i++) // 找到要删除结点的前一个结点
            nd = nd->next;
        t = nd->next;
        // printf("->%d",t->data);
        nd->next = t->next;
        delete t;
        nd = nd->next; // 将结点指向被删除结点后一个结点
    }
    return nd->data;
}