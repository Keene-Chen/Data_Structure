#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
    int data;
    struct linkedList *next;
} LinkedList;

LinkedList *initList();                          // 初始化单链表
void showList(LinkedList *p);                    // 打印单链表
LinkedList *iterationReverseList(LinkedList *p); // 单链表迭代逆序
LinkedList *recursiveReverseList(LinkedList *p); // 单链表迭代逆序

int main(void)
{
    LinkedList *head = initList();
    printf("原链表\n");
    showList(head);
    printf("迭代逆序后的单链表\n");
    LinkedList *list = iterationReverseList(head);
    showList(list);
    printf("递归逆序后的单链表\n");
    LinkedList *list1 = recursiveReverseList(list);
    showList(list1);

    return 0;
}

LinkedList *initList()
{
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
    if (head == NULL) {
        printf("初始化失败");
        exit(0);
    }

    LinkedList *temp = head; // 创建临时结点指向头结点

    for (int i = 1; i < 6; i++) // 尾插法添加结点
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->data       = i; // 结点数据域赋值

        temp->next = node;
        temp       = temp->next; // 把当前结点指向下一个结点，或者temp=node;
        node->next = NULL;
    }

    return head;
}

void showList(LinkedList *p)
{
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkedList *iterationReverseList(LinkedList *p)
{
    LinkedList *head = p; // 创建临时结点指向头结点
    LinkedList *next, *prev = NULL;

    while (head != NULL) // 遍历单链表，不为NULL就循环，为NULL终止
    {
        next       = head->next; // 将指针指向首元结点
        head->next = prev;       // 断开头结点把头结点插入到prev指针中
        prev       = head;       //  将head和next指针后移实现迭代
        head       = next;
    }

    return prev;
}

LinkedList *recursiveReverseList(LinkedList *p)
{
    LinkedList *head = p, *newHead;

    if ((head == NULL) || (head->next == NULL))
        return head;
    newHead          = recursiveReverseList(head->next);
    head->next->next = head;
    head->next       = NULL;

    return newHead;
}