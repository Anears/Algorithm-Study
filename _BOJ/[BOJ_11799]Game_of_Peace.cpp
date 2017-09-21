//
//  [BOJ_11799]Game_of_Peace.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 11..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

typedef long long ll;
ll gcd(ll x,ll y){
    for(ll z=x%y;z;x=y,y=z,z=x%y);
    return y;
}

int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int x,n,y,m;
        scanf("%d%d%d%d",&x,&n,&y,&m);
        ll le=x,ri=0;
        while(n--){
            ri+=le;
            le^=ri^=le^=ri;
        }
        printf("Case %d: %lld\n",tc++,gcd(ri,le+y));
    }
    return 0;
}
