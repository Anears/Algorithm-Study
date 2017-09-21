//
//  [BOJ_11266]단절점.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 21..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#define UNVIS -1

using namespace std;
typedef vector<int> vi;

int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num,dfs_low,dfs_parent,articulation_vertex;
vi adj[10100];

void articulationPointAndBridge(int u){
    dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
    for(int v: adj[u]){
        if(dfs_num[v]==UNVIS){
            dfs_parent[v]=u;
            if(u==dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            
            if(dfs_low[v]>=dfs_num[u])
                articulation_vertex[u]=true;
            //if(dfs_low[v]>dfs_num[u])
            //    printf("Edge(%d, %d)is a bridge\n",u,v);
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=dfs_parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}

int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfsNumberCounter=0; dfs_num.assign(n, UNVIS); dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0); articulation_vertex.assign(n, 0);
    
    for(int i=0;i<n;++i){
        if(dfs_num[i]==UNVIS){
            dfsRoot=i; rootChildren=0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot]=(rootChildren>1);
        }
    }
    
    vi ans;
    for(int i=0;i<n;++i){
        if(articulation_vertex[i])
            ans.push_back(i+1);
    }
    printf("%d\n",(int)ans.size());
    for(int v:ans)
        printf("%d ",v);
    
    
    return 0;
}
