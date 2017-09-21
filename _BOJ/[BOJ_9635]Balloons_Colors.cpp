//
//  [BOJ_9635]Balloons_Colors.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,y,k;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%d",&k);
        bool es=(k==x);
        while(--n) scanf("%d",&k);
        bool ha=(k==y);
        if(es&&ha) printf("BOTH\n");
        else if(es) printf("EASY\n");
        else if(ha) printf("HARD\n");
        else printf("OKAY\n");
    }
    
    return 0;
}
