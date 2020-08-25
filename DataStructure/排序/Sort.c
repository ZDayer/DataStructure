//
//  Sort.c
//  DataStructure
//
//  Created by 大洋 on 2020/8/3.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "Sort.h"
// 直接插入排序
// 希尔排序是直接插入排序的升级

// 选择排序
// 简单选择排序
// 堆排序

// 交换排序
// 冒泡排序
// 快速排序

void swap(SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}


// 冒泡排序
// 初级
void BubbleSort0(SqList *L) {
    for (int i = 1; i < L->length; i++) {
        for (int j = 1+1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                swap(L, i, j);
            }
        }
    }
}

// 从后向前比较, 小的数字逐渐向前移动到比它小的位置后面, 提高效率
void BubbleSort(SqList *L) {
    for (int i = 1; i < L->length; i++) {
        for (int j = L->length-1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                swap(L, j, j+1);
            }
        }
    }
}

// 优化, 增加标记, 减少比较次数
void BubbleSort2(SqList *L) {
    Status flag = TRUE;
    for (int i = 1; i < L->length && flag ; i++) {
        flag = FALSE; // 初始
        for (int j = L->length-1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                swap(L, j, j+1);
                flag = TRUE; // 有数据交换, 变为 TRUE
            }
        }
    }
}


/// ===============
// 简单选择排序
void SelectSort(SqList *L) {
    for (int i = 1; i < L->length; i++) {
        int min = i;  // 将当前下标定义为最小值下标
        for (int j = i+1; j < L->length; j++) {
            if (L->r[min] > L->r[j]) {
                min = j;
            }
        }
        if (i != min) {
            swap(L, i, min);
        }
    }
}

// 直接插入排序
void InsertSort(SqList *L) {
    for (int i = 2; i < L->length; i++) {
        if (L->r[i] < L->r[i-1]) {
            L->r[0] = L->r[i]; // 设置哨兵
            int j;
            for (j = i-1; L->r[j] > L->r[0]; j--) {
                L->r[j+1] = L->r[j]; // 记录后移
            }
            L->r[j+1] = L->r[0]; // 插入正确位置
            
        }
    }
}

void ShellSort(SqList *L) {
    int increment = L->length;
    do {
        increment = increment/3+1; //增量序列
        for (int i = increment+1; i<= L->length; i++) {
            if (L->r[i] < L->r[i-increment]) {
                 // 需将 L->r[i] 插入有序增量子表
                L->r[0] = L->r[i]; // 暂存在 L->r[0]
                int j;
                for (j = i-increment; j>0 && L->r[0] < L->r[j]; j-=increment) {
                    L->r[j+increment] = L->r[j]; // 记录后移, 查找插入位置
                }
                L->r[j+increment] = L->r[0]; // 插入
            }
        }
    } while (increment > 1);
}




// 堆排序  堆是完全二叉树  根: i, 左孩子: 2*i, 右孩子 2*i+1
// 已知 L->r[s..m] 中记录的关键字除 L->r[s] 之外均满足堆的定义
// 本函数调整 L->r[s] 的关键字, 使L-r[s..m] 成为一个大顶堆
void HeapAdjust(SqList *L, int s, int m) { // m 为顶点数最大下标
    int temp = L->r[s];
    for (int j = 2*s; j<=m; j*=2) {  // 根结点为 s, 左孩子为 2*s, 右孩子为 2*s+1
        if (j < m && L->r[j] < L->r[j+1]) { // 沿关键字较大的孩子结点向下筛选
            // 右孩子大于左孩子, 指向右孩子下标
            ++j;  // j 为关键字中较大的记录的下标
        }
        if (temp >= L->r[j]) {
            break;  //rc 应插入在位置 s上
        }
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; // 插入
}




void HeapSort(SqList *L) {
    // 将 L->r[] 构建成一个大顶堆
    for (int i = L->length/2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }
    
    
    for (int i = L->length; i>1 ; i--) {
        // 将堆顶记录和当前未经排序子序列的最后一个记录交换
        swap(L, 1, i);
        // 将 L->r[1..i-1] 重新调整为大顶堆
        HeapAdjust(L, 1, i-1);
    }
    
}




// 归并排序

// 递归方式, 占用内存, 效率高, 稳定的算法
// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n) {
    int j,k,l;
    for (j = m+1, k = i; i<=m && j<=n; k++) { // 将 SR 中记录由小到大归并到TR中
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    if (i<=m) {
        for (l = 0; l <= m-i; l++) {
            TR[k+1] = SR[i+1]; // 将剩余的 SR[i..m]复制到TR
        }
    }
    if (j <= n) {
        for (l=0; l<=n-j; l++) {
            TR[k+1] = SR[j+1]; // 将剩余的SR[j..n]复制到TR
        }
    }
}


// 将 SR[s..t] 归并排序为 TR1[s..t]
void MSort(int SR[], int TR1[], int s, int t) {
    int TR2[MAXSIZE+1];  // int r[MAXSIZE+1]
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        int m = (s+t)/2; // 将 SR[s..t] 平分为 SR[s..m] 和 SR[m+1..t]
        MSort(SR, TR2, s, m); // 递归将 SR[s..m]归并为有序的TR2[s..m]
        MSort(SR, TR2, m+1, t); // 递归将 SR[m+1..t]归并为有序的TR2[m+1..t]
        Merge(TR2, TR1, s, m, t); // 将 TR2[s..m] 和 TR2[m+1..t] 归并到 TR1[s...t]
    }
}


void MergeSort(SqList *L) {
    MSort(L->r, L->r, 1, L->length);
}


// 归并, 迭代方式

// 将 SR[] 中相邻长度为 s 的子序列两两归并到 TR[]
void MergePass(int SR[], int TR[], int s, int n) {
    int i = 1;
    int j;
    while (i <= n-2*s+1) {
        Merge(SR, TR, i, i+s-1, i+2*s-1); // 两两归并  //  1, 1, 2
        i= i+2*s; // 3                                // 3, 3, 4
    }
    if (i < n-s+1) { // 归并最后两个序列
        Merge(SR, TR, i, i+s-1, n);
    } else {
        // 最后只剩下单个子序列
        for (j = i; j <= n; j++) {
            TR[j] = SR[j];
        }
    }
}

void MergeSort2(SqList *L) {
    int *TR = (int *)malloc(L->length*sizeof(int)); // 申请空间
    int k = 1;
    while (k < L->length) {  //  1->2->4->8->16   归并每组个数
        MergePass(L->r, TR, k, L->length);// L->r TR 1 9
        k = 2*k;  // 子序列长度加倍
        MergePass(TR, L->r, k, L->length); // TR L->r 2 9
        k = 2*k;  // 子序列长度加倍
    }
}



// 快速排序

int Partition(SqList *L, int low, int high) {
    int pivotkey = L->r[low]; // 使用子表第一个记录做 枢轴记录
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        swap(L, low, high); // 将比枢轴记录小的记录交换到低端
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        swap(L, low, high); // 将比枢轴大的记录交换到高端
    }
    return low;
}


void QSort(SqList *L, int low, int high) {
    if (low < high) {
        int pivot = Partition(L, low, high); // 将 L->r[low..high] 一分为二, 算出枢轴值pivot
        QSort(L, low, pivot);
        QSort(L, pivot+1, high);
    }
}

void QuickSort(SqList *L) {
    QSort(L, 1, L->length);
}
