//
//  [BOJ_6118]숨바꼭질.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 19..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<int> adj[20100];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q; q.push(1);
    vector<int> dis(n+1,INF); dis[1]=0;
    int pos=1, far=0, cnt=1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(far<=dis[u]){
            if(far<dis[u]){
                far=dis[u];
                cnt=0;
                pos=u;
            }
            pos=pos>u?u:pos;
            cnt++;
        }
        for(int v: adj[u]){
            if(dis[v]==INF){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    printf("%d %d %d\n",pos,far,cnt);
    
    return 0;
}
