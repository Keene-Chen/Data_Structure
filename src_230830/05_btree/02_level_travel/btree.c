/**
 * @file    : btree.c
 * @author  : KeeneChen
 * @date    : 2023.09.12-18:46:49
 * @details : btree
 */

#include "btree.h"
#include "list_queue.h"
#include <stdio.h>
#include <stdlib.h>

int btree_insert(struct node_st **root, struct student *data)
{
    struct node_st *node = NULL;
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

    if (data->id <= (*root)->data.id) {
        return btree_insert(&(*root)->left, data);
    }
    return btree_insert(&(*root)->right, data);
}

static struct node_st *max_(struct node_st *root)
{
    if (root->right == NULL)
        return root;
    return max_(root->right);
}

int btree_delete(struct node_st **root, int id)
{
    struct node_st **node = root;
    struct node_st *cur   = NULL;

    // 查找失败
    if (*node == NULL)
        return -1;

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

    return 0;
}

int level_travel_list_queue(struct node_st *root)
{
    if (root == NULL)
        return -1;

    struct node_st *cur = NULL;
    int ret             = 0;
    QUEUE *queue        = list_queue_create(sizeof(struct node_st *));
    if (queue == NULL)
        return -1;

    list_queue_enqueue(queue, &root);

    for (;;) {
        ret = list_queue_dequeue(queue, &cur);
        if (ret == -1)
            break;
        printf("出队元素: %d\n", cur->data.id);

        // 判断出队元素是否有左右孩子,有就又入队
        if (cur->left != NULL) {
            list_queue_enqueue(queue, &cur->left);
        }
        if (cur->right != NULL) {
            list_queue_enqueue(queue, &cur->right);
        }
    }

    list_queue_destroy(queue);

    return 0;
}
