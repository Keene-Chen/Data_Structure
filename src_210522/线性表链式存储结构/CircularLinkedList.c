#include <stdio.h>
#include <stdlib.h>

typedef struct circularLinkedList {
    int data;
    struct circularLinkedList *next;
} CirList;

int main(void)
{

    return 0;
}

CirList *initCircularList()
{
    CirList *head = (CirList *)malloc(sizeof(CirList));
    CirList *temp = head;

    for (int i = 1; i < 6; i++) {
        CirList *node = (CirList *)malloc(sizeof(CirList));
        node->data    = i;

        temp->next = node;
        temp       = temp->next;
        node->next = NULL;
    }
    return head;
}