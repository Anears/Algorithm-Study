//
//  [BOJ_11801]Feast_Coins.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 13..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int v[50],c[50];

int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int s,n;
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",&v[i],&c[i]);
        
        ll ans=0;
        for(int k=1;k<=5000;++k){
            if(s%k!=0) continue;
            vector<ll> dp(s/k+1,0);
            dp[0]=1;
            for(int i=0;i<n;++i){
                if(c[i]<k) continue;
                for(int j=s/k;j>=v[i];j--)
                    dp[j]+=dp[j-v[i]];
            }
            ans+=dp[s/k];
        }
        
        printf("Case %d: %lld\n",tc++,ans);
    }
    return 0;
}
