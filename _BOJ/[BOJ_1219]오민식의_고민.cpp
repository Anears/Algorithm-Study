//
//  [BOJ_1219]오민식의_고민.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 19..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 4000000000000000000

using namespace std;
typedef long long ll;
typedef pair<int,ll> ii;

vector<ii> adj[110];
bool com[110][110];
ll mon[110];

int main()
{
    int n,s,t,m;
    scanf("%d%d%d%d",&n,&s,&t,&m);
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(v,w));
        com[u][v]=true;
    }
    for(int i=0;i<n;++i)
        scanf("%lld",&mon[i]);
    
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                com[i][j]|=(com[i][k]&&com[k][j]);
        }
    }
    
    vector<ll> dis(n,INF); dis[s]=-mon[s];
    queue<int> q; q.push(s);
    vector<bool> inq(n,false); inq[s]=true;
    vector<int> vis(n,0);
    bool gee=false;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=false;
        for(ii next: adj[u]){
            int v=next.first; ll w=next.second;
            if(dis[v]>dis[u]+w-mon[v]){
                dis[v]=dis[u]+w-mon[v];
                if(!inq[v]){
                    vis[v]++;
                    if(vis[v]>=n){
                        if(com[v][t]){
                            gee=true;
                            break;
                        }
                    }
                    else{
                        q.push(v);
                        inq[v]=true;
                    }
                }
            }
        }
        if(gee) break;
    }
    if(dis[t]==INF)printf("gg");
    else if(gee) printf("Gee");
    else printf("%lld",-dis[t]);
    
    return 0;
}
