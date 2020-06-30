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
// 默认从 1 开始

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef Node *LinkList;





//
//Status InitList(SqList *L);
//Status ListEmpty(SqList L);
//Status ClearList(SqList *L);
Status GetElem(LinkList L, int i, ElemType *e);
//Status LocateElem(SqList L, ElemType e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
//int ListLength(SqList L);
//void unionL(SqList *La, SqList Lb);




#endif /* LinkList_h */
