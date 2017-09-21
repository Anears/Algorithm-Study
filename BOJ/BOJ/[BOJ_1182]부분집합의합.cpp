#include <iostream>

using namespace std;

int t[20];
int n,s;

int bf(int pos,int sum){
    if(pos==-1) return s==sum?1:0;
    else return bf(pos-1,sum+t[pos])+bf(pos-1,sum);
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<n;++i)
        cin>>t[i];
    cout<<bf(n-1,0)-(s==0?1:0)<<endl;
    return 0;
}
