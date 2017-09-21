//
//  [BOJ_11066]파일_합치기.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 6..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

int file[501];
int dp[501][501];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;++i){
            scanf("%d",&file[i]);
            file[i]+=file[i-1];
        }
        for(int j=2;j<=k;++j){
            for(int i=j-1;i>0;--i){
                dp[i][j]=INF;
                for(int k=i;k<j;++k)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+file[j]-file[i-1]);
            }
        }
        printf("%d\n",dp[1][k]);
    }
    
    return 0;
}
