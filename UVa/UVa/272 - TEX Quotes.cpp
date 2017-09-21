//
//  272 - TEX Quotes.cpp
//  UVa
//
//  Created by minji on 2017. 8. 24..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <cstdio>

int main()
{
    char ch;
    bool op = true;
    while(scanf("%c",&ch) != EOF){
        if(ch == '"'){
            if(op) printf("``");
            else printf("''");
            op=!op;
        }
        else printf("%c",ch);
    }
    return 0;
}
