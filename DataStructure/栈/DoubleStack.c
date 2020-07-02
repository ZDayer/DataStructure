//
//  DoubleStack.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "DoubleStack.h"

Status Push(SqDoubleStack *S, SELemType e, int stackNumber) {
    if (S->top1 +1 == S->top2) { // 栈满
        return ERROR;
    }
    if (stackNumber == 1) {
        S->top1++;
        S->data[S->top1] = e;
    } else if (stackNumber == 2) {
        S->top2--;
        S->data[S->top2] = e;
    }
    return OK;
}

Status Pop(SqDoubleStack *S, SELemType *e, int stackNumber) {
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return ERROR;
        }
        *e = S->data[S->top1];
        S->top1--;
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2];
        S->top2++;
    }
    return OK;
}
