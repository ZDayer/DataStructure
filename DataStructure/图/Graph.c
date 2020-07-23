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



void MiniSpanTree_Prim(MGraph G) {
    int adjvex[MAXVEX]; // 保存相关顶点下标
    int lowcost[MAXVEX]; // 保存相关顶点间权值
    lowcost[0] = 0; // 初始化第一个权值, 即v0加入生成树
    adjvex[0] = 0; // 初始化第一个顶点
    for (int i = 1; i < G.numVertexes; i++){ // 除下标为 0 的全部顶点
        lowcost[i] = G.arc[0][i]; // 将 v0顶点与之有边的权值存入数组
        adjvex[i] = 0; // 初始化都为 vo 的下标
    }
    
    for (int i = 1; i < G.numVertexes; i++) {
        int min = INFINITY; // 初始化最小权值为比较大的值
        int j = 1, k = 0;
        
        // 第一次 获得与 v0 相连的边的最小权值,并记录
        while (j < G.numVertexes) { // 循环全部顶点
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j]; // 让当前权值为最小值
                k = j;            // 最小值下标存入 k
            }
            j++;
        }
        
        
        printf("(%d,%d)", adjvex[k], k); // 打印当前顶点边中权值最小边 // 第一次打印, adjvex[k] == 0, 表明是从 v0 开始遍历, 找到 v0连接的边, k 记录最小权值的下标, 与 v0相连
        lowcost[k] = 0; // 将当前顶点权值设为 0, 表示此顶点已经完成任务
        for (int j = 1; j < G.numVertexes; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                // 若下标为k的顶点各边权值小于此前这些顶点未被加入生成树权值
                lowcost[j] = G.arc[k][j]; // 将较小权值存入 lowcost
                adjvex[j] = k; // 将下标为k的顶点存入 adjvex
            }
        }
    }
}

int Find(int *parent, int f) {  // 查找连线顶点的尾部下标
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}


// 9个顶点, 15 条边
void MiniSpanTree_Kruskal(MGraph G) {
    Edge edges[15]; // 边集数组
    int parent[9]; // 记录顶点, 判断是否形成了回路
    // 省略了将邻接矩阵转化为边集数组 edges并按权值由小到大排列  // Page252
    for (int i = 0; i < G.numVertexes; i++) {
        parent[i] = 0; // 初始化数组
    }
    for (int i = 0; i < G.numEdges; i++) { // 循环每一条边
        int n = Find(parent, edges[i].begin);
        int m = Find(parent, edges[i].end);
        if (n != m) { // 不相等, 表示此边没有与现有生成树形成回路
            parent[n] = m; // 将此边的结尾顶点放入下标为起点的 parent 中, 表示此顶点已经在生成树集合中
            printf("(%d, %d) %d", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}



