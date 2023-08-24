#ifndef __SINGLE_CIRCULAR_LIST_H__
#define __SINGLE_CIRCULAR_LIST_H__

typedef struct node {
    int data;
    struct node *next;
} *Node;

Node CreteNode(int n);
int DeleteNode(Node nd, int m);

#endif // __SINGLE_CIRCULAR_LIST_H__