//
//  [BOJ_10258]스위치_배열.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 6..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <cmath>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int res = 0;
        char bit[31];
        scanf("%s",bit);
        int len = int(strlen(bit));
        
        char next = '0';
        for(int i=0;i<len;++i){
            if(bit[i] != next){
                res += pow(2,len-1-i);
                next = '1';
            }
            else
                next = '0';
        }
        printf("%d\n",res);
    }
    
    return 0;
}
