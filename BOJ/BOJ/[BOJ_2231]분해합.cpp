#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int x=i,sum=i;
        while(x){
            sum+=x%10;
            x/=10;
        }
        if(sum==n){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
