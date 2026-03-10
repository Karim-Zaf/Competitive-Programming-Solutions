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
    int n , q;
    cin >> n ;
    vector<int> v(n) ;
    for (auto &x: v)cin >> x;

    int prev =v[0] , lst = 0;
    set<pair<int,int>> s ;
    for (int i= 1 ;i<n; i++){
        if (v[i]==prev)continue;
        s.insert({lst+1,i});
        lst = i ;
        prev= v[i] ;
    }
    s.insert({lst+1,n});


    cin >> q ;
    while (q--){
        int l , r ;
        cin >> l >> r  ;
        pair<int,int>p ={l,INF};
        auto pos = s.lower_bound(p) ;
        if (pos==s.end()) {
            cout << "-1 -1\n";
            continue;
        }
        auto pos2 = pos;
        pos2--;

        auto[l1,r1]= *pos;
        auto[l2,r2]= *pos2;

        if (l1 > r) {
            cout << "-1 -1\n";
            continue;
        }
        cout << r2 << " " << l1 << endl;
    }
    cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}