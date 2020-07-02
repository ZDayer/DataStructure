//
//  StaticLinkList.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/1.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "StaticLinkList.h"

Status InitList(StaticLinkList space) {
    for (int i = 0; i < MAXSIZE-1; i++) { // 数组从 0 开始
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    return OK;
}

int Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) { // 不为 0, 说明有链表不为空
        space[0].cur = space[i].cur;
        // space[0].cur 是第一个备用链表的下标
        // space[i].cur 是他指向的备用链表的下标
        // i 这个位置需要分配出去, 所以需要改变 space[0].cur
        // 不是 i-1 是因为第一个特殊, 不存储数据, 指向第一个备用链表
    }
    return i;
}

void Free_SSL(StaticLinkList space, int i) {
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int k = MAXSIZE-1; // k 是最后一个元素的下标
    if (i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }
    int j = Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (int l = 1; l < i-1; l++) { // 不能理解
            // 最后一个元素的下标指向第一个有数据的下标
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}


Status ListDelete(StaticLinkList L, int i) {
    if (i < 1 || i > ListLength(L)) {
        return ERROR;
    }
    int k = MAXSIZE-1;
    for (int j = 1; j < i-1; j++) {
        k = L[k].cur;
    }
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}


int ListLength(StaticLinkList L) {
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    if (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}
