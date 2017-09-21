//
//  [BOJ_9632]Swyper_Keyboard.cpp
//  brute_force
//
//  Created by minji on 2017. 9. 20..
//  Copyright © 2017년 KGT. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str,dic,sub;
string adj[26][26]={
    {{""},{""},{"B"},{"BC"},{"BCD"},{""},{""},{""},{"BH"},{"BI"},{"BCIJ"},{"BCJK"},{"GF"},{"G"},{"GH"},{"H"},{"BHIP"},{"BHIJQ"},{"BHIJKR"},{"GM"},{"GN"},{"GO"},{"GHOP"},{"HP"},{"BHIPQX"},{"BHIQRY"}},
    {{""},{""},{""},{"C"},{"CD"},{"AG"},{""},{""},{""},{"CI"},{"CJ"},{"CDJK"},{"G"},{"HG"},{"H"},{"HI"},{"I"},{"CIJQ"},{"CIJKR"},{"HGNM"},{"HN"},{"HO"},{"HP"},{"HIPQ"},{"IQ"},{"CIJQRY"}},
    {{"B"},{""},{""},{""},{"D"},{"BG"},{"BH"},{""},{""},{""},{"DJ"},{"DK"},{"BHGN"},{"H"},{"IH"},{"I"},{"IJ"},{"J"},{"DJKR"},{"HN"},{"IHON"},{"IO"},{"IP"},{"IQ"},{"IJQR"},{"JR"}},
    {{"CB"},{"C"},{""},{""},{""},{"CBHG"},{"CH"},{"CI"},{""},{""},{""},{"EK"},{"CIHGN"},{"CIHO"},{"I"},{"JI"},{"J"},{"JK"},{"K"},{"CIHONU"},{"IO"},{"JIPO"},{"JP"},{"JQ"},{"JR"},{"JKRS"}},
    {{"DCB"},{"DC"},{"D"},{""},{""},{"DCHG"},{"DCIH"},{"DI"},{"DJ"},{""},{""},{""},{"DJIHGN"},{"DJIHO"},{"DJIP"},{"J"},{"KJ"},{"K"},{"KL"},{"DJIONU"},{"DJIPOV"},{"JP"},{"KJQP"},{"KQ"},{"KR"},{"KS"}},
    {{""},{"GA"},{"GB"},{"GHBC"},{"GHCD"},{""},{""},{"G"},{"GH"},{"GHI"},{"GHIJ"},{"GHIJK"},{""},{""},{"GN"},{"GO"},{"GHOP"},{"GHPQ"},{"GHIPQR"},{"M"},{"MN"},{"N"},{"GNOV"},{"GNOPW"},{"GNOPQX"},{"GOPQY"}},
    {{""},{""},{"HB"},{"HC"},{"HICD"},{""},{""},{""},{"H"},{"HI"},{"HIJ"},{"HIJK"},{""},{""},{""},{"HO"},{"HP"},{"HIPQ"},{"HIQR"},{"NM"},{"N"},{"NO"},{"O"},{"HOPW"},{"HOPQX"},{"HOPQRY"}},
    {{""},{""},{""},{"IC"},{"ID"},{"G"},{""},{""},{""},{"I"},{"IJ"},{"IJK"},{"GN"},{""},{""},{""},{"IP"},{"IQ"},{"IJQR"},{"N"},{"ON"},{"O"},{"OP"},{"P"},{"IPQX"},{"IPQRY"}},
    {{"HB"},{""},{""},{""},{"JD"},{"HG"},{"H"},{""},{""},{""},{"J"},{"JK"},{"HN"},{"HO"},{""},{""},{""},{"JQ"},{"JR"},{"HONU"},{"O"},{"PO"},{"P"},{"PQ"},{"Q"},{"JQRY"}},
    {{"IB"},{"IC"},{""},{""},{""},{"IHG"},{"IH"},{"I"},{""},{""},{""},{"K"},{"IHON"},{"IO"},{"IP"},{""},{""},{""},{"KR"},{"IPONU"},{"IPOV"},{"P"},{"QP"},{"Q"},{"QR"},{"R"}},
    {{"JICB"},{"JC"},{"JD"},{""},{""},{"JIHG"},{"JIH"},{"JI"},{"J"},{""},{""},{""},{"JION"},{"JIPO"},{"JP"},{"JQ"},{""},{""},{""},{"JQPONU"},{"JQPOV"},{"JQPW"},{"Q"},{"RQ"},{"R"},{"RS"}},
    {{"KJCB"},{"KJDC"},{"KD"},{"KE"},{""},{"KJIHG"},{"KJIH"},{"KJI"},{"KJ"},{"K"},{""},{""},{"KJIPON"},{"KJPO"},{"KJQP"},{"KQ"},{"KR"},{""},{""},{"KQPOU"},{"KRQPOV"},{"KRQPW"},{"KRQX"},{"R"},{"SR"},{"S"}},
    {{"FG"},{"G"},{"NGHB"},{"NGHIC"},{"NGHIJD"},{""},{""},{"NG"},{"NH"},{"NOHI"},{"NOIJ"},{"NOPIJK"},{""},{""},{"N"},{"NO"},{"NOP"},{"NOPQ"},{"NOPQR"},{""},{""},{"NU"},{"NV"},{"NOVW"},{"NOWX"},{"NOPWXY"}},
    {{"G"},{"GH"},{"H"},{"OHIC"},{"OHIJD"},{""},{""},{""},{"OH"},{"OI"},{"OPIJ"},{"OPJK"},{""},{""},{""},{"O"},{"OP"},{"OPQ"},{"OPQR"},{""},{""},{""},{"OV"},{"OW"},{"OPWX"},{"OPXY"}},
    {{"HG"},{"H"},{"HI"},{"I"},{"PIJD"},{"NG"},{""},{""},{""},{"PI"},{"PJ"},{"PQJK"},{"N"},{""},{""},{""},{"P"},{"PQ"},{"PQR"},{"NU"},{""},{""},{""},{"PW"},{"PX"},{"PQXY"}},
    {{"H"},{"IH"},{"I"},{"IJ"},{"J"},{"OG"},{"OH"},{""},{""},{""},{"QJ"},{"QK"},{"ON"},{"O"},{""},{""},{""},{"Q"},{"QR"},{"OU"},{"OV"},{""},{""},{""},{"QX"},{"QY"}},
    {{"PIHB"},{"I"},{"JI"},{"J"},{"JK"},{"POHG"},{"PH"},{"PI"},{""},{""},{""},{"RK"},{"PON"},{"PO"},{"P"},{""},{""},{""},{"R"},{"POVU"},{"PV"},{"PW"},{""},{""},{""},{"RY"}},
    {{"QJIHB"},{"QJIC"},{"J"},{"KJ"},{"K"},{"QPHG"},{"QPIH"},{"QI"},{"QJ"},{""},{""},{""},{"QPON"},{"QPO"},{"QP"},{"Q"},{""},{""},{""},{"QPVU"},{"QPWV"},{"QW"},{"QX"},{""},{""},{""}},
    {{"RKJIHB"},{"RKJIC"},{"RKJD"},{"K"},{"LK"},{"RQPIHG"},{"RQIH"},{"RQJI"},{"RJ"},{"RK"},{""},{""},{"RQPON"},{"RQPO"},{"RQP"},{"RQ"},{"R"},{""},{""},{"RQPWVU"},{"RQWV"},{"RQXW"},{"RX"},{"RY"},{""},{""}},
    {{"MG"},{"MNGH"},{"NH"},{"UNOHIC"},{"UNOIJD"},{"M"},{"MN"},{"N"},{"UNOH"},{"UNOPI"},{"UNOPQJ"},{"UOPQK"},{""},{""},{"UN"},{"UO"},{"UVOP"},{"UVPQ"},{"UVWPQR"},{""},{""},{"U"},{"UV"},{"UVW"},{"UVWX"},{"UVWXY"}},
    {{"NG"},{"NH"},{"NOHI"},{"OI"},{"VOPIJD"},{"NM"},{"N"},{"NO"},{"O"},{"VOPI"},{"VOPQJ"},{"VOPQRK"},{""},{""},{""},{"VO"},{"VP"},{"VWPQ"},{"VWQR"},{""},{""},{""},{"V"},{"VW"},{"VWX"},{"VWXY"}},
    {{"OG"},{"OH"},{"OI"},{"OPIJ"},{"PJ"},{"N"},{"ON"},{"O"},{"OP"},{"P"},{"WPQJ"},{"WPQRK"},{"UN"},{""},{""},{""},{"WP"},{"WQ"},{"WXQR"},{"U"},{""},{""},{""},{"W"},{"WX"},{"WXY"}},
    {{"POHG"},{"PH"},{"PI"},{"PJ"},{"PQJK"},{"VONG"},{"O"},{"PO"},{"P"},{"PQ"},{"Q"},{"XQRK"},{"VN"},{"VO"},{""},{""},{""},{"XQ"},{"XR"},{"VU"},{"V"},{""},{""},{""},{"X"},{"XY"}},
    {{"PH"},{"QPIH"},{"QI"},{"QJ"},{"QK"},{"WPONG"},{"WPOH"},{"P"},{"QP"},{"Q"},{"QR"},{"R"},{"WVON"},{"WO"},{"WP"},{""},{""},{""},{"YR"},{"WVU"},{"WV"},{"W"},{""},{""},{""},{"Y"}},
    {{"XQPIHB"},{"QI"},{"RQJI"},{"RJ"},{"RK"},{"XQPONG"},{"XQPOH"},{"XQPI"},{"Q"},{"RQ"},{"R"},{"RS"},{"XWON"},{"XWPO"},{"XP"},{"XQ"},{""},{""},{""},{"XWVU"},{"XWV"},{"XW"},{"X"},{""},{""},{""}},
    {{"YRQIHB"},{"YRQJIC"},{"RJ"},{"SRKJ"},{"SK"},{"YQPOG"},{"YRQPOH"},{"YRQPI"},{"YRQJ"},{"R"},{"SR"},{"S"},{"YXWPON"},{"YXPO"},{"YXQP"},{"YQ"},{"YR"},{""},{""},{"YXWVU"},{"YXWV"},{"YXW"},{"YX"},{"Y"},{""},{""}}};

int main()
{
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n>>str;
        dic=str[0];
        for(int i=1;i<str.length();++i)
            dic+=adj[str[i-1]-'A'][str[i]-'A']+str[i];
        
        bool chk=false;
        string ans;
        while(n--){
            cin>>sub;
            if(chk) continue;
            int q=0,w=0;
            while(q<dic.length() && w<sub.length()){
                if(dic[q]==sub[w]) w++;
                q++;
            }
            if(w==sub.length()) {chk=true; ans=sub;}
        }
        if(chk) cout<< ans<<endl;
        else cout<<"NO SOLUTION"<<endl;
    }
    
    return 0;
}
