//
//  Graph.c
//  DataStructure
//
//  Created by zhaoyang on 2020/7/14.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Graph.h"

// 邻接矩阵
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


void CreateALGraph(GraphAdjList *G) {
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%s", &G->adjList[i].data); // 输入顶点信息
        G->adjList[i].firstedge = NULL;
    }
    for (int k = 0; k < G->numEdges; k++) {
        int i, j;
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j; // 邻接点为 j
        
        // 头插法
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        
        // 无向表
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}
