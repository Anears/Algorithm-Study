#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> per(n);
    for(int i=1;i<=n;++i)
        per[i-1]=i;
    do{
        for(int&x:per)
            printf("%d ",x);
        printf("\n");
    }while(next_permutation(per.begin(), per.end()));
    
    return 0;
}
