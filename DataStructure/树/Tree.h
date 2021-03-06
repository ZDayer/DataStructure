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
#include <stdlib.h>
#include "define.h"
/*
 InitTree(*T)  构造空树
 DestroyTree(*T) 销毁树
 CreateTree(*T, definition) 按照definition中给出树的定义构造树
 ClearTree(*T) 若c树存在, 清空为空树, 结点为 0
 TreeEmpty(T) 空树true, 否则false
 TreeDepth(T) 返回T的深度
 Root(T) 返回根结点
 Value(T,cur_e) cur_e是树的一个结点, 返回此结点的值
 Assign(T,cur_e,value) 给树T的结点cur_e赋值为value
 Parent(T,cur_e) 若cur_e是树T的非根结点, 返回它的双亲
 LeftChild(T, cur_e) 若cur_e是树T的非叶子结点, 返回它的左孩子
 RightChild(T,cur_e) 若cur_e是树T的非叶子结点, 返回它的右孩子
 InsertChild(*T, *p, i, c) 其中p指树T的某个结点, i为所指结点p的度加1, 非空树c与T不相交, 操作结果为插入c为树T中p结点的第ik棵子树
 DeleteChile(*T, *p, i)  其中p指树T的某个结点, i为所指结点p的度, 操作结果为删除T中pz结点的第i棵子树
 */


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



// 二叉树 链表表示, 优化: 可以添加一个指向双亲的指针
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// 二叉树遍历

// 前序遍历算法  根 -> 左 -> 右
void PreOrderTraverse(BiTree T);

// 中序遍历算法 左 -> 根 -> 右
void InOrderTraverse(BiTree T);

// 后序遍历算法 左 -> 右 -> 根
void PostOrderTraverse(BiTree T);


// 二叉树生成
// 前序生成, # 表示空结点
void CreateBiTree(BiTree *T);




// 线索二叉树
typedef enum {Link, Thread} PointerTag;  // Link == 0, 左右孩子, Thread == 1, 前驱后继
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BIThrTree;

// 中序遍历线索化
void InThreading(BIThrTree p);


// 增加头结点的线索二叉树
// T指向头结点, 头结点的 lchild 指向根结点, rchild 指向中序遍历的最后一个结点,
Status InOrderTraverse_Thr(BIThrTree T);
#endif /* Tree_h */
