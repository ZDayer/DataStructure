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

// 邻接链表
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
        
        // 无向表, 需要同步添加
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}


typedef int Boolean;
Boolean visited[MAXVEX];
// 递归
void DFS(MGraph G, int i) {
    visited[i] = TRUE;
    printf("%c", G.vexs[i]); // 打印顶点, 也可执行其他操作
    for (int j = 0; j < G.numVertexes; j++) {  // <vi,vj> j 是邻接顶点在顶点表中的下标
        if (G.arc[i][j] == 1 && !visited[j]) {
            DFS(G, j);
        }
    }
}
// 深度遍历
void DFSTraverse(MGraph G) {
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE; // 初始化
    }
    for (int j = 0; j < G.numVertexes; j++) {
        if (!visited[j]) {
            DFS(G, j);
        }
    }
}


        
void DFSLink(GraphAdjList GL, int i) {
    visited[i] = TRUE;
    EdgeNode *p = GL.adjList[i].firstedge; // 指向头一个顶点
    while (p) {
        if (!visited[p->adjvex]) {   // p->adjvex 邻接点域, 存储该顶点对应的下标
            DFSLink(GL, p->adjvex);
        }
        p = p->next;
    }
}

void DFSLinkTraverse(GraphAdjList GL) {
    for (int i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    for (int j = 0; j < GL.numVertexes; j++) {
        DFSLink(GL, j);
    }
    
}



void BFSTraverse(MGraph G) {
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }
    SqQueue q;
    InitQueue(&q);  // 存储顶点在顶点表中的下标
    for (int j = 0; j < G.numVertexes; j++) {
        if (!visited[j]) {
            visited[j] = TRUE;
            printf("%c", G.vexs[j]); //打印顶点, 也可执行其他操作
            EnQueue(&q, j);  // 进队列
            while (!QueueLenght(q)) { // 队列有值
                DeQueue(&q, &j); // 出队列, 赋值给 j , 循环后 j值会变成原来
                for (int k = 0; k < G.numVertexes; k++) {
                    if (G.arc[j][k] == 1 && !visited[k]) {
                        visited[k] = TRUE;
                        printf("%c", G.vexs[k]); //打印顶点, 也可执行其他操作
                        EnQueue(&q, k); // 入队列
                    }
                }
            }  
        }
    }
}


void BFSTraverses(GraphAdjList GL) {
    for (int i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    SqQueue q;
    InitQueue(&q);  // 存储顶点在顶点表中的下标
    for (int j = 0; j < GL.numVertexes; j++) {
        if (!visited[j]) {
            visited[j] = TRUE;
            printf("%c", GL.adjList[j].data); //打印顶点, 也可执行其他操作
            EnQueue(&q, j);  // 进队列
            while (!QueueLenght(q)) { // 队列有值
                DeQueue(&q, &j); // 出队列, 赋值给 j , 循环后 j值会变成原来
                EdgeNode *p = GL.adjList[j].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;
                        printf("%c", GL.adjList[p->adjvex].data); //打印顶点, 也可执行其他操作
                        EnQueue(&q, j); // 入队列

                    }
                    p = p->next;
                }
            }
        }
    }
}

