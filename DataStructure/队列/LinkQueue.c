//
//  LinkQueue.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "LinkQueue.h"
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) { // 分配失败
        return ERROR;
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

// 有头结点
Status DeQueue(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) { // 空栈
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front; // Q->front 是不变的
    }
    free(p);
    return OK;
}
