//
//  Graph.c
//  DataStructure
//
//  Created by zhaoyang on 2020/7/14.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Graph.h"


void CreateGraph(MGraph *G) {
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes, &G->numEdges); // 输入顶点数和边数
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%c",&G->vexs[i]);
    }
    for (int i = 0; i < G->numVertexes; i++) {
        for (int j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY; // 初始化
        }
    }
    for (int k = 0; k < G->numEdges; k++) {
        printf("输入边(vi, Vj)上的下标 i,下标j 和权值 w:\n");
        int i, j, w;
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];  // 无向图, 矩阵对称
    }
}
