/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.11-15:41:10
 * @details : main
 */

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct student stu;
    struct node_st *btree = NULL;

    int arr[] = { 1, 2, 3, 7, 6, 5, 9, 8, 4 };
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        stu.id = arr[i];
        snprintf(stu.name, sizeof(stu.name), "stu_%02d", arr[i]);
        stu.age   = rand() % 100;
        stu.score = rand() % 100;
        btree_insert(&btree, &stu);
    }

    printf("\n画出二叉树\n");
    btree_draw(btree);

    int tmp             = 2;
    struct student *ret = btree_find(btree, tmp);
    if (ret == NULL)
        printf("canot find the %d\n", tmp);
    else
        printf("id:%d name:%s age:%d score:%d\n", ret->id, ret->name, ret->age, ret->score);

#if DEBUG_BTREE
    printf("开始平衡二叉树的过程\n");
#endif
    balance_btree(&btree);
    printf("\n平衡后的二叉树\n");
    btree_draw(btree);

    // int tmpid = 7;
    // btree_delete(&btree, tmpid);
    // printf("\n删除结点为%d后的二叉树\n", tmpid);
    // btree_draw(btree);

#if DEBUG_BTREE
    printf("\n先序遍历二叉树的过程\n");
    preorder_travel(btree);
#endif

    printf("\n先序遍历二叉树\n");
    btree_travel(btree, preorder);
    printf("\n中序遍历二叉树\n");
    btree_travel(btree, inorder);
    printf("\n后序遍历二叉树\n");
    btree_travel(btree, postorder);

    return 0;
}