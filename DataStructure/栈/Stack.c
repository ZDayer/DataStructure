//
//  Stack.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Stack.h"

Status Push(SqStack *S, SELemType e) {
    if (S->top == MAXSIZE-1) { // 栈满
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e) {
    if (S->top == -1) { // 空栈
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
