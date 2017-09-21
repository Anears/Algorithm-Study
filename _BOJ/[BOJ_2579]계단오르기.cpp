#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> sco(n+1),d(n+1);
    for(int i=1;i<=n;++i)
        cin>>sco[i];
    d[0]=0;
    d[1]=sco[1];
    d[2]=sco[1]+sco[2];
    
    for(int i=3;i<=n;++i)
        d[i]=max(d[i-3]+sco[i-1],d[i-2])+sco[i];
    cout<<d[n]<<endl;
    
    return 0;
}
