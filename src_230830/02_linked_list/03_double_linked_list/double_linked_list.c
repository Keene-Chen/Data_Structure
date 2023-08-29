#include "double_linked_list.h"

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL) {
        // 如果链表为空，将新节点作为头节点
        *head         = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else {
        // 找到最后一个节点
        Node *last = (*head)->prev;

        // 在最后一个节点之后插入新节点
        last->next    = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

void display(Node *head)
{
    if (head == NULL) {
        printf("链表为空.\n");
        return;
    }

    Node *current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

void destroy(Node **head)
{
    if (*head == NULL) {
        return;
    }

    Node *current = *head;
    Node *next    = NULL;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}
