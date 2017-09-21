#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool chk[4][1001];

int main()
{
    vector<int>ori;
    set<int>tri;
    for(int i=1;i*(i+1)/2<=1000;++i)
        ori.push_back(i*(i+1)/2);
    
    for(int&i:ori){
        for(int&j:ori){
            for(int&k:ori)
                tri.insert(i+j+k);
        }
    }
    
    int tc;
    cin>>tc;
    while(tc--){
        int k;
        cin>>k;
        cout<<(tri.find(k)!=tri.end()?1:0)<<endl;
    }
    return 0;
}
