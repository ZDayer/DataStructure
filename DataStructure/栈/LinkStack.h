//
//  LinkStack.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

// 头指针指向栈顶, 无头结点

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

typedef int SELemType; // 假设为 int

typedef struct StackNode {
    SELemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;

Status Push(LinkStack *S, SELemType e);

Status Pop(LinkStack *S, SELemType *e);

Status StackEmpty(LinkStack S);
#endif /* LinkStack_h */
