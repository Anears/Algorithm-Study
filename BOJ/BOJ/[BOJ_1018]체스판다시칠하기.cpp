#include <iostream>
#include <algorithm>

using namespace std;

char pan[50][50];

int cnt(int x,int y,char ch){
    int c=0;
    for(int i=x;i<x+8;++i){
        for(int j=y;j<y+8;++j){
            if((i+j)%2==0 && pan[i][j]==ch)
                c++;
            else if((i+j)%2!=0 && pan[i][j]!=ch)
                c++;
        }
    }
    return c;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>pan[i];
    
    int res=987654321;
    for(int i=0;i<=n-8;++i){
        for(int j=0;j<=m-8;++j){
            res=min(res,min(cnt(i,j,'W'),cnt(i,j,'B')));
        }
    }
    cout<<res<<endl;
    return 0;
}
