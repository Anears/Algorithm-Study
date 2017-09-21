#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct tomato{
    int x,y;
};
int box[1001][1001];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

int main()
{
    int n,m,res=0;
    cin>>n>>m;
    queue<tomato> q;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>box[i][j];
            if(box[i][j]==1)
                q.push({i,j});
        }
    }
    
    while(!q.empty()){
        tomato now = q.front();
        q.pop();
        res=max(res,box[now.x][now.y]-1);
        for(int k=0;k<4;++k){
            tomato next = {now.x+dx[k],now.y+dy[k]};
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=m || box[next.x][next.y]!=0)
                continue;
            box[next.x][next.y] = box[now.x][now.y] + 1;
            q.push(next);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(box[i][j]==0){
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<res<<endl;
    
    return 0;
}
