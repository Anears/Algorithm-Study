#include <iostream>

using namespace std;

int main()
{
    long long d[91]={0,1,1},n;
    cin>>n;
    for(int i=3;i<=n;++i)
        d[i]=d[i-2]+d[i-1];
    cout<<d[n]<<endl;
    
    return 0;
}
