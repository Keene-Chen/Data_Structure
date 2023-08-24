#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int count;
} LinkStack;

LinkStack *init_link_stack();
void show_link_stack(LinkStack *stack);
LinkStack *push(LinkStack *stack, int elem);
LinkStack *pop(LinkStack *stack);

int main(void)
{
    LinkStack *stack = init_link_stack();

    for (int i = 1; i < 3; i++) {
        push(stack, i);
    }

    printf("栈中的元素总数%d\n", stack->count);
    show_link_stack(stack);
    printf("弹出一个元素\n");
    pop(stack);
    pop(stack);
    show_link_stack(stack);

    return 0;
}

LinkStack *init_link_stack()
{
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    if (!p) {
        printf("内存分配失败\n");
        exit(0);
    }

    p->count = 0;
    p->top   = NULL;

    return p;
}

LinkStack *push(LinkStack *stack, int elem)
{
    if (!stack)
        return NULL;

    // 创建一个新结点
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = elem;

    // 相当于链表的头插法
    NewNode->next = stack->top; // 新结点的next指向栈顶
    stack->top    = NewNode;    // 栈顶更改为插入进来的新结点
    stack->count++;             // 栈计数器加1

    return stack;
}

LinkStack *pop(LinkStack *stack)
{
    Node *temp = stack->top; // 把栈顶结点保存到临时节点中，方便free释放
    if (!stack->top) {
        printf("栈为空");
        exit(0);
    }
    else {
        stack->top = stack->top->next;
        free(temp);
        stack->count--;
        return stack;
    }
}

void show_link_stack(LinkStack *stack)
{
    Node *temp = stack->top;

    if (!stack) // stack==NULL
    {
        printf("栈为空");
        exit(0);
    }
    while (temp != NULL) // 只要栈顶不为空就循环
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
