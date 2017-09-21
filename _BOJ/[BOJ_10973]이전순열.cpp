#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> per(n);
    for(int&x:per)
        cin>>x;
    if(prev_permutation(per.begin(), per.end())){
        for(int&x:per)
            cout<<x<<" ";
        cout<<endl;
    }
    else cout<<"-1"<<endl;
    
    
    return 0;
}
