//
//  [BOJ_2150]Strongly_Connected_Component.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 14..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#define UNVISITED -1

using namespace std;

vector<int> dfs_num,dfs_low,s,vis;
vector<int> adj[10010],scc[10010];
int dfsNumberCounter,numSCC;

void tarjanSCC(int u){
    dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
    s.push_back(u);
    vis[u]=1;
    for(int v:adj[u]){
        if(dfs_num[v]==UNVISITED)
            tarjanSCC(v);
        if(vis[v])
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){
        while(1){
            int v=s.back();
            s.pop_back();
            vis[v]=0;
            scc[numSCC].push_back(v+1);
            if(u==v) break;
        }
        numSCC++;
    }
}

int main()
{
    int v,e;
    scanf("%d%d",&v,&e);
    while(e--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u-1].push_back(v-1);
    }
    
    dfs_num.assign(v, UNVISITED);
    dfs_low.assign(v, 0);
    vis.assign(v, 0);
    dfsNumberCounter=numSCC=0;
    
    for(int i=0;i<v;++i){
        if(dfs_num[i]==UNVISITED)
            tarjanSCC(i);
    }
    
    for(int i=0;i<numSCC;++i)
        sort(scc[i].begin(),scc[i].end());
    sort(scc,scc+numSCC);
    
    printf("%d\n",numSCC);
    for(int i=0;i<numSCC;++i){
        for(int v:scc[i])
            printf("%d ",v);
        printf("-1\n");
    }
    
    return 0;
}
