/**
 * @file    : binary_tree_non_recursion.c
 * @author  : KeeneChen
 * @date    : 2022.09.03-14:36:37
 * @details : 二叉树非递归遍历（栈实现）
 */

#include "seq_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树结构体定义
typedef struct binary_node_s {
    char ch;                      // 数据域
    int flag;                     // 标志
    struct binary_node_s *lchild; // 左孩子
    struct binary_node_s *rchild; // 右孩子
} binary_node_t;

/**
 * 非递归算法:
 * 1、将根节点 入栈
 * 2、只要栈中元素个数大于 0  执行循环
 *    获取栈顶元素
 *    出栈
 *    如果标志位真  直接输出  并且执行下一次循环
 *    如果为假 将标志改为真
 *    将右子树  左子树 根 入栈
 *    执行下一次循环
 */
void non_recursion(binary_node_t *root)
{
    seq_stack stack = seq_stack_init();
    seq_stack_push(stack, root);
    while (seq_stack_size(stack) > 0) {
        binary_node_t *top_elem = seq_stack_top(stack);
        seq_stack_pop(stack);
        if (top_elem->flag == 1) {
            printf("%c -> ", top_elem->ch);
            continue;
        }

        top_elem->flag = 1;

        // 入栈:右左根 出栈:根左右 等于先序遍历
        // if (top_elem->rchild != NULL)
        //     seq_stack_push(stack, top_elem->rchild);
        // if (top_elem->lchild != NULL)
        //     seq_stack_push(stack, top_elem->lchild);
        // seq_stack_push(stack, top_elem);

        // 入栈:右根左 出栈:左根右 等于中序遍历
        // if (top_elem->rchild != NULL)
        //     seq_stack_push(stack, top_elem->rchild);
        // seq_stack_push(stack, top_elem);
        // if (top_elem->lchild != NULL)
        //     seq_stack_push(stack, top_elem->lchild);

        // 入栈:根右左 出栈:左右根 等于后序遍历
        seq_stack_push(stack, top_elem);
        if (top_elem->rchild != NULL)
            seq_stack_push(stack, top_elem->rchild);
        if (top_elem->lchild != NULL)
            seq_stack_push(stack, top_elem->lchild);
    }
    seq_stack_destory(stack);
}

int main(void)
{
    binary_node_t node_A = { 'A', 0, NULL, NULL };
    binary_node_t node_B = { 'B', 0, NULL, NULL };
    binary_node_t node_C = { 'C', 0, NULL, NULL };
    binary_node_t node_D = { 'D', 0, NULL, NULL };
    binary_node_t node_E = { 'E', 0, NULL, NULL };
    binary_node_t node_F = { 'F', 0, NULL, NULL };
    binary_node_t node_G = { 'G', 0, NULL, NULL };
    binary_node_t node_H = { 'H', 0, NULL, NULL };

    node_A.lchild = &node_B;
    node_A.rchild = &node_F;
    node_B.rchild = &node_C;
    node_C.lchild = &node_D;
    node_C.rchild = &node_E;
    node_F.rchild = &node_G;
    node_G.lchild = &node_H;

    non_recursion(&node_A);
    printf("NULL\n");

    return 0;
}