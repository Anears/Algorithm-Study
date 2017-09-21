#include <iostream>

using namespace std;
bool adj[100][100];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cin>>adj[i][j];
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                adj[i][j] |= (adj[i][k] && adj[k][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
