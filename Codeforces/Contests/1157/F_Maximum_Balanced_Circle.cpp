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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    int n , flag = 1;
    cin >> n ;
    vector<int> v(n) ,ans;
    for (auto &x: v) cin >> x;
    sort (all(v));

    vector<int> lef , righ ;

    for (auto x: v) {
        bool one = righ.empty() ||abs (x-righ.back())<=1 ;
        bool two = lef.empty() ||abs (x-lef.back())<=1 ;

        if (one && two ){
            if (flag) lef.pb(x);
            else righ.pb(x);
            flag ^=1 ;
        }else{
            vector<int> nw ;
            nw = lef ;
            reverse(all(righ));
            for (auto e: righ) nw.pb(e);

            if (nw.size()>ans.size()) ans = nw ;

            int add =-1;

            if (!righ.empty() &&abs (x-righ.back())<=1) add = righ.back();
            if (!lef.empty() &&abs (x-lef.back())<=1) add = lef.back();

            righ.clear();
            lef.clear();

            if (add !=-1){
                lef.pb(add) ;
                righ.pb(x);
                flag = 1 ;
            }else {
                lef.pb(x);
                flag = 0 ;
            }
        }
    }
    vector<int> nw ;
    nw = lef ;
    reverse(all(righ));
    for (auto e: righ) nw.pb(e);

    if (nw.size()>ans.size()) ans = nw ;

    cout << ans.size() << endl;
    for (auto x: ans ) cout << x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}