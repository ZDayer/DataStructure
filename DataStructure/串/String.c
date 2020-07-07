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
