/**
 * @file    : btree.c
 * @author  : KeeneChen
 * @date    : 2023.09.11-15:40:33
 * @details : btree
 */

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

/* 学生结构体打印宏 */
#define printf_stu(x)                                                            \
    do {                                                                         \
        printf("id:%d name:%s age:%d score:%d\n", x.id, x.name, x.age, x.score); \
    } while (0)

/**
 * @brief  btree_insert 二叉树插入结点
 * @param  struct node_st **root 无头结点的指针,指向二叉树结构
 * @note 因为没有头结点管理,所有要使用二级指针来修改二叉树结构的数据
 * @param  struct student *data 指向结点数据的指针
 * @return int 插入是否成功
 * @retval 0 成功
 * @retval non-zero 失败
 */
int btree_insert(struct node_st **root, struct student *data)
{
    struct node_st *node = NULL;

    // 二叉树为空就插入元素
    if (*root == NULL) {
        node = malloc(sizeof(struct node_st));
        if (node == NULL)
            return -1;

        node->data  = *data;
        node->left  = NULL;
        node->right = NULL;
        *root       = node;

        return 0;
    }

    // 如果待插入元素id小于等于二叉树中的id就向左子树插入
    if (data->id <= (*root)->data.id) {
        return btree_insert(&(*root)->left, data);
    }
    return btree_insert(&(*root)->right, data);
}

/**
 * @brief  btree_find 根据id查找二叉树中对应结点
 * @param  struct node_st *root 二叉树
 * @param  int id 待查找的id
 * @return struct student *node 查找到的结点数据
 */
struct student *btree_find(struct node_st *root, int id)
{
    if (root == NULL)
        return NULL;
    if (id == root->data.id)
        return &root->data;

    // 如果待查找元素id小于二叉树中的id就向左子树查找
    if (id < root->data.id)
        return btree_find(root->left, id);
    else
        return btree_find(root->right, id);
}

/**
 * @brief  draw_ 用于内部画树函数,即将二叉树示意图向左旋转90°即可,并非平衡二叉树左旋或右旋
 * @param  struct node_st *root 二叉树
 * @param  int level 根据层级计算出需要打印的空格数量
 * @return void
 */
static void draw_(struct node_st *root, int level)
{
    if (root == NULL)
        return;
    draw_(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("(%d)\n", root->data.id);

    draw_(root->left, level + 1);
}

/**
 * @brief  btree_draw 画二叉树
 * @note 使用 DEBUG_BTREE 宏可开启画树的步骤
 * @return void
 */
void btree_draw(struct node_st *root)
{
    draw_(root, 0);

#if DEBUG_BTREE
    printf("\n\n");
    getchar();
#endif
}

/* 一系列辅助函数 */
static int get_num_(struct node_st *root)
{
    if (root == NULL)
        return 0;
    return get_num_(root->left) + 1 + get_num_(root->right);
}

static struct node_st *min_(struct node_st *root)
{
    if (root->left == NULL)
        return root;
    return min_(root->left);
}

static struct node_st *max_(struct node_st *root)
{
    if (root->right == NULL)
        return root;
    return max_(root->right);
}

/**
 * @brief  trun_left_ 内部函数,二叉树左旋
 * @param  struct node_st **root 指向二叉树结构的指针
 * @return void
 */
static void trun_left_(struct node_st **root)
{
    struct node_st *cur = *root;
    *root               = cur->right;
    cur->right          = NULL;
    min_(*root)->left   = cur;

#if DEBUG_BTREE
    btree_draw(*root);
#endif
}

static void trun_right_(struct node_st **root)
{
    struct node_st *cur = *root;
    *root               = cur->left;
    cur->left           = NULL;
    max_(*root)->right  = cur;

#if DEBUG_BTREE
    btree_draw(*root);
#endif
}

/**
 * @brief  balance_btree 平衡二叉树
 * @param  struct node_st **root 指向二叉树结构的指针
 * @return void
 */
void balance_btree(struct node_st **root)
{
    if (*root == NULL)
        return;

    for (;;) {
        // 获取左子树减去右子树个数
        int sub = get_num_((*root)->left) - get_num_((*root)->right);
        // 个数小于1或者大于等于-1就平衡
        if (sub >= -1 && sub <= 1)
            break;
        // 小于-1左旋
        if (sub < -1)
            trun_left_(root);
        else
            trun_right_(root);
    }

    // 递归去平衡左右子树
    balance_btree(&(*root)->left);
    balance_btree(&(*root)->right);
}

/**
 * @brief  balance_btree 根据id删除二叉树上的结点数据
 * @param  struct node_st **root 指向二叉树结构的指针
 * @param  int id 待删除id
 * @return void
 */
void btree_delete(struct node_st **root, int id)
{
    struct node_st **node = root;
    struct node_st *cur   = NULL;

    // 查找失败
    if (*node == NULL)
        return;

    // 查找待操作结点
    while (*node != NULL && (*node)->data.id != id) {
        if (id < (*node)->data.id)
            node = &(*node)->left;
        else
            node = &(*node)->right;
    }

    // ? 未理解原理
    cur = *node;
    if (cur->left == NULL)
        *node = cur->right;
    else {
        *node                  = cur->left;
        max_(cur->left)->right = cur->right;
    }
    free(cur);
}

/**
 * @brief  balance_btree 根据id删除二叉树上的结点数据
 * @param  struct node_st *root 二叉树结构
 * @param  int tarvel_way 遍历方式:
           preorder  先序遍历
           inorder   中序遍历
           postorder 后序遍历
 * @return void
 */
void btree_travel(struct node_st *root, int tarvel_way)
{
    if (tarvel_way < 0 && tarvel_way > 2)
        tarvel_way = 0;

    if (root == NULL)
        return;
    switch (tarvel_way) {
    case 0: // 根左右
        printf_stu(root->data);
        btree_travel(root->left, tarvel_way);
        btree_travel(root->right, tarvel_way);
        break;
    case 1: // 左根右
        btree_travel(root->left, tarvel_way);
        printf_stu(root->data);
        btree_travel(root->right, tarvel_way);
        break;
    case 2: // 左右根
        btree_travel(root->left, tarvel_way);
        btree_travel(root->right, tarvel_way);
        printf_stu(root->data);
        break;
    }
}

void preorder_travel(struct node_st *root)
{
    if (root == NULL)
        return;

    printf("root:%d\n", root->data.id);
    if (root->left) {
        printf("%d 作为 %d 的左子树\n", root->left->data.id, root->data.id);
        preorder_travel(root->left);
    }
    if (root->right) {
        printf("%d 作为 %d 的右子树\n", root->right->data.id, root->data.id);
        preorder_travel(root->right);
    }
}
