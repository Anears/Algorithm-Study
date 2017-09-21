//
//  [BOJ_5427]불.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 18..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <queue>
#define UNVIS 1000000000

using namespace std;
typedef pair<int,int> ii;

char building[1010][1010];
int ff[1010][1010], pp[1010][1010];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int w,h;
        scanf("%d%d",&w,&h);
        
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                ff[i][j]=pp[i][j]=UNVIS;
            }
        }
        
        queue<ii> fire,pos;
        for(int i=0;i<h;++i){
            scanf("%s",building[i]);
            for(int j=0;j<w;++j){
                if(building[i][j]=='@'){
                    pos.push(ii(i,j));
                    pp[i][j]=0;
                }
                else if(building[i][j]=='*'){
                    fire.push(ii(i,j));
                    ff[i][j]=0;
                }
            }
        }
        
        while(!fire.empty()){
            ii now = fire.front(); fire.pop();
            for(int k=0;k<4;++k){
                ii next(now.first+dx[k],now.second+dy[k]);
                if(next.first<0 || next.first>=h || next.second<0 || next.second>=w) continue;
                char ch=building[next.first][next.second];
                if(ch!='#' && ff[next.first][next.second]==UNVIS){
                    ff[next.first][next.second]=ff[now.first][now.second]+1;
                    fire.push(next);
                }
            }
        }
        
        bool find=false;
        while(!pos.empty()){
            ii now = pos.front(); pos.pop();
            for(int k=0;k<4;++k){
                ii next(now.first+dx[k],now.second+dy[k]);
                if(next.first<0 || next.first>=h || next.second<0 || next.second>=w){
                    printf("%d\n",pp[now.first][now.second]+1);
                    find=true;
                    break;
                }
                char ch=building[next.first][next.second];
                if(ch!='#' && pp[next.first][next.second]==UNVIS && pp[now.first][now.second]+1<ff[next.first][next.second]){
                    pp[next.first][next.second]=pp[now.first][now.second]+1;
                    pos.push(next);
                }
            }
            if(find) break;
        }
        if(!find) printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
