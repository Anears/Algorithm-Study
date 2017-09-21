#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> d(11);
    d[0]=d[1]=1;
    d[2]=2;
    for(int i=3;i<=10;++i)
        d[i]=d[i-3]+d[i-2]+d[i-1];
    
    int tc,n;
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<d[n]<<endl;
    }
    
    return 0;
}
