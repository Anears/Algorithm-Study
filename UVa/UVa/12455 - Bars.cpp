//
//  12455 - Bars.cpp
//  UVa
//
//  Created by minji on 2017. 7. 12..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int bar[20];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p;
        scanf("%d",&n);
        scanf("%d",&p);
        for(int i=0;i<p;++i)
            scanf("%d",&bar[i]);
        
        bool pos=false;
        for(int x=0;x<(1<<p);++x){
            int sum=0;
            for(int i=0;i<p;++i)
                sum+=(x&(1<<i)?bar[i]:0);
            if(sum==n){pos=true;break;}
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
