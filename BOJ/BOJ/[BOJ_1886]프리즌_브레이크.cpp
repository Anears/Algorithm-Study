//
//  [BOJ_1886]프리즌_브레이크.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 1..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <vector>
#define INF 1000000000

using namespace std;
int dis[144][144];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n*m;++i){
        for(int j=0;j<n*m;++j)
            dis[i][j]=INF;
    }
    
    vector<char> map(m,' ');
    vector<int> door,jail;
    for(int i=0;i<n;++i){
        getchar();
        for(int j=0;j<m;++j){
            char ch;
            scanf("%c",&ch);
            int pos = m*(i-1)+j;
            if(ch=='X') continue;
            else if(ch=='D') door.push_back(pos);
            else if(ch=='.') jail.push_back(pos);
            if(i!=0 && map[j]!='X')
                dis[pos-m][pos]=dis[pos][pos-m] = 1;
            if(j!=0 && map[j-1]!='X')
                dis[pos-1][pos]=dis[pos][pos-1] = 1;
        }
    }
    
    for()
    
    
    return 0;
}
