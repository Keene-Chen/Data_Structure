/**
 * Author:   hellochen
 * DateTime: 2021.04.01-14:17:19
 * Description: 单链表的创建
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int elem;          // 代表数据域
    struct link *next; // 代表指针域，指向直接后继元素
} Link;                // link为节点名，每个节点都是一个 Link 结构体

Link *initLinkList();
void showLinkList(Link *p);
Link *initLinkListH();
void showLinkListH(Link *p);

int main(void)
{
    Link *p1 = initLinkList();
    showLinkList(p1);
    printf("--------------------------\n");
    Link *p2 = initLinkListH();
    showLinkListH(p2);
    return 0;
}

Link *initLinkList()
{
    Link *p    = NULL;                         // 创建头指针
    Link *temp = (Link *)malloc(sizeof(Link)); // 创建首元节点

    temp->elem = 1; // 首元节点先初始化
    temp->next = NULL;
    p          = temp; // 头指针指向首元节点

    for (int i = 2; i <= 10; i++) {
        Link *a    = (Link *)malloc(sizeof(Link));
        a->elem    = i;
        a->next    = NULL;
        temp->next = a;
        temp       = temp->next;
    }
    return p;
}

void showLinkList(Link *p)
{
    Link *temp = p; // 将temp指针重新指向头结点
    // 只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

Link *initLinkListH()
{
    Link *p    = (Link *)malloc(sizeof(Link)); // 创建一个头结点
    Link *temp = p;                            // 声明一个指针指向头结点，

    for (int i = 1; i <= 10; i++) // 生成链表
    {
        Link *a    = (Link *)malloc(sizeof(Link));
        a->elem    = i;
        a->next    = NULL;
        temp->next = a;
        temp       = temp->next;
    }
    return p;
}

void showLinkListH(Link *p)
{
    Link *temp = p; // 将temp指针重新指向头结点
    // 只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}