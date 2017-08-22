//
//  11195 - Another n-Queen Problem.cpp
//  UVa
//
//  Created by minji on 2017. 7. 12..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>

int n,cnt;
bool chk0[15], chk1[31], chk2[31];

void nQueen(int x) {
    if (x == n)
        ++cnt;
    else {
        for (int y = 0;y < n;++y) {
            if (!chk0[y] && !chk1[x + y] && !chk2[x - y + n]) {
                chk0[y] = chk1[x + y] = chk2[x - y + n] = true;
                nQueen(x + 1);
                chk0[y] = chk1[x + y] = chk2[x - y + n] = false;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    nQueen(0);
    printf("%d", cnt);
    return 0;
}
