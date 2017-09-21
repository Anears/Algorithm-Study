#include <iostream>
#include <algorithm>

using namespace std;

bool bro[10];

bool chk(int k){
    if(k==0 && bro[k%10])return false;
    while(k){
        if(bro[k%10]) return false;
        k/=10;
    }
    return true;
}

int len(int k){
    if(k==0) return 1;
    int cnt=0;
    while(k){
        cnt++;
        k/=10;
    }
    return cnt;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        bro[x]=true;
    }
    int res=abs(n-100);
    for(int i=0;i<=1000000;++i){
        if(chk(i)) res=min(res,len(i)+abs(n-i));
    }
    cout<<res<<endl;
    
    return 0;
}
