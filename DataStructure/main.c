//
//  main.c
//  DataStructure
//
//  Created by 大洋 on 2020/6/30.
//  Copyright © 2020 Dayer. All rights reserved.
//

#include <stdio.h>
// 学习 大话数据结构/程杰

void Fbi(int i);
int Fbis(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//    Fbi(40);
    for (int i = 0; i < 40; i++) {
        printf("%d ", Fbis(i));
    }
    
    
    return 0;
}

void Fbi(int n) {
    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("%d %d ", a[0], a[1]);
    for (int i = 2; i < 40; i++) {
        a[i] = a[i-1]+a[i-2];
        printf("%d ", a[i]);
    }
}

int Fbis(int n) {
    if (n < 2) {
        return n == 0 ?: 1;
    }
    return Fbis(n-1)+Fbis(n-2);
}
