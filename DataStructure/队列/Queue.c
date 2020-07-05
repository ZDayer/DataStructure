//
//  Queue.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Queue.h"

Status InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}


int QueueLenght(SqQueue Q) {
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear+1)%MAXSIZE == Q->front) {  // 队列满
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) { // 空队列
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return OK;
}
