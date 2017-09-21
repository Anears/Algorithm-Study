//
//  [BOJ_9637]The_Stones_Game.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int t,n,m,x; cin>>t;
    while(t--){
        cin>>n>>m>>x;
        cout<<((n%m==x%m)?"YES":"NO")<<endl;
    }
    return 0;
}
