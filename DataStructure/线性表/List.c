//
//  List.c
//  List
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "List.h"

// 将 Lb 中不在 La 的元素放入 La
void unionL(SqList *La, SqList Lb) {
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);
    ElemType e;
    for (int i = 1; i < Lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e)) {
            ListInsert(La, La_len++, e);
        }
    }
}


Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i-1]; // 数组下标从 0 开始, 线性表从 1开始
    return OK;
}


Status ListInsert(SqList *L, int i, ElemType e) {
    if (L->length == MAXSIZE) {
        return ERROR; // 可实现扩容操作
    }
    if (i < 1 || i > L->length+1) { // +1 是可以插入到最后面, 线性表是连续的
        return ERROR;
    }
    if (i <= L->length) { // 不在表尾
        for (int k = L->length-1; k > i-1; k--) { // 移动数组, 注意下标最大为 L->length-1
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}


Status ListDelete(SqList *L, int i, ElemType *e) {
    if (L->length == 0) {
        return ERROR;
    }
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    *e = L->data[i-1];
    if (i < L->length) {
        for (int k = i-1; k < L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}

int ListLength(SqList L) {
    return L.length;
}
