//
//  11172 - Relational Operator.cpp
//  UVa
//
//  Created by minji on 2017. 8. 24..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%c\n",(a!=b)?((a<b)?'<':'>'):'=');
    }
    
    return 0;
}
