//
//  convention.cpp
//  UVa
//
//  Created by minji on 2017. 8. 23..
//  Copyright © 2017년 KGT. All rights reserved.
//

#define _CRTSECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

// ans = a ? b : c;
// ans += val;
// index = (index + 1) % n;
// index = (index + n - 1) % n;
// int ans = (int)((double)d + 0.5);

//중복 제거
//sort(a.begin(),a.end());
//a.resize(unique(a.begin(),a.end())-a.begin())

int main()
{
    int n=5, l[] = {10, 7, 5, 20, 8}, v = 6;
    sort(l,l+n);
    printf("%d\n",binary_search(l, l+n, v));
    printf("%ld\n",lower_bound(l, l+n, v)-l);
    printf("%ld\n",upper_bound(l, l+n, v)-l);
    return 0;
}
