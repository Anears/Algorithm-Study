#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >t(n);
    vector<int>r(n,1);
    for(auto&x:t)
        cin>>x.first>>x.second;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(t[i].first>t[j].first && t[i].second>t[j].second) r[j]++;
            else if(t[i].first<t[j].first && t[i].second<t[j].second) r[i]++;
        }
    }
    for(auto&x:r)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
