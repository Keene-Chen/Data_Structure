/**
 * Author:   hellochen
 * DateTime: 2021.04.06-17:27:13
 * Description: 声明Stack
 */

#define MAX_SIZE 5  // 栈最大容量
#define Empty    0  // 空
#define Full     1  // 满
#define Avail    -1 // 可用

typedef struct sqstack {
    int *top;    // 栈顶指针
    int *bottom; // 栈底指针
    int size;    // 栈的最大容量
} sqStack;

sqStack initStack(sqStack p); // 初始化栈
void showStack(sqStack p);    // 遍历栈中元素
int isStackEmpty(sqStack p);  // 判断栈是否为空
int isStackFull(sqStack p);   // 判断栈是否为满
sqStack push(sqStack p);      // 入栈
sqStack pop(sqStack p);       // 出栈