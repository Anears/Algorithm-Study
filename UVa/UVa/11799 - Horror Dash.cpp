//
//  11799 - Horror Dash.cpp
//  UVa
//
//  Created by minji on 2017. 8. 24..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int tc,c=1;
    scanf("%d",&tc);
    while(tc--){
        int n,ans=0,val;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&val);
            ans=max(ans,val);
        }
        printf("Case %d: %d\n",c++,ans);
    }
    
    return 0;
}
