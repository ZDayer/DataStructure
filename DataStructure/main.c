//
//  main.c
//  DataStructure
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
// 学习 大话数据结构/程杰

void Fbi(int i);
int Fbis(int n);

typedef char VertexType;    // 顶点类型, 自定义
typedef int EdgeType;       // 权值类型, 自定义
#define MAXVEX 100
#define INFINITY 65535      // 65535是计算机16位二进制最大数, 代替极限值

typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[9][9]; // 邻接矩阵, 也可以看做边表
    int numVertexes, numEdges; // 顶点数, 边数
}MGraph;

void MiniSpanTree_Prim(MGraph G);

void CreateGraph(MGraph *G);
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//    Fbi(40);
//    for (int i = 0; i < 40; i++) {
//        printf("%d ", Fbis(i));
//    }
    
    MGraph *G = malloc(sizeof(MGraph));
//    CreateGraph(G);
    G->numVertexes = 9;
    printf("%d", G->numVertexes);
    int arc[9][9] = {
        {0, 10, 100, 100, 100, 11, 100, 100, 100},
        {10, 0, 18, 100, 100, 100, 16, 100, 12},
        {100, 100, 0, 22, 100, 100, 100, 100, 8},
        {100, 100, 22, 0, 20, 100, 100, 16, 21},
        {100, 100, 100, 20, 0, 26, 100, 7, 100},
        {11, 100, 100, 100, 26, 0, 17, 100, 100},
        {100, 16, 100, 100, 100, 17, 0, 19, 100},
        {100, 100, 100, 16, 7, 100, 19, 0, 100},
        {100, 12, 8, 21, 100, 100, 100, 100, 0}
    };
    
    for (int i = 0; i< 9; i++) {
        for (int j = 0; j < 9; j++) {
            G->arc[i][j] = arc[i][j];
        }
    }
    
    
    MiniSpanTree_Prim(*G);
    
    return 0;
}

void Fbi(int n) {
    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("%d %d ", a[0], a[1]);
    for (int i = 2; i < 40; i++) {
        a[i] = a[i-1]+a[i-2];
        printf("%d ", a[i]);
    }
}

int Fbis(int n) {
    if (n < 2) {
        return n == 0 ?: 1;
    }
    return Fbis(n-1)+Fbis(n-2);
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
    for (int i = 0; i < 9; i++) {
        printf("lowcost %d  ", lowcost[i]);
        printf("adjvex %d", adjvex[i]);
        printf("\n");
    }

}

// 邻接矩阵
void CreateGraph(MGraph *G) {
    printf("输入顶点数和边数:\n");
    scanf("%d%d",&G->numVertexes, &G->numEdges); // 输入顶点数和边数
    for (int i = 0; i < G->numVertexes; i++) {
//        scanf("%c",&G->vexs[i]);
        G->vexs[i] = i;
    }
    for (int i = 0; i < G->numVertexes; i++) {
        for (int j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY; // 初始化
        }
    }
    for (int k = 0; k < G->numEdges; k++) {
        printf("输入边(vi, Vj)上的下标 i,下标j 和权值 w:\n");
        int i, j, w;
        scanf("%d%d%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];  // 无向图, 矩阵对称
    }
}
