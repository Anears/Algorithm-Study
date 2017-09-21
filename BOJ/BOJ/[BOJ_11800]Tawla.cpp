//
//  [BOJ_11800]Tawla.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 13..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b) a^=b^=a^=b;
        
        printf("Case %d: ",tc++);
        if(a==b){
            if(a==1) printf("Habb Yakk");
            else if(a==2) printf("Dobara");
            else if(a==3) printf("Dousa");
            else if(a==4) printf("Dorgy");
            else if(a==5) printf("Dabash");
            else if(a==6) printf("Dosh");
        }
        else if(a==6 && b==5)
            printf("Sheesh Beesh");
        else{
            char str[7][10]={"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
            printf("%s %s",str[a],str[b]);
        }
        printf("\n");
    }
    
    return 0;
}
