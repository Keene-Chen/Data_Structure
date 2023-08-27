/**
 * @file    : digraph.c
 * @author  : KeeneChen
 * @date    : 2022.09.03-16:29:01
 * @details : digraph
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 50
typedef char vertex_info[9];

// 定义图的结构体
typedef struct graph_s {
    vertex_info vertex[MAX_VERTEX];   // 顶点数组 - 存储顶点的名字
    int edge[MAX_VERTEX][MAX_VERTEX]; // 边的数组
    int vertex_num;                   // 顶点的个数
    int edge_num;                     // 边的条数
} graph_t;

// 求用户输入的顶点在顶点数组中的位置
int get_vertex_position(graph_t *g, vertex_info v)
{
    for (int i = 0; i < g->vertex_num; i++) {
        if (strcmp(v, g->vertex[i]) == 0)
            return i;
    }
    return -1;
}

// 创建图
void graph_create(graph_t *g)
{
    printf("请输入图的顶点数和边数: 顶点 边\n");
    scanf("%d %d", &g->vertex_num, &g->edge_num);
    printf("请输入%d个顶点的值\n", g->vertex_num);
    for (int i = 0; i < g->vertex_num; i++) {
        scanf("%s", g->vertex[i]);
    }

    // 初始化,默认没有边
    for (int i = 0; i < g->vertex_num; ++i) {
        for (int j = 0; j < g->vertex_num; ++j) {
            g->edge[i][j] = INT_MAX;
        }
    }

    // <B,A>
    printf("请输入%d条边, 弧尾 弧头 权重\n", g->edge_num);
    int w;
    vertex_info v1, v2;
    for (int i = 0; i < g->edge_num; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        int m         = get_vertex_position(g, v1);
        int n         = get_vertex_position(g, v2);
        g->edge[m][n] = w;
    }
}

// 打印图 -
void graph_print(graph_t *g)
{
    // 水平表头
    printf("\t");
    for (int i = 0; i < g->vertex_num; ++i) {
        printf("%d\t", g->vertex[i]);
    }
    for (int i = 0; i < g->vertex_num; ++i) {
        printf("\n");
        // 垂直的
        printf("%d\t", g->vertex[i]);
        for (int j = 0; j < g->vertex_num; ++j) {
            if (g->edge[i][j] == INT_MAX) {
                printf("∞\t");
            }
            else {
                printf("%d\t", g->edge[i][j]);
            }
        }
    }
    printf("\n");
}

int main(void)
{
    graph_t g;
    graph_create(&g);
    graph_print(&g);

    return 0;
}