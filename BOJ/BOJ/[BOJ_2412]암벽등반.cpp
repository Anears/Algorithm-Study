//
//  [BOJ_2412]암벽등반.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#define UNVIS -1

using namespace std;
typedef pair<int, int> ii;

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    vector<ii> home;
    home.push_back(ii(0,0));
    
    for(int i=0;i<n;++i){
        ii p;
        scanf("%d%d",&p.first,&p.second);
        home.push_back(p);
    }
    sort(home.begin(),home.end());
    
    queue<int> q; q.push(0);
    vector<int> dis(n+1,UNVIS); dis[0]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(home[u].second==t){
            printf("%d",dis[u]);
            return 0;
        }
        
        int st=int(lower_bound(home.begin(), home.end(), ii(home[u].first-2,home[u].second-2))-home.begin());
        int en=int(upper_bound(home.begin(), home.end(), ii(home[u].first+2,home[u].second+2))-home.begin());
        for(int v=st;v<en;++v){
            if(dis[v]!=UNVIS) continue;
            if(abs(home[u].second-home[v].second)<=2){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    printf("-1");
    return 0;
}
