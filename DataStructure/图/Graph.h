//
//  Graph.h
//  DataStructure
//
//  Created by zhaoyang on 2020/7/14.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>

// 邻接矩阵
typedef char VertexType;    // 顶点类型, 自定义
typedef int EdgeType;       // 权值类型, 自定义
#define MAXVEX 100
#define INFINITY 65535      // 65535是计算机16位二进制最大数, 代替极限值

typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵, 也可以看做边表
    int numVertexes, numEdges; // 顶点数, 边树数
}MGraph;


// 构造图, 就是向顶点表和边表填入数据的过程

// 无向网图
void CreateGraph(MGraph *G);
#endif /* Graph_h */
