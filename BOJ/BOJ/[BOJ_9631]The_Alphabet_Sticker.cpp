//
//  [BOJ_9631]The_Alphabet_Sticker.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#define mod 1000000007

char str[10100];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long ans=1;
        
        scanf("%s",str);
        int len=(int)strlen(str);
        int cnt=0;
        char pre=' ';
        for(int i=0;i<len;++i){
            if(str[i]=='?') cnt++;
            else {
                if(cnt>0){
                    if(pre!=' ' && pre!=str[i])
                        ans=(ans*(cnt+1))%mod;
                    cnt=0;
                }
                pre=str[i];
            }
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}
