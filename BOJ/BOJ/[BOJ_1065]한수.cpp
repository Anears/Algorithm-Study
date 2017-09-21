#include <iostream>

using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int x=i;
        if(x/100==0) cnt++;
        else{
            int an,d;
            an=x/10%10;
            d=an-x%10;
            x/=100;
            while(x){
                if(x%10-an != d)
                    break;
                an=x%10;x/=10;
            }
            if(!x)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
