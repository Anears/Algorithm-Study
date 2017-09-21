#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        deque<pair<int,int> >pri;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            pri.push_back(make_pair(x,i==m?1:0));
        }
        int cnt=1;
        while(1){
            bool chk=true;
            pair<int,int> now = pri.front();
            pri.pop_front();
            for(int i=0;i<pri.size();++i){
                if(pri[i].first>now.first){
                    pri.push_back(now);
                    chk=false;
                    break;
                }
            }
            if(!chk) continue;
            if(now.second) break;
            cnt++;
        }
        cout<<cnt<<endl;
        
    }
    
    return 0;
}
