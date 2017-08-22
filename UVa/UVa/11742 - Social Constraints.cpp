//
//  11742-SocialConstraints.cpp
//  UVa
//
//  Created by minji on 2017. 7. 12..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define ABS(x) ((x)>=0?(x):-(x))

using namespace std;
struct cons{
    int a,b,c;
}con[20];
int sit[8];
int main()
{
    while(1){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&con[i].a,&con[i].b,&con[i].c);
        for(int i=0;i<n;++i)
            sit[i]=i;
        int cnt=0;
        do{
            bool chk=true;
            for(int i=0;i<m;++i){
                int tmp=sit[con[i].a]-sit[con[i].b];
                if(con[i].c>0 && ABS(tmp)>ABS(con[i].c))
                {chk=false;break;}
                if(con[i].c<0 && ABS(tmp)<ABS(con[i].c))
                {chk=false;break;}
            }
            if(chk)cnt++;
        }while(std::next_permutation(sit, sit+n));
        printf("%d\n",cnt);
    }
    
    return 0;
}
