#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define MAX_SIZE 100

typedef struct Seque {
    int data[MAX_SIZE];
    int front;
    int rear;
} *SequeNode;

void Iniqueue(SequeNode p);
int AddQueue(SequeNode p, int n);
int outQueue(SequeNode p, int n, int m);

#endif // __CIRCULAR_QUEUE_H__