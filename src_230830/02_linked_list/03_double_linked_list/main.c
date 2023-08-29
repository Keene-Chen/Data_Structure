#include "double_linked_list.h"

int main(void)
{
    Node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("双向循环链表的元素：");
    display(head);

    destroy(&head);

    return 0;
}