//
//  [BOJ_9023]연습시즌.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 21..
//  Copyright © 2017년 KGT. All rights reserved.
//
/*
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[110][110];
int x[110],y[110];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int c,D,dd,xc,yc;
        scanf("%d%d%d",&c,&D,&dd);
        xc=yc=0;
        while(1){
            scanf("%d",&x[xc]);
            if(x[xc++]==0) break;
        }
        while(1){
            scanf("%d",&y[yc]);
            if(x[yc++]==0) break;
        }
        for(int i=1;i<=xc;++i){
            for(int j=1;j<=yc;++j){
                dp[i][j]=0;
                int k;
                
                dp[i][j]=dp[i-1][j-1]+(x[i]==y[j]?c:2*c);
                dp[i][j]=min(dp[i][j],);
            }
        }
    }
    
    return 0;
}*/

#include <cstdio>
int t[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%1d",&t[i][j]);
    
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(t[i][j]==1){
                cnt++;
                for(int k=0;k<=i;++k){
                    for(int l=0;l<=j;++l)
                        t[k][l]=1-t[k][l];
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
