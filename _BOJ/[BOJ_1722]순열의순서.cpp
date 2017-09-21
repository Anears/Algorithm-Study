#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main()
{
    ll n,k,p=1;
    scanf("%lld",&n);
    scanf("%lld",&k);
    vector<bool>chk(n,false);
    for(int i=2;i<=n;++i)p*=i;
    if(k==1){
        scanf("%lld",&k);k--;
        for(int i=n;i>0;--i){
            p/=i;
            ll c=k/p;
            for(int j=0;j<n;++j){
                if(chk[j] || c--) continue;
                printf("%d ",j+1);
                chk[j]=true;
                break;
            }
            k%=p;
        }
    }
    else{
        ll res=0;
        for(int i=n;i>0;--i){
            p/=i;
            scanf("%lld",&k);
            chk[--k]=true;
            int cnt=0;
            for(int j=0;j<k;++j){
                if(!chk[j])
                    cnt++;
            }
            res+=p*cnt;
        }
        printf("%lld\n",res+1);
    }
    return 0;
}
