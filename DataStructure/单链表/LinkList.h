//
//  LinkList.h
//  List
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
// 默认从 1 开始


typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef Node *LinkList;





void CreateListHead(LinkList *L, int n); // 随机产生 n个随机数, 建立带头结点的单线性表(头插法)
//Status InitList(SqList *L);
//Status ListEmpty(SqList L);
Status ClearList(LinkList *L);
Status GetElem(LinkList L, int i, ElemType *e);
//Status LocateElem(SqList L, ElemType e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
//int ListLength(SqList L);
//void unionL(SqList *La, SqList Lb);




#endif /* LinkList_h */

/* 循环链表
 将单链表中终端结点的指针端由空指针改为指向头结点, 就使整个单链表形成一个环, 这种头尾相接的单链表称为单循环链表 circular linked list
 为了方便处理, 使空链表和非空链表处理一致, 通常会设置一个头结点, 头指针指向头结点, 头结点的指针指向自己
 
 用尾结点更加方便
 
 */
