#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data);
void insert(Node **head, int data);
void display(Node *head);
void destroy(Node **head);

#endif // __DOUBLE_LINKED_LIST_H__