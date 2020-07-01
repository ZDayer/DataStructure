//
//  StaticLinkList.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/1.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef StaticLinkList_h
#define StaticLinkList_h

#include <stdio.h>
#include "define.h"
// 用数组代替指针, 描述单链表
// 每个下标对应两个数据域, data存储数据, cur相当于next, 叫游标
// 数组的第一个和最后一个元素做特殊处理, 不存数据
// 未被使用的数组元素称为备用链表
// 数组的第一元素, 下标为 0 的元素的 cur存放备用链表的第一个结点下标
//数组的的最后一个元素的 cur存放第一个有数据的元素下标, 相当于头结点

#define MAXSIZE 1000
typedef struct {
    ElemType data;
    int cur;// 游标, 为 0 时表示无指向
} Component, StaticLinkList[MAXSIZE];  // 对于不提供结构体的程序语言, 可以使用一对并行数组 data, cur 处理

// space[0].cur 为头指针, "0"表示空指针
Status InitList(StaticLinkList space);

// 若备用链表非空, 返回分配的结点下标, 否则返回 0
int Malloc_SLL(StaticLinkList space);
void Free_SSL(StaticLinkList space, int i);


Status ListInsert(StaticLinkList L, int i, ElemType e);

int ListLength(StaticLinkList L);

#endif /* StaticLinkList_h */
