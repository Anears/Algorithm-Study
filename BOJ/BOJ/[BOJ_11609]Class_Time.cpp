//
//  [BOJ_11609]Class_Time.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 21..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef pair<string, string> ii;


bool cmp(ii&a,ii&b){
    return a.second<b.second ||(a.second==b.second && a.first<b.first);
}

int main()
{
    int n;
    cin>>n;
    vector<ii> arr(n);
    for(ii&x:arr)
        cin>>x.first>>x.second;
    sort(arr.begin(), arr.end(), cmp);
    for(ii&x:arr)
        cout<<x.first<<" "<<x.second<<endl;
    
    return 0;
}
