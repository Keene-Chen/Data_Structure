/**
 * Author:   hellochen
 * DateTime: 2021.04.01-15:08:31
 * Description: 单链表的CURD操作
 */

#include "SingleList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Link *p = initLinkListH();
    printf("原始链表数据如下：\n");
    showLinkListH(p);

    printf(ASTERISK);
    insertLinkList(p, 26, 3);
    printf("插入后，链表数据：\n");
    showLinkListH(p);

    printf(ASTERISK);
    deleteLinkList(p, 4);
    printf("删除后，链表数据：\n");
    showLinkListH(p);

    printf(ASTERISK);
    int elem1 = 0;
    printf("请输入要查找的元素值：");
    scanf("%d", &elem1);
    int elem2 = selectLinkList(p, elem1);
    if (elem2 != -1) {
        printf("查找到元素%d的在链表中的第%d个位置\n", elem1, elem2);
    }
    else {
        printf("查找到元素%d的在链表中不存在\n", elem1);
    }

    printf(ASTERISK);
    int temp1 = 0, temp2 = 0;
    printf("请输入要更改的元素以及更改后的值：");
    scanf("%d %d", &temp1, &temp2);
    updateLinkList(p, temp1, temp2);
    showLinkListH(p);
    return 0;
}

Link *initLinkListH()
{
    Link *p    = (Link *)malloc(sizeof(Link)); // 创建一个头结点
    Link *temp = p;                            // 声明一个指针指向头结点

    for (int i = 1; i <= 10; i++) // 生成链表
    {
        Link *a = (Link *)malloc(sizeof(Link));
        a->elem = i;
        a->next = NULL;

        // 将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        // 指针temp每次都指向新链表的最后一个节点，其实就是
        // a节点，这里写temp=a也对,表尾是a，让temp=a就把新表尾重新覆盖原表尾了
        temp = temp->next; // temp=a;
    }
    return p;
}

void showLinkListH(Link *p)
{
    Link *temp = p;
    while (temp->next) {
        temp = temp->next;
        printf("%d -> ", temp->elem);
    }
    printf("NULL\n");
}

Link *insertLinkList(Link *p, int elem, int addIndex)
{
    Link *temp = p;
    for (int i = 1; i < addIndex; i++) {
        temp = temp->next; // 找到addIndex所在的前驱节点
        if (temp == NULL) {
            printf("insert error!\n");
            exit(0);
            return p;
        }
    }

    /* 创建一个新结点 */
    Link *newNode = (Link *)malloc(sizeof(Link));
    newNode->elem = elem;

    /* 通过钩链创建结点和链表的关系，及将结点插入到链表中 */
    newNode->next = temp->next;
    temp->next    = newNode;
    return p;
}

Link *deleteLinkList(Link *p, int delIndex)
{
    Link *temp = p;

    // 遍历到被删除结点的上一个结点
    for (int i = 1; i < delIndex; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("没有该结点\n");
            exit(0);
            return p;
        }
    }

    Link *del = temp->next;        // 单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; // 删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     // 手动释放该结点，防止内存泄漏

    return p;
}

int selectLinkList(Link *p, int elem)
{
    // 新建一个指针temp，初始化为头指针 p
    Link *temp = p;

    int count = 1;
    // 由于头节点的存在，因此while中的判断为temp->next
    while (temp->next) {
        temp = temp->next;
        if (temp->elem == elem) {
            return count;
        }
        count++;
    }
    // 程序执行至此处，表示查找失败
    return -1;
}

Link *updateLinkList(Link *p, int elem, int updateElem)
{
    Link *temp = p;

    temp = temp->next; // 在遍历之前，temp指向首元结点
    // 遍历到待更新结点
    for (int i = 1; i < elem; i++) {
        temp = temp->next;
    }

    temp->elem = updateElem;

    return p;
}