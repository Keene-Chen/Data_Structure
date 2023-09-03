#include <stdio.h>
#include <stdlib.h>

typedef struct doublyLsit {
    int data;
    struct doublyLsit *prev, *next;
} DoublyList;

DoublyList *initDoublryList()
{
    DoublyList *head = (DoublyList *)malloc(sizeof(DoublyList));

    if (head == NULL) {
        printf("分配内存失败！");
        exit(0);
    }

    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

    DoublyList *list = head;

    for (int i = 2; i <= 3; i++) {
        // 创建并初始化一个新结点
        DoublyList *body = (DoublyList *)malloc(sizeof(DoublyList));
        body->prev       = NULL;
        body->next       = NULL;
        body->data       = i;

        list->next = body; // 直接前趋结点的next指针指向新结点
        body->prev = list; // 新结点指向直接前趋结点
        list       = list->next;
    }

    return head;
}

void showDoublyList(DoublyList *head)
{
    DoublyList *temp = head;
    while (temp) {
        // 如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL)
            printf("%d\n", temp->data);
        else
            printf("%d <-> ", temp->data);

        temp = temp->next;
    }
}

int main(void)
{
    DoublyList *head = initDoublryList();
    showDoublyList(head);
    return 0;
}