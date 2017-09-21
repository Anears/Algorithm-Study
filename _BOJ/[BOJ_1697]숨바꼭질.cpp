#include <iostream>
#include <queue>
#define MAXPOS 100000

using namespace std;

int vis[MAXPOS+1];

int main()
{
    int n,k;
    cin>>n>>k;
    
    queue<int>pos;
    pos.push(n);
    vis[n]=1;
    
    while(!pos.empty()){
        int now=pos.front();pos.pop();
        if(now == k)
            break;
        if(now-1>=0 && vis[now-1]==0) { pos.push(now-1);vis[now-1]=vis[now]+1; }
        if(now+1<=MAXPOS && vis[now+1]==0) { pos.push(now+1);vis[now+1]=vis[now]+1; }
        if(now*2<=MAXPOS && vis[now*2]==0) { pos.push(now*2);vis[now*2]=vis[now]+1; }
    }
    
    cout<<vis[k]-1;
    return 0;
}
