//
//  [BOJ_1753]최단경로.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 17..
//  Copyright © 2017년 KGT. All rights reserved.
//


//SPFA
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii;
vector<ii> adj[20010];

int main()
{
    int v,e,k;
    scanf("%d%d",&v,&e);
    scanf("%d",&k); k--;
    while(e--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u-1].push_back(ii(v-1,w));
    }
    
    vector<int> dis(v,INF); dis[k]=0;
    queue<int> q; q.push(k);
    vector<bool> inq(v,false); inq[k]=true;
    while(!q.empty()){
        int u=q.front(); q.pop(); inq[u]=false;
        for(ii next: adj[u]){
            int v=next.first,w=next.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    
    for(int d: dis){
        if(d==INF) printf("INF\n");
        else printf("%d\n",d);
    }
    return 0;
}
