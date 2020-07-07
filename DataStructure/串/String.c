//
//  String.c
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include "String.h"

int Index(String S, String T, int pos) {
    if (StringEmpty(S) || StringEmpty(T)) {
        return 0;
    }
    String sub;
    if (pos > 0) {
        int n = StrLength(S);
        int m = StrLength(T);
        int i = pos;
        while (i <= n-m+1) { // pos 从1 开始
            SubStrin(sub, S, i, m);
            if (StrCompare(sub, T) != 0) {
                ++i;
            } else {
                return i;
            }
            
        }
    }
    return 0;
    
}

int Indexs(String S, String T, int pos) {
    int i = pos; // i 用于主串 S 中当前位置下标, 若 pos 不为 1, 则从 pos 位置开始匹配
    int j = i; // j 用于子串 T 中当前位置下标值
    while (i <= S.data[0] && j <= T.data[0]) { //首位存储串长度
        if (S.data[i] == T.data[j]) {
            ++i; ++j;
        } else {
            i = i-j+2; // i 退回到上次匹配首位的下一位, 怎么计算????
            j = 1; // j 退回 T 首位
        }
    }
    if (j > T.data[0]) {
        return i-T.data[0]; // T.data[0] 为 T 串的长度
    } else {
        return 0;
    }
    
}


void get_next(String T, int *next) {
    int i = 1;
    int j = 0;
    next[1] = 0; // 串从 1 开始, next 也从 1 开始
    while (i < T.data[0]) { // T[0] 表示串长度
        if (j == 0 || T.data[i] == T.data[j]) { // T[i] 表示后缀的单个字符, T[j]表示前缀的单个字符
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];  // 若字符不相同, 则 j 值回溯
        }
    }
}

int Index_KMP(String S, String T, int pos) {
    int i = pos; // i 用于主串 S 中当前位置下标, 若 pos 不为 1, 则从 pos 位置开始匹配
    int j = i; // j 用于子串 T 中当前位置下标值
    int next[255];
    get_next(T, next);
//    get_nextval(T, next);
    while (i <= S.data[0] && j <= T.data[0]) { //首位存储串长度
        if (j == 0 || S.data[i] == T.data[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > T.data[0]) {
        return i-T.data[0]; // T.data[0] 为 T 串的长度
    } else {
        return 0;
    }
}

void get_nextval(String T, int *nextval) {
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if (T[i] != T[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }
}
