//
//  String.h
//  DataStructure
//
//  Created by 大洋 on 2020/7/5.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdio.h>
#include "define.h"

/*
 串中的元素仅由一个字符组成, 相邻元素具有前驱和后继关系
 
 StrAssign(T, *chars): 生成一个其值等于字符串常量chars 的串 T
 StrCopy(T, S)
 ClearString(S)
 StringEmpty(S)
 StrLength(S)
 StrCompare(S,T) 对比大小 小: -1, 等于: 0, 大于: 1
 Concat(T, S1, S2) 用 T 返回由 S1和 S2 联接而成的新串
<<<<<<< HEAD
 SubStrin(Sub,S,pos,len)  position 从1 开始
=======
 SubStrin(Sub,S,pos,len)  position 从 1 开始的
>>>>>>> 45aedb8cab9aa7587bd256e2ac6ffe2a18ff96b5
 Index(S,T,pos) 串 S和 T 存在, T 是非空串, 1<= pos <= StrLength(S), 若主串 S 中存在和串 T 值相同的子串, 则返回它在主串 S 中第 pos 个字符之后第一次出现的位置, 否则返回 0
 Replace(S,T,V) 串 S, T 和 V 存在, T 是非空串, 用 V 替换主串 S 中出现的所有与 T 相等的不重复子串
 StrInsert(S,pos,T)
 StrDelete(S,pos,len)
 */

#define MAXSIZE 100
typedef char SElemType;
typedef struct {
    SElemType data[MAXSIZE];
}String;

Status StringEmpty(String S);
int StrLength(String S);
Status SubStrin(String Sub, String S, int pos, int len);
int StrCompare(String S, String T);
// T 为非空串, 若主串S中第pos个字符之后存在与T相等的子串, 则返回第一个这样的子串在S中的位置, 否则返回0
int Index(String S, String T, int pos);

// 朴素的模式匹配算法, pos 从 1 开始, 1 <= pos <= StrLenght(S)
int Indexs(String S, String T, int pos);


// KMP 模式
// 获取 next 数组
void get_next(String T, int *next);

int Index_KMP(String S, String T, int pos);
#endif /* String_h */
