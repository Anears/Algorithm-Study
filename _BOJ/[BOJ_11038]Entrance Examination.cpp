//
//  [BOJ_11038]Entrance Examination.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 11..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int main()
{
    while(1){
        int m,nmin,nmax;
        scanf("%d%d%d",&m,&nmin,&nmax);
        if(m==0 && nmin==0 && nmax==0)
            break;
        
        int ans=0,val=0,x,px=0;
        for(int i=0;i<m;++i){
            scanf("%d",&x);
            if(i>=nmin && i<=nmax){
                if(val<=px-x){
                    val=px-x;
                    ans=i;
                }
            }
            px=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}
