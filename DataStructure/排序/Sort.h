//
//  Sort.h
//  DataStructure
//
//  Created by 大洋 on 2020/8/3.
//  Copyright © 2020 Dayer. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "define.h"

// 排序用的顺序结构
#define MAXSIZE 10
typedef struct {
    int r[MAXSIZE+1]; // 用于存储要排序数组, r[0] 用于哨兵或临时变量
    int length; // 用于记录顺序表的长度
}SqList;

void swap(SqList *L, int i, int j);




#endif /* Sort_h */
