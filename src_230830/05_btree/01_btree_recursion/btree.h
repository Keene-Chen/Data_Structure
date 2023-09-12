/**
 * @file    : btree.h
 * @author  : KeeneChen
 * @date    : 2023.09.11-15:40:18
 * @details : btree recursion
 */

#ifndef __BTREE_H__
#define __BTREE_H__

#define DEBUG_BTREE   0 // 开启画树详情
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

struct student {
    int id;
    char name[32];
    int age;
    int score;
};

/* 二叉树结点结构 */
struct node_st {
    struct student data;
    struct node_st *left;  // 左孩子
    struct node_st *right; // 右孩子
};

enum {
    preorder, // 先序遍历
    inorder,  // 中序遍历
    postorder // 后序遍历
};

/**
 * @brief  btree_insert 二叉树插入结点
 * @param  struct node_st **root 无头结点的指针,指向二叉树结构
 * @note 因为没有头结点管理,所有要使用二级指针来修改二叉树结构的数据
 * @param  struct student *data 指向结点数据的指针
 * @return int 插入是否成功
 * @retval 0 成功
 * @retval non-zero 失败
 */
int btree_insert(struct node_st **root, struct student *data);

/**
 * @brief  btree_find 根据id查找二叉树中对应结点
 * @param  struct node_st *root 二叉树
 * @param  int id 待查找的id
 * @return struct student *node 查找到的结点数据
 */
struct student *btree_find(struct node_st *root, int id);

/**
 * @brief  btree_draw 画二叉树
 * @note 使用 DEBUG_BTREE 宏可开启画树的步骤
 * @return void
 */
void btree_draw(struct node_st *root);

/**
 * @brief  balance_btree 平衡二叉树
 * @param  struct node_st **root 指向二叉树结构的指针
 * @return void
 */
void balance_btree(struct node_st **root);

/**
 * @brief  balance_btree 根据id删除二叉树上的结点数据
 * @param  struct node_st **root 指向二叉树结构的指针
 * @param  int id 待删除id
 * @return void
 */
void btree_delete(struct node_st **root, int id);

/**
 * @brief  balance_btree 根据id删除二叉树上的结点数据
 * @param  struct node_st *root 二叉树结构
 * @param  int tarvel_way 遍历方式:
           preorder  先序遍历
           inorder   中序遍历
           postorder 后序遍历
 * @return void
 */
void btree_travel(struct node_st *root, int tarvel_way);

void preorder_travel(struct node_st *root);

#endif // __BTREE_H__