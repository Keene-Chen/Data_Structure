#ifndef __SEQUENCE_TABLE_H__
#define __SEQUENCE_TABLE_H__

#define MAX_SIZE 100

typedef struct CirCleNode {
    int data[MAX_SIZE];
    int last; // 顺序表的大小
} *CNode;

CNode CreateCirCleNode(int n);
int PushCirCleNode(CNode cn, int m);

#endif // __SEQUENCE_TABLE_H__