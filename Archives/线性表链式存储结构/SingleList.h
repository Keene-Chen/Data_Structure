/**
 * Author:   hellochen
 * DateTime: 2021.04.01-15:06:19
 * Description: 单链表结构和函数声明
 */

/* variable statement*/
#define ASTERISK \
    "**************************************************************\n\n" // Asterisk separator

typedef struct link {
    int elem;
    struct link *next;
} Link;

/* function statement*/
Link *initLinkListH();
void showLinkListH(Link *p);
Link *insertLinkList(Link *p, int elem, int addIndex);
Link *deleteLinkList(Link *p, int delIndex);
int selectLinkList(Link *p, int elem);
Link *updateLinkList(Link *p, int elem, int updateElem);