//
//  DoubleStack.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef DoubleStack_h
#define DoubleStack_h

// 共享空间的两个栈, 仅做了解

#include <stdio.h>
#include "define.h"

#define MAXSIZE 20

typedef int SELemType; // 假设为 int

typedef struct {
    SELemType data[MAXSIZE];
    int top1; // 栈 1 栈顶指针
    int top2; // 栈 2 栈顶指针
}SqDoubleStack;


//    [ top1 ->      <-top2 ]


// 栈满 top1 + 1 = top2

// stackNumber 标识是栈 1 还是栈 2
Status Push(SqDoubleStack *S, SELemType e, int stackNumber);
Status Pop(SqDoubleStack *S, SELemType *e, int stackNumber);

#endif /* DoubleStack_h */
