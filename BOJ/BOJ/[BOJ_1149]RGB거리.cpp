#include <iostream>
#include <vector>

using namespace std;

struct RGB{
    int r,g,b;
};

int main()
{
    int n;
    cin>>n;
    vector<RGB> cost(n);
    for(auto&x:cost)
        cin>>x.r>>x.g>>x.b;
    
    for(int i=1;i<n;++i){
        cost[i].r+=min(cost[i-1].g,cost[i-1].b);
        cost[i].g+=min(cost[i-1].b,cost[i-1].r);
        cost[i].b+=min(cost[i-1].r,cost[i-1].g);
    }
    cout<<min(cost[n-1].r,min(cost[n-1].g,cost[n-1].b))<<endl;
    
    return 0;
}
