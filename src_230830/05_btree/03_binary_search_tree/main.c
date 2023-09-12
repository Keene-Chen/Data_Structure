/**
 * @file    : main.c
 * @author  : KeeneChen
 * @date    : 2023.09.12-21:58:08
 * @details : main
 */

// #include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_SIZE 256
#define KEY_SIZE  256
#define BUF_SIZE  512
#define FILENAME  "animal.log"

struct node_st {
    struct node_st *ch[26];
    char desc[DESC_SIZE];
};

static int get_word(FILE *fp, char *key, char *desc)
{
    char buf[BUF_SIZE];
    char *ptr = NULL;
    int i, j;

    ptr = fgets(buf, BUF_SIZE, fp);
    if (ptr == NULL)
        return -1;

    for (i = 0; i < KEY_SIZE - 1 && buf[i] != ':'; i++)
        key[i] = buf[i];
    key[i] = '\0';

    i++;

    for (j = 0; j < DESC_SIZE - 1 && buf[i] != '\0'; j++, i++)
        desc[j] = buf[i];
    desc[j] = '\0';

    return 0;
}

int insert(struct node_st **root, char *key, char *desc)
{
    struct node_st *node;

    if (*root == NULL) {
        node = malloc(sizeof(*node));
        if (node == NULL)
            return -1;
        node->desc[0] = '\0';
        for (int i = 0; i < 26; i++) {
            node->ch[i] = NULL;
        }
        *root = node;
    }
    if (*key == '\0') {
        strcpy((*root)->desc, desc);
        return 0;
    }

    return insert((*root)->ch + *key - 'a', key + 1, desc);
}

char *find(struct node_st *root, char *key)
{
    if (root == NULL)
        return NULL;
    if (*key == '\0')
        return root->desc;
    return find(root->ch[*key - 'a'], key + 1);
}

int main(void)
{
    char desc[DESC_SIZE] = { '\0' }, key[KEY_SIZE] = { '\0' };
    struct node_st *tree = NULL;
    char *tmp            = NULL;
    int ret              = 0;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("failed to open file\n");
        return -1;
    }

    while (1) {
        ret = get_word(fp, key, desc);
        if (ret == -1)
            break;
        // puts(key);
        // puts(desc);
        insert(&tree, key, desc);
    }

    tmp = find(tree, "ant");
    if (tmp == NULL)
        printf("canot find %s\n", "ant");
    else
        printf("%s\n", tmp);

    fclose(fp);

    return 0;
}