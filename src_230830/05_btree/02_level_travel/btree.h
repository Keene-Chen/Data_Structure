/**
 * @file    : btree.h
 * @author  : KeeneChen
 * @date    : 2023.09.12-18:45:46
 * @details : btree
 */

#ifndef __BTREE_H__
#define __BTREE_H__

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))
#endif

struct student {
    int id;
    char name[32];
    int age;
};

struct node_st {
    struct student data;
    struct node_st *left;
    struct node_st *right;
};

int btree_insert(struct node_st **root, struct student *data);
int btree_delete(struct node_st **root, int id);
int level_travel_list_queue(struct node_st *root);

#endif // __BTREE_H__