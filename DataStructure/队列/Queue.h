//
//  Queue.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "define.h"
/*
 InitQueue(*Q)
 DestroyQueue(*Q)
 ClearQueue(*Q)
 QueueEmpty(Q)
 GetHead(Q, *e)
 EnQueue(*Q, e) 插入
 DeQueue(*Q, *e) 删除
 QueueLength(Q)
 */

// 顺序存储队列
// 使用数组存储, 与线性表一致, 但只能在头删除, 在尾插入


// 循环队列
#define MAXSIZE 20
typedef int QElemType;
typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *Q);

int QueueLenght(SqQueue Q);

Status EnQueue(SqQueue *Q, QElemType e);

Status DeQueue(SqQueue *Q, QElemType *e);

#endif /* Queue_h */
