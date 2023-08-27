/**
 * @file    : binary_tree_recursion.c
 * @author  : KeeneChen
 * @date    : 2022.09.02-08:48:21
 * @details : binary_tree_recursion
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isNULL(x)    \
    if ((x) == NULL) \
        return;

typedef struct binary_node_s {
    char ch;
    struct binary_node_s *lchild;
    struct binary_node_s *rchild;
} binary_node_t;

void preorder_traversal(binary_node_t *root)
{
    isNULL(root);

    // 先序遍历 根左右
    printf("%c -> ", root->ch);
    preorder_traversal(root->lchild);
    preorder_traversal(root->rchild);
}

void inorder_traversal(binary_node_t *root)
{
    isNULL(root);

    // 中序遍历 左根右
    inorder_traversal(root->lchild);
    printf("%c -> ", root->ch);
    inorder_traversal(root->rchild);
}

void postorder_traversal(binary_node_t *root)
{
    isNULL(root);

    // 后序遍历 左右根
    postorder_traversal(root->lchild);
    postorder_traversal(root->rchild);
    printf("%c -> ", root->ch);
}

int main(void)
{
    binary_node_t node_A = { 'A', NULL, NULL };
    binary_node_t node_B = { 'B', NULL, NULL };
    binary_node_t node_C = { 'C', NULL, NULL };
    binary_node_t node_D = { 'D', NULL, NULL };
    binary_node_t node_E = { 'E', NULL, NULL };
    binary_node_t node_F = { 'F', NULL, NULL };
    binary_node_t node_G = { 'G', NULL, NULL };
    binary_node_t node_H = { 'H', NULL, NULL };

    node_A.lchild = &node_B;
    node_A.rchild = &node_F;
    node_B.rchild = &node_C;
    node_C.lchild = &node_D;
    node_C.rchild = &node_E;
    node_F.rchild = &node_G;
    node_G.lchild = &node_H;

    printf("先序遍历\n");
    preorder_traversal(&node_A);
    printf("\n中序遍历\n");
    inorder_traversal(&node_A);
    printf("\n后序遍历\n");
    postorder_traversal(&node_A);
    printf("\n");

    return 0;
}