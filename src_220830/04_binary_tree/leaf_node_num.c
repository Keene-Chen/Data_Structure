/**
 * @file    : leaf_node_num.c
 * @author  : KeeneChen
 * @date    : 2022.09.02-09:14:02
 * @details : leaf_node_num
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

/**
 * @brief  使用递归思想计算叶子结点个数
 * @param  root 根结点
 * @param  num  传入传出,叶子结点数量
 * @return void
 */
void leaf_node_num(binary_node_t *root, int *num)
{
    isNULL(root);

    // 当左右子树都为NULL时为叶子结点
    if (root->lchild == NULL && root->rchild == NULL)
        (*num)++;
    leaf_node_num(root->lchild, num);
    leaf_node_num(root->rchild, num);
}

/**
 * @brief  获取树的高度/深度
 * @param  root 根结点
 * @return int  树的高度
 */
int get_tree_height(binary_node_t *root)
{
    if (root == NULL)
        return 0;

    // 获取左子树高度
    int lheight = get_tree_height(root->lchild);

    // 获取右子树高度
    int rheight = get_tree_height(root->rchild);

    // 比较高度取最大值+1
    int height = lheight > rheight ? lheight + 1 : rheight + 1;
    return height;
}

/**
 * @brief  拷贝二叉树
 * @param  待拷贝二叉树的根结点
 * @return binary_node_t* 拷贝出来后的新根结点
 */
binary_node_t *copy_tree(binary_node_t *root)
{
    if (root == NULL)
        return NULL;

    // 拷贝左子树
    binary_node_t *lchild = copy_tree(root->lchild);
    // 拷贝右子树
    binary_node_t *rchild = copy_tree(root->rchild);
    // 新建根结点
    binary_node_t *new_node = malloc(sizeof(binary_node_t));
    new_node->ch            = root->ch;
    new_node->lchild        = lchild;
    new_node->rchild        = rchild;

    return new_node;
}

/**
 * @brief  递归遍历二叉树,先序遍历
 * @param  root 根结点
 * @return void
 */
static void recursion(binary_node_t *root)
{
    isNULL(root);

    // 先序遍历 根左右
    printf("%c -> ", root->ch);
    recursion(root->lchild);
    recursion(root->rchild);
}

/**
 * @brief  释放二叉树
 * @param  int
 * @param  int
 * @return int
 */
void free_tree(binary_node_t *root)
{
    isNULL(root);

    // 先释放左子树
    free_tree(root->lchild);
    // 在释放右子树
    free_tree(root->rchild);
    // 释放根结点
    printf("free %c\n", root->ch);
    free(root);
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

    int num = 0;
    leaf_node_num(&node_A, &num);
    printf("二叉树叶子结点个数:%d\n", num);

    printf("二叉树高度:%d\n", get_tree_height(&node_A));

    binary_node_t *new_node = copy_tree(&node_A);
    recursion(&node_A);
    printf("NULL\n");
    recursion(new_node);
    printf("NULL\n");

    free_tree(new_node);

    return 0;
}