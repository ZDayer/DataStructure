//
//  Search.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/27.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Search.h"

// 数组从 1 开始, 返回 0 表示查找失败
int Sequential_Search(int *a, int n, int key) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

int Sequential_Search2(int *a, int n, int key) {
    int i = n;
    a[0] = key; // 哨兵也可以放在尾部
    while (a[i] != key) {
        i--;
    }
    return i; // 返回 0 查找失败
}

// 从 1 开始
int Binary_Search(int *a, int n, int key) {
    int low = 1;
    int high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key < a[mid]) {
            high = mid-1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}



// 插值 key-a[low] / a[high]-a[low]
// 分布较均匀的查找表适合用插值查找法
int Binary_Search2(int *a, int n, int key) {
    int low = 1;
    int high = n;
    while (low <= high) {
        int mid =  low + (high - low) * (key - a[low])/(a[high] - a[low]);
        if (key < a[mid]) {
            high = mid-1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

// 0    1   2   3   4   5   6   7   8
// 0    1   1   2   3   5   8   13  21
//int *F = [0, 1, 1 , 2, 3, 5, 8, 13, 21, 34];
// a 是有序数组
int Fibonacci_Search(int *a, int n, int key, int *F) {
    int low = 1;
    int hight = n;
    int k = 0;
    while (n > F[k]-1) {  // 计算 n 在 斐波那契数列中的位置
        k++;
    }
    for (int i = n; i < F[k]-1; i++) {
        a[i] = a[n];  // 补全数组, 都为最大值
    }
    while (low <= hight) {
        int mid = low + F[k-1]-1;
        if (key < a[mid]) {
            hight = mid-1;
            k = k-1; // 斐波那契数列下标减1 位
        } else if (key > a[mid]) {
            low = mid+1;
            k = k-2;
        } else {
            if (mid <= n) {
                return mid;  // 相等, 说明 mid即为查找到的位置
            } else {
                return n; // 若 mid > n, 说明是补全值, 返回n
            }
        }
    }
    
    return 0;
}



Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) { // 查找不成功
        *p = f;
        return FALSE;
    } else if (key == T->data) {
        *p = T;
        return TRUE;
    } else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);
    } else {
        return SearchBST(T->rchild, key, T, p);
    }
}

Status InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p)) { //
        
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p) {  // 空树
            *T = s; // 插入根结点
        } else if (key < p->data) {
            p->lchild = s;  // 查找方法中的 f 才有意义, 记录父结点
        } else {
            p->rchild = s;  // 查找方法中的 f 才有意义, 记录父结点
        }
        return TRUE;
    } else {
        return FALSE; // 树中已有
    }
}

void initTree() {
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;
    for (int i = 0; i < 10; i++) {
        InsertBST(&T, a[i]);
    }
}

// 删除结点
Status Delete(BiTree *p) {
    BiTree q, s;
    if ((*p)->rchild == NULL) { // 右子树为空, 只需重接左子树, 叶子结点也能处理
        q = *p; // 记录当前
        *p = (*p)->lchild;
        free(q);
    } else if ((*p)->lchild == NULL) { // 左子树为空, 只需重接右子树
        q = *p;
        *p = (*p)->rchild;
        free(q);
    } else { // 左右子树均不为空
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) { // 找到与删除结点接近的值, 根节点的值大于所有子结点, 左树小于右树, 找到子节点中最大的值, 找到删除结点的直接前驱
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data; // s 指向被删除结点的直接前驱
        if (q != *p) {
            q->rchild = s->lchild; // 重接 q 的右子树
        } else {
            q->lchild = s->lchild; // 重接 q 的左子树
        }
        free(s);
        
        
//        q = *p;
//        s = (*p)->rchild; // 后继结点
//        while (s->lchild) {
//            q = s;
//            s = s->lchild;
//        }
//        (*p)->data = s->data; // 直接后继
//        if (q != *p) {
//            q->lchild = s->rchild;
//        } else {
//            q->rchild = s->rchild;
//        }
//        free(s);
    }
    return TRUE;
}

Status DeleteBST(BiTree *T, int key) {
    if (!*T) {
        return FALSE;
    } else {
        if (key == (*T)->data) { // 找到
            return Delete(T);
        } else if (key < (*T)->data) {
            return DeleteBST(&(*T)->lchild, key);
        } else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

void R_Rotate(BBiTree *p) {
    BBiTree L;
    L = (*p)->lchild;
    (*p)->lchild = L->rchild; // p->data 大于所有左子树结点的值, L 变成根结点, p是 L 的第一个右结点, 需要处理 L 的右子树
    L->rchild = (*p);
    *p = L;
}

void L_Rotate(BBiTree *p) {
    BBiTree R;
    R = (*p)->rchild;
    (*p)->rchild = R->lchild; // p->data 小于所有右子树结点的值, R 变成根结点, p是 R 的第一个左结点, 需要处理 R 的左子树
    R->lchild = (*p);
    *p = R;  // p 指向新结点
}
