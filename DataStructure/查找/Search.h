//
//  Search.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/27.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Search_h
#define Search_h

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// 静态查找表
// 查询某个特定的数据元素是否在查找表中
// 查询某个特定的数据元素和各种属性

// 动态查找表
// 查找时插入数据元素
// 查找时删除数据元素

// 顺序查找 for 循环
// 优化: 设立哨兵, 无序判断越界情况
int Sequential_Search(int *a, int n, int key);
int Sequential_Search2(int *a, int n, int key);


// 有序表查找
// 二分查找
int Binary_Search(int *a, int n, int key);

// 插值查找
int Binary_Search2(int *a, int n, int key);

//  斐波那契查找
int Fibonacci_Search(int *a, int n, int key, int F[100]);




// 二叉排序树
// 若左子树不空, 则左子树上所有的结点的值均小于它根结点的值
// 若右子树不空, 则右子树上所有的结点的值均大于它根结点的值
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// 二叉树查找
// 递归查找二叉排序树 T 中是否存在 key
// 指针 f 指向 T 的双亲, 初始值为 NULL
// 若查找成功, 则指针 p 指向该数据元素结点, 并返回 TRUE
// 否则指针 p 指向查找路径上访问的最后一个结点并返回 FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p);

// 插入
Status InsertBST(BiTree *T, int key);

// 删除
// 存在关键字 key, 则删除该数据元素结点
Status DeleteBST(BiTree *T, int key);


// 平衡二叉树
typedef struct BBiTNode {
    int data;
    int bf;  // 平衡因子
    struct BBiTNode *lchild, *rchild;
}BBiTNode, *BBiTree;

// 右旋操作
// 对以 p 为根的二叉排序树做右旋处理
// 处理后 p 指向新的树根结点, 即旋转处理之前的左子树的根结点
void R_Rotate(BBiTree *p);

// 左旋操作
// 对以 p 为根的二叉排序树做左旋处理
// 处理后 p 指向新的树根结点, 即旋转处理之前的右子树的根结点
void L_Rotate(BBiTree *p);


#endif /* Search_h */

