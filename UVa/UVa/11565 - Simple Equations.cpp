//
//  11565-SimpleEquations.cpp
//  UVa
//
//  Created by minji on 2017. 7. 12..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,c;
        bool sol=false;
        scanf("%d%d%d",&a,&b,&c);
        for(int x=-100;!sol && x<=100;++x){
            for(int y=-100;!sol && y<=100;++y){
                int z=a-x-y;
                if(x==y || y==z || z==x) continue;
                if(x+y+z!=a || x*y*z!=b || x*x+y*y+z*z!=c) continue;
                printf("%d %d %d\n",x,y,z);
                sol=true;
            }
        }
        if(!sol) printf("No solution.\n");
    }
    
    return 0;
}
