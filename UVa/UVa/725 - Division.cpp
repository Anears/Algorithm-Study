//
//  725-Division.cpp
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
    if(n==0) return 0;
    while(1){
        int cnt=0;
        for(int fghij = 1234; fghij <= 98765/n; ++fghij){
            int abcde = fghij * n;
            int tmp, used = (fghij < 10000);
            tmp = abcde; while(tmp) { used |= 1 << (tmp%10); tmp/=10;}
            tmp = fghij; while(tmp) { used |= 1 << (tmp%10); tmp/=10;}
            if(used == (1<<10)-1){
                printf("%.5d / %.5d = %d\n",abcde,fghij,n);
                cnt++;
            }
        }
        if(cnt==0) printf("There are no solutions for %d.\n",n);
        
        scanf("%d",&n);
        if(n==0) break;
        printf("\n");
    }
    
    return 0;
}
