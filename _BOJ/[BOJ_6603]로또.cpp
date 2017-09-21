#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s,r(6);

void bf(int sl,int rl,int k){
    if(sl>k || 6-rl>k-sl) return;
    if(rl==6){
        for(int&x:r)
            cout<<x<<" ";
        cout<<endl;
    }
    else{
        r[rl]=s[sl];
        bf(sl+1,rl+1,k);
        bf(sl+1,rl,k);
    }
}

int main()
{
    while(1){
        int k;
        cin>>k;
        if(k==0) break;
        s=vector<int>(k);
        for(int&x:s)
            cin>>x;
        sort(s.begin(),s.end());
        bf(0,0,k);
        cout<<endl;
    }
    
    return 0;
}
