/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=5e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , k ,res =INF ;
    cin >> n >> k ;

    auto work =[&] (int a , int b)->int{
        string s = '0'+to_string (n) ;
        string ret = s ;
        bool flag = false ;
        if(a>b) swap (a,b);
        auto to_char =[] (int x){return char('0'+x);};
        for (int i= 1 ;i<s.size() ;i++){
            if (flag) {ret[i] = to_char(min (a,b));continue;}
            if (to_char(a)==s[i]||to_char(b)==s[i]){ret[i]=s[i];continue;}
            flag = true;
            if (to_char(min(a,b))>s[i]){ret[i]=to_char(min(a,b));continue;}
            if (to_char(max(a,b))>s[i]){ret[i]=to_char(max(a,b));continue;}
            ret[i]=to_char(min(a,b));
            for (int j= i-1 ; j>=0 ;j--){
                if (ret[j]<=to_char(a) && to_char(b)>=ret[j]) {
                    ret[j]=to_char(b);
                    for (int d = j+1 ; d<=i ; d++) ret[d]=to_char(a);
                    break;
                }
            }
        }
        reverse(all(ret));
        int foix = 1 , ans=0;
        for (char c : ret){
            ans += (c-'0')*foix ;
            foix *= 10;
        }
        return ans ;
    };
    for (int i=0 ;i<=9; i++) {
        int poss = work( i,i);
        if (poss>=n)res = min(res, poss);
        if (k==1)continue;
        for (int j = 0; j <= 9; j++) {
            poss = work( i,j);
            if (poss>=n)res = min(res, poss);
        }
    }

    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}