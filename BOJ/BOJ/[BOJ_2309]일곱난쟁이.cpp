#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int hei[9], s=0;
    for(auto&x:hei){
        cin>>x;
        s+=x;
    }
    sort(hei,hei+9);
    for(int i=0;i<9;++i)
        for(int j=i+1;j<9;++j){
            if(s-(hei[i]+hei[j])==100){
                for(int k=0;k<9;++k){
                    if(k!=i && k!=j)
                        cout<<hei[k]<<endl;
                }
                return 0;
            }
        }
    
    return 0;
}
