//
//  LinkStack.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "LinkStack.h"

Status Push(LinkStack *S, SELemType e) {
    // 不需要判断栈满的情况
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SELemType *e) {
    if (StackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    LinkStackPtr p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}


Status StackEmpty(LinkStack S) {
    if (S.count) {
        return TRUE;
    }
    return FALSE;
}
