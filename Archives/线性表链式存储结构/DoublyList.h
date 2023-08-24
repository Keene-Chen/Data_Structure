/**
 * Author:   hellochen
 * DateTime: 2021.04.02-16:16:10
 * Description: 双向链表的CURD操作
 */

#define ASTERISK \
    "**************************************************************\n\n" // Asterisk separator

typedef struct doublyList {
    int data;                // 数据域
    struct doublyList *prev; // 前趋指针
    struct doublyList *next; // 后趋指针
} DoublyList;

DoublyList *initDoublyList();
void showDoublyList(DoublyList *list);
DoublyList *insertDoublyList(DoublyList *list, int elem, int addIndex);
DoublyList *deleteDoublyList(DoublyList *list, int delElem);
int selectDoublyList(DoublyList *list, int elem);
DoublyList *updateDoublyList(DoublyList *list, int elem, int updateElem);