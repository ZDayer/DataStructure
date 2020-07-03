//
//  Stack.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/2.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

/*
 InitStack(*S)   创建空栈
 DestoryStack(*S) 若栈存在, 则销毁它
 ClearStack(*S) 清空栈
 StackEmpty(S)  空栈返回 true, 否则 false
 GetTop(S, *e) 返回栈顶非空元素
 Push(*S, *e) 入栈
 Pop(*S, *e) 出栈
 StackLength(S) 栈内元素个数
 */



#include <stdio.h>
#include "define.h"
#define MAXSIZE 20
typedef int SELemType; // 假设为 int

typedef struct {
    SELemType data[MAXSIZE];
    int top;
}SqStack;

Status Push(SqStack *S, SELemType e);

Status Pop(SqStack *S, ElemType *e); 


#endif /* Stack_h */
