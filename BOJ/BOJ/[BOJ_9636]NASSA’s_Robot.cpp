//
//  [BOJ_9636]NASSA’s_Robot.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <cstring>

char str[100100];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len=(int)strlen(str);
        int u,r,d,l,q;
        u=r=d=l=q=0;
        for(int i=0;i<len;++i){
            if(str[i]=='U') u++;
            else if(str[i]=='R') r++;
            else if(str[i]=='D') d++;
            else if(str[i]=='L') l++;
            else q++;
        }
        int x=r-l, y=u-d;
        printf("%d %d %d %d\n",x-q,y-q,x+q,y+q);
    }
    
    return 0;
}
