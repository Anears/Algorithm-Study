#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int r,c,res;
char board[20][20];
bool vis[26];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

void alp(int i,int j,int l){
    if(i<0 || i>=r || j<0 || j>=c || vis[board[i][j]-'A'])
        return;
    vis[board[i][j]-'A'] = true;
    for(int k=0;k<4;++k){
        alp(i+dx[k],j+dy[k],l+1);
    }
    vis[board[i][j]-'A'] = false;
    res=max(res,l);
}

int main()
{
    cin>>r>>c;
    for(int i=0;i<r;++i)
        cin>>board[i];
    alp(0,0,1);
    cout<<res<<endl;
    
    return 0;
}


///왜 틀렸습니다??
/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int r,c;
char board[20][20];
bool vis[26];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

int alp(int i,int j){
    if(i<0 || i>=r || j<0 || j>=c || vis[board[i][j]-'A'])
        return 0;
    vis[board[i][j]-'A'] = true;
    int maxAlp=0;
    for(int k=0;k<4;++k)
        maxAlp = max(maxAlp,alp(i+dx[k],j+dy[k]));
    vis[board[i][j]-'A'] = false;
    return maxAlp+1;
}

int main()
{
    cin>>r>>c;
    for(int i=0;i<r;++i)
        cin>>board[i];
    cout<<alp(0,0)<<endl;
    
    return 0;
}*/
