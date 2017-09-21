#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

char maze[100][100];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int cnt[100][100];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>maze[i];
        for(int j=0;j<m;++j)
            cnt[i][j]=987654321;
    }
    
    queue<pii>pos;
    pos.push(make_pair(0,0));
    cnt[0][0]=1;
    
    while(!pos.empty()){
        pii now = pos.front();
        pos.pop();
        if(now.first == n-1 && now.second == m-1) break;
        for(int k=0;k<4;++k){
            pii next(now.first+dx[k],now.second+dy[k]);
            if(next.first<0 || next.first>=n || next.second<0 || next.second>=m) continue;
            if(maze[next.first][next.second]=='0' || cnt[next.first][next.second] <= cnt[now.first][now.second]+1) continue;
            cnt[next.first][next.second] = cnt[now.first][now.second]+1;
            pos.push(next);
        }
    }
    cout<<cnt[n-1][m-1]<<endl;
    
    return 0;
}
