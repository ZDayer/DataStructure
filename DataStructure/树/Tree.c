//
//  Tree.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/7.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Tree.h"

// 递归的方法
void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}


void InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}


void CreateBiTree(BiTree *T) {
    TElemType ch;
    scanf("%d", &ch);
    if (ch == "#") { // TElemType 类型为 intg
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) {
            exit(OVERFLOW)
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}


BIThrTree pre;// 全局变量, 始终指向刚刚访问过的结点 ??
void InThreading(BIThrTree p) { // 只是改变值, 没有结点的改变,
    if (!p) {
        return;
    }
    // 中序遍历, 左->根->右
    InThreading(p->lchild);
    if (!p->lchild) {
        p->LTag = Thread;
        p->lchild = pre; // 指向前驱, pre 上次访问过的结点
    }
    if (!pre->rchild) {
        pre->RTag = Thread;
        pre->rchild = p;
    }
    pre = p;
    InThreading(p->rchild);
}

Status InOrderTraverse_Thr(BIThrTree T) {
    BIThrTree p = T->lchild; // p 指向根结点
    while (p != T) { // p == T 时表示空树或遍历结束
        while (p->LTag == Link) { // 中序遍历, 找到第一个结点
            p = p->lchild;
        }
        printf("%c", p->data); // 第一个结点的值

        while (p->RTag == Thread && p->rchild != T) {// 有右孩子不会进入, 指向后续结点
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}
