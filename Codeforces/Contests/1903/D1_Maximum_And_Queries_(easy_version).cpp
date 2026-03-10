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
//#define int ll
#define endl '\n'

const int  N=2e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    ll n, q;
    cin >> n >> q ;
    vector <ll> v(n) ;
    for (auto &x: v) cin >> x;
    while (q--){
        ll k , res = 0  ;
        cin >> k ;
        vector <ll> a= v ;
        for (int j= 61 ; j>=0 ; j--){
            int lezem =0 , indx=-1;
            vector<int> p ;
            for (auto &curr : a) {
                indx++;
                if ((1ll<<j) & curr  ) {curr -= (1ll<<j); continue;}
                lezem += (1ll<<j) -curr ;
                p.pb(indx);
            }
            if (lezem >k) continue;
            else {
                k-= lezem ;
                for (auto xx:  p ) a[xx]=0;
                res += (1ll<<j);
            }
        }
        cout << (ll)res << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}