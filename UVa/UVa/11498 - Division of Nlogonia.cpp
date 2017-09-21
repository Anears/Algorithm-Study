//
//  11498 - Division of Nlogonia.cpp
//  UVa
//
//  Created by minji on 2017. 8. 24..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int main()
{
    int k;
    while(scanf("%d",&k), k){
        int n,m,a,b;
        scanf("%d%d",&n,&m);
        while(k--){
            scanf("%d%d",&a,&b);
            if(n==a || m==b)
                printf("divisa\n");
            else{
                if(m<b) printf("N");
                else printf("S");
                if(n<a) printf("E\n");
                else printf("O\n");
            }
        }
    }
    
    return 0;
}
