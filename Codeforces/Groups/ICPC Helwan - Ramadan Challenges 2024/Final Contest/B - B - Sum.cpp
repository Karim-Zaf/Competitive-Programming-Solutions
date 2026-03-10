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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    int a, b ;
    cin >> a >> b ;
    string aa = to_string (a) ;
    int base = 1 ;
    for (auto c: aa) base= max (base, c-'0'+1ll) ;
    string bb  = to_string (b) ;
    for (auto c: bb) base= max (base, c-'0'+1ll) ;

    int aaa = 0 , bbb= 0 ;
    int puiss = 1 ;

    reverse(all(aa));
    for (auto c: aa){
        aaa += puiss* (c-'0') ;
        puiss*= base ;
    }

    reverse(all(bb));
    puiss = 1 ;
    for (auto c: bb){
        bbb += puiss* (c-'0') ;
        puiss*= base ;
    }

    int x = aaa + bbb ;

    string ans = "" ;
    while(x){
        int curr = x % base ;
        x/= base ;
        ans = to_string(curr) + ans ;

    }
    kar (ans);
    cout << ans.size()<< endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}