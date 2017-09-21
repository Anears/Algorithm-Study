//
//  [BOJ_5719]거의_최단_경로.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 18..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;
typedef pair<int,int> ii;

vector<ii> adj[510];
vector<int> tra[510];
int n,m,s,d;
bool eraE[510][510];

void Erasing(int v){
    if(v==s) return;
    for(int u: tra[v]){
        eraE[u][v]=true;
        Erasing(u);
    }
}

int SFPA(){
    vector<int> dis(n,INF); dis[s]=0;
    queue<int> q; q.push(s);
    vector<bool> inq(n,false); inq[s]=true;
    while(!q.empty()){
        int u=q.front(); q.pop(); inq[u]=false;
        for(ii next: adj[u]){
            int v=next.first, w=next.second;
            if(!eraE[u][v] && dis[v]>=dis[u]+w){
                if(dis[v]>dis[u]+w) tra[v].clear();
                dis[v]=dis[u]+w;
                tra[v].push_back(u);
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return dis[d]==INF?-1:dis[d];
}

int main()
{
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        scanf("%d%d",&s,&d);
        for(int i=0;i<n;++i){
            adj[i].clear();
            tra[i].clear();
            for(int j=0;j<n;++j)
                eraE[i][j]=false;
        }
        while(m--){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            adj[u].push_back(ii(v,p));
        }
        
        SFPA();
        Erasing(d);
        printf("%d\n",SFPA());
    }
    
    return 0;
}
