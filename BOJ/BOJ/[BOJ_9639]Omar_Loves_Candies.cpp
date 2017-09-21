//
//  [BOJ_9639]Omar_Loves_Candies.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#define INF 2000000100

int can[1100][1100];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&can[i][j]);
                can[i][j]+=can[i-1][j]+can[i][j-1]-can[i-1][j-1];
            }
        }
        int ans=-INF;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int v=can[n][m]-can[i-1][m]-can[n][j-1]+can[i-1][j-1];
                ans=ans<v?v:ans;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
