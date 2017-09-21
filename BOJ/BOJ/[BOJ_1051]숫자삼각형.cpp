#include <iostream>
#include <algorithm>

using namespace std;

char t[50][50];

int main()
{
    int n,m,res=1;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>t[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int k=1;;++k){
                if(i+k>=n || j+k>=m)break;
                if(t[i][j]==t[i][j+k] &&
                   t[i][j+k]==t[i+k][j+k] &&
                   t[i+k][j+k]==t[i+k][j])
                    res=max(res,(k+1)*(k+1));
            }
        }
    }
    cout<<res<<endl;
    
    return 0;
}
