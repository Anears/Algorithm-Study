//
//  [BOJ_9015]정사각형.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 21..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
typedef pair<int,int> ii;

vector<ii> point;

inline ii sumii(ii x,ii y){ return ii(x.first+y.first, x.second+y.second); }
inline ii subii(ii x,ii y){ return ii(x.first-y.first, x.second-y.second); }
inline double cal(ii a,ii b){ return pow(a.first-b.first,2)+pow(a.second-b.second,2); }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        point.clear();
        set<ii> s;
        for(int i=0;i<n;++i){
            ii x;
            scanf("%d%d",&x.first,&x.second);
            point.push_back(x);
            s.insert(x);
        }
        
        int ans=0,k;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                ii&p1=point[i],p2=point[j];
                ii a,aa,b,bb;
                a=subii(p1, p2);
                aa=ii(-a.second,a.first);
                aa=sumii(aa,p2);
                b=subii(p2, p1);
                bb=ii(b.second,-b.first);
                bb=sumii(bb, p1);
                if(s.find(aa)!=s.end() && s.find(bb)!=s.end()){
                    if(ans<(k=cal(p1,p2)))
                        ans=k;
                }
                
                a=subii(p1, p2);
                aa=ii(a.second,-a.first);
                aa=sumii(aa,p2);
                b=subii(p2, p1);
                bb=ii(-b.second,b.first);
                bb=sumii(bb, p1);
                if(s.find(aa)!=s.end() && s.find(bb)!=s.end()){
                    if(ans<(k=cal(p1,p2)))
                        ans=k;
                }
                
                a=subii(p1, p2);
                aa=ii(-a.second,a.first);
                if((a.first+aa.first)%2!=0 || (a.second+aa.second)%2!=0)
                    continue;
                aa=ii((a.first+aa.first)/2,(a.second+aa.second)/2);
                aa=sumii(aa, p2);
                
                b=subii(p1, p2);
                bb=ii(a.second,-a.first);
                if((b.first+bb.first)%2!=0 || (b.second+bb.second)%2!=0)
                    continue;
                bb=ii((b.first+bb.first)/2,(b.second+bb.second)/2);
                bb=sumii(bb, p2);
                if(s.find(aa)!=s.end() && s.find(bb)!=s.end()){
                    if(ans<(k=cal(p1,aa)))
                        ans=k;
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
