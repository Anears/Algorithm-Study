//
//  11559 - Event Planning.cpp
//  UVa
//
//  Created by minji on 2017. 8. 24..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <cstdio>

int main()
{
    //freopen("/Users/minji/Desktop/Algorithm/Algorithm-Study/UVa/UVa/input.txt","r",stdin);
    int n,b,h,w;
    while(scanf("%d",&n)){
        scanf("%d%d%d",&b,&h,&w);
        int ans = b+1;
        while(h--){
            int pri,bed;
            scanf("%d",&pri);
            for(int i=0;i<w;++i){
                scanf("%d",&bed);
                if(ans>pri && bed>=n)
                    ans = pri;
            }
        }
        if(ans*n>b) printf("stay home\n");
        else printf("%d\n",ans*n);
    }
    
    return 0;
}
