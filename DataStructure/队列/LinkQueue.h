//
//  LinkQueue.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>
#include <stdlib.h>
#include "define.h"
typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status EnQueue(LinkQueue *Q, QElemType e);

Status DeQueue(LinkQueue *Q, QElemType *e);

#endif /* LinkQueue_h */
