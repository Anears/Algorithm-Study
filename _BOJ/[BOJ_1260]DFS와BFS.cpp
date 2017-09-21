#include <iostream>
#include <queue>

using namespace std;

bool adj[1001][1001],vis[1001];

void DFS(int x){
    if(vis[x]) return;
    vis[x]=true;
    cout<<x<<" ";
    for(int i=1;i<=1000;++i){
        if(adj[x][i])
            DFS(i);
    }
}

void BFS(int x){
    queue<int> q;
    q.push(x);
    vis[x]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        cout<<now<<" ";
        for(int i=1;i<=1000;++i){
            if(adj[now][i] && !vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n,m,v,a,b;
    cin>>n>>m>>v;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        adj[a][b]=adj[b][a]=true;
    }
    
    DFS(v);
    cout<<endl;
    for(int i=1;i<=n;++i)
        vis[i]=false;
    
    BFS(v);
    
    return 0;
}
