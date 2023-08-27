/**
 * @file    : example_match_nearby.c
 * @author  : KeeneChen
 * @date    : 2022.09.01-12:01:52
 * @details : stack的应用示例：就近匹配括号
 */

/**
 * 算法：
 * * 从第一个字符开始扫描
 * * 当遇见普通字符时忽略，
 * * 当遇见左括号时压入栈中
 * * 当遇见右括号时从栈中弹出栈顶符号，并进行匹配
 * * 匹配成功：继续读入下一个字符
 * * 匹配失败：立即停止，并报错
 * * 结束：
 * * 成功: 所有字符扫描完毕，且栈为空
 * * 失败：匹配失败或所有字符扫描完毕但栈非空
 */

#include "seq_stack.h"

int is_left_bracket(char ch)
{
    return ch == '(';
}

int is_right_bracket(char ch)
{
    return ch == ')';
}

void print_err(char *str, char *msg, char *index)
{
    printf("error:%s\n", msg);
    printf("%s\n", str);

    // 计算打印空格数量
    int num = index - str;
    for (int i = 0; i < num; i++)
        printf(" ");

    printf("^\n");
}

int main(void)
{
    // char* str = "5+5*(6)+9/3*1)-(1+3(";
    char *str = "5+5*(6)+9/3*1-(1+3(";
    char *ptr = str;

    seq_stack stack = seq_stack_init();

    // 遍历字符串
    while (*ptr != '\0') {
        // 如果遇到左括号,入栈
        if (is_left_bracket(*ptr)) {
            seq_stack_push(stack, ptr);
        }

        // 如果遇到右括号
        if (is_right_bracket(*ptr)) {
            // 栈中有元素,出栈
            if (seq_stack_size(stack) > 0) {
                seq_stack_pop(stack);
            }
            // 没有元素,右括号匹配不到左括号,停止,报错
            else {
                print_err(str, "右括号没有匹配到对应的左括号", ptr);
                break;
            }
        }
        ptr++;
    }

    // 遍历结束 判断是否有左括号没有匹配到对应的右括号
    while (seq_stack_size(stack) > 0) {
        print_err(str, "左括号没有匹配到对应的右括号", seq_stack_top(stack));
        // 出栈
        seq_stack_pop(stack);
    }

    // 销毁栈
    seq_stack_destory(stack);

    return 0;
}