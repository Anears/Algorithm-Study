//
//  11727 - Cost Cutting.cpp
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
    int tc,pc=1;
    scanf("%d",&tc);
    while(tc--){
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        printf("Case %d: %d\n",pc++,a[1]);
    }
    
    return 0;
}
