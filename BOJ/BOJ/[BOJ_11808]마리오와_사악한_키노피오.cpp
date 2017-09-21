//
//  [BOJ_11808]마리오와_사악한_키노피오.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 13..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;

ll dis[1010][1010];
bool vis[1010];
int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        ll ans=0;
        int n,k;
        scanf("%d%d",&n,&k);
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j)
                dis[i][j]=INF;
            dis[i][i]=0;
            vis[i]=false;
        }
        for(int i=2;i<=n;++i){
            int p,c;
            scanf("%d%d",&p,&c);
            dis[i][p]=dis[p][i]=c;
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        int pos=1;
        while(k--){
            ll val=INF;
            for(int i=2;i<=n;++i){
                if(vis[i]) continue;
                if()
            }
            ans+=val;
            vis[]
        }
        printf("Case %d: %d\n",tc++,ans);
    }
    
    return 0;
}
