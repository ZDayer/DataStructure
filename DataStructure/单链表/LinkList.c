//
//  LinkList.c
//  List
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "LinkList.h"

Status GetElem(LinkList L, int i, ElemType *e) { // L 是头指针
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e) {
    LinkList p = *L;
    LinkList s;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e) {
    LinkList p = *L;
    LinkList q;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = p->data;
    free(q);
    return OK;
}

// 随机产生 n个随机数, 建立带头结点的单线性表(头插法)
//void CreateListHead(LinkList *L, int n) {
//    LinkList p;
//    srand(time(0)); // 初始化随机数种子
//    *L = (LinkList)malloc(sizeof(Node));
////    *L = (struct Node *)malloc(sizeof(Node));
//    (*L)->next = NULL; // 头结点
//    for (int i = 0; i < n; i++) {
//        p = (LinkList)malloc(sizeof(Node));
//        p->data = rand()%100+1;
//        p->next = (*L)->next;
//        (*L)->next = p;
//    }
//}

// 尾插法
void CreateListHead(LinkList *L, int n) {
    LinkList p, r;
    time_t t = 0;
    srand(time(t));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}


Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
