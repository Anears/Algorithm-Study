//
//  [BOJ_11605]Magic_Trick.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 21..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

pair<string,int> si[10];

int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>si[i].first>>si[i].second;
    for(int i=1;i<=100;++i){
        bool chk=true;
        int p=i;
        for(int i=0;i<n;++i){
            if(si[i].first=="ADD") p+=si[i].second;
            else if(si[i].first=="SUBTRACT"){
                if(p<si[i].second){
                    chk=false;
                    break;
                }
                p-=si[i].second;
            }
            else if(si[i].first=="MULTIPLY") p*=si[i].second;
            else if(si[i].first=="DIVIDE"){
                if(p%si[i].second!=0){
                    chk=false;
                    break;
                }
                p/=si[i].second;
            }
        }
        if(!chk) ans++;
    }
    cout<<ans;
    return 0;
}
