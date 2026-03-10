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
#define int __int128
#define endl '\n'
 
const int N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
 
void Solve() {
    string eo ;
    cin >> eo ;
    set <int> s ;
    int j = 1 ;
    for (int i= 0 ;i<124; i++){
        s.insert(j);
        j*=2 ;
    }
    auto bp = [] (int x ){
        int cnt = 0 , j=1;
        for (int i= 0 ;i<=126; i++) {
            if (j & x) cnt++;
            j *= 2;
        }
        return cnt ;
    };
 
    reverse (all(eo));
    if (eo[0]=='E'){cout << "INVALID\n";return;}
    for (auto c: eo){
        set <int> nw_s;
        for (auto curr :s){
            int e = 2*curr ;
            int o = (curr-1)/3 ;
            int e_cnt =  bp(e);
            int o_cnt =  bp(o);
            if (e<=j&& c=='E' && e_cnt !=1)  nw_s.insert(e) ;
            else if ( o<=j&&c=='O'&& (curr -1) %3==0 && o%2==1 && o_cnt !=1)
                nw_s.insert(o);
        }
        s = nw_s ;
        if (s.empty()){cout << "INVALID\n";return;}
    }
    cout << (ll)*s.begin() ;
 
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--)Solve();
}