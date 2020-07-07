//
//  Tree.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/7.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>


// 双亲表示法
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode {
    TElemType data; // 结点数据
    int parent;     // 双亲位置
}PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int r, n; // 根的位置, 结点数
}PTree;
// 根结点没有双亲, 位置域设置为 -1
/*
 扩充, 双亲表示法可以很快找到双亲和祖先结点, 找孩子结点需要遍历
 
 1. 增加一个 长子域, 没有孩子结点设置为 -1
 
 2. 增加一个 右兄弟域, 没有右兄弟设置为 -1
 
 ...

 */

// 孩子结点表示法
// 每个结点的孩子结点, 以单链表存储, 叶子结点链表为空
// n个结点就有 n 个孩子链表
// n 个头指针组成线下表, 采用顺序存储结构, 存放进一个一维数组中

// 孩子结点
typedef struct CTNode {
    int child;
    struct CTNode *next;
}*ChilePtr;

// 表头结构
typedef struct {
    TElemType data;
    ChilePtr firstchild;
}CTBox;

// 树结构
typedef struct {
    CTBox node[MAX_TREE_SIZE]; // 结点数组
    int r, n; // 根的位置, 结点数
}CTree;

// 优化, 可以找到双亲结点, 找双亲结点不需要遍历整个表,
// 表头结构 添加双亲节点位置
typedef struct {
    TElemType data;
    int parent;
    ChilePtr firstchild;
}PCBox;


// 孩子兄弟表示法, 可以将复杂的树变成二叉树
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstchild, *rightsib;
}CSNode, *CSTree;

// 优化, 添加父节点指针域
typedef struct PCSNode{
    TElemType data;
    struct PCSNode *parent, *firstchild, *rightsib;
}PCSNode, *PCSTree;
#endif /* Tree_h */
