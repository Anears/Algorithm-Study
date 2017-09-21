#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ms=1000000;
    vector<int> d(ms+1,987654321);
    d[1]=0;
    for(int i=1;i<=ms;++i){
        if(i*2<=ms) d[i*2]=min(d[i]+1,d[i*2]);
        if(i*3<=ms) d[i*3]=min(d[i]+1,d[i*3]);
        if(i+1<=ms) d[i+1]=min(d[i]+1,d[i+1]);
    }
    
    int n;
    cin>>n;
    cout<<d[n]<<endl;
    return 0;
}
