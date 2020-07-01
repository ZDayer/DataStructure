//
//  List.h
//  List
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include "define.h"
// 默认线性表从 1 开始

#define MAXSIZE 20

typedef struct {
    ElemType data[MAXSIZE];
    int length;
}SqList;


Status InitList(SqList *L);
Status ListEmpty(SqList L);
Status ClearList(SqList *L);
Status GetElem(SqList L, int i, ElemType *e);
Status LocateElem(SqList L, ElemType e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
int ListLength(SqList L);
void unionL(SqList *La, SqList Lb);
#endif /* List_h */
