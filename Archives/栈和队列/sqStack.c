#include "sqStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sqStack p;
    char ch;

    p.size = MAX_SIZE;
    p      = initStack(p); // 初始化栈

    printf("Do you want to push to sqStack?(Y/N): ");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y') {
        p = push(p);  // 入栈
        showStack(p); // 打印栈中元素
        printf("\nDo you want to push to sqStack?(Y/N): ");
        scanf(" %c", &ch);
    }

    printf("\nDo you want to pop (Y/N): ");
    scanf(" %c", &ch);
    printf("\n");
    while (ch == 'Y' || ch == 'y') {
        p = pop(p);
        showStack(p);
        printf("Do you want to pop (Y/N): ");
        scanf(" %c", &ch);
    }

    return 0;
}

/* Function：栈的初始化 */
sqStack initStack(sqStack p)
{
    p.bottom = (int *)malloc(p.size * sizeof(int));
    if (p.bottom == NULL) {
        printf("初始化栈失败\n");
        exit(0);
    }
    p.top  = p.bottom;
    p.size = MAX_SIZE;

    return p;
}

/* Function：遍历栈中元素，从栈顶到栈底*/
void showStack(sqStack p)
{
    if (isStackEmpty(p) == Empty) {
        printf("栈为空栈，无法遍历\n");
        exit(0);
    }
    printf("栈中元素为：");
    printf("顶端-> [");
    while (p.top != p.bottom) {
        p.top--;
        printf("%d-", *p.top);
    }
    printf("] <-底端\n");
}

/* Function：判断栈是否为空 */
int isStackEmpty(sqStack p)
{
    return ((p.top == p.bottom) ? Empty : Avail);
}

/* Function：判断栈是否为满 */
int isStackFull(sqStack p)
{
    return ((p.top - p.bottom == p.size) ? Full : Avail);
}

/* Function：入栈 */
sqStack push(sqStack p)
{
    int data;
    if (isStackFull(p) == Full) {
        printf("栈空间已满，无法入栈");
        return p;
    }
    printf("Please input data: ");
    scanf("%d", &data);
    *p.top = data;
    p.top++;

    return p;
}

/* Function：出栈 */
sqStack pop(sqStack p)
{
    if (isStackEmpty(p) == Empty) {
        printf("栈为空栈，无法出栈 ");
        return p;
    }
    p.top--;
    printf("出栈元素为：%d\n", *p.top);

    return p;
}