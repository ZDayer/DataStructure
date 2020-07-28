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
