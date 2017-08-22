//
//  10911 - Forming Quiz Teams.cpp
//  UVa
//
//  Created by minji on 2017. 8. 23..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MINV(a,b) (((a)<(b))?(a):(b))
#define INF 1000000000

int px[16],py[16],n;
double vis[1<<16];

double dis(int a, int b){
    return sqrt(pow(px[a]-px[b],2)+pow(py[a]-py[b], 2));
}

double pro(int state){
    if(vis[state] != INF) return vis[state];
    
    double ret = INF;
    for(int i=0;i<2*n;++i){
        if(!(state & (1<<i))) continue;
        for(int j=i+1;j<2*n;++j){
            if(!(state & (1<<j))) continue;
            ret = MINV(ret, pro((state&(~(1<<i)))&(~(1<<j))) + dis(i,j));
        }
    }
    return vis[state] = ret;
}

int main()
{
    int tc = 1;
    while(scanf("%d",&n)==1 && n){
        char name[20];
        for(int i=0;i<2*n;++i)
            scanf("%s %d %d",name,&px[i],&py[i]);
        for(int i=0;i<(1<<(2*n));++i)
            vis[i]=INF;
        
        vis[0] = 0;
        double res = pro((1<<(2*n))-1);
        
        printf("Case %d: %.2lf\n",tc,res);
        tc++;
    }
    return 0;
}
