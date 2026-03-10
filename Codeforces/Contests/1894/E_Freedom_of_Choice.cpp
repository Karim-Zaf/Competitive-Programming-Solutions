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
    int m ,mx = 0, mn = 0;
    cin >> m;

    map<int,int> mp_max, mp_min ;
    vector<map<int,int>> v(m+3);

    vector<pair<int,int>> inter (m+3) ;

    for (int i= 1, l ,r, n ; i<=m ;i++){
        cin >> n>> l >>r;

        vector <int> a(n) ,c(n) ;

        for (auto &x: a) cin >> x;
        for (int j= 0,occ ; j<n ;j++){
            cin >> occ ;
            v[i][a[j]]+=occ;
        }

        inter[i]={l,r};
        mx+= r ; mn += l ;
    }

    for (int i= 1; i<=m ;i++){
        auto mape = v[i];
        int sum =0 ;
        for (auto x: mape) sum+= x.S ;
        for (auto [val,occ]: mape){
            int other_max = sum - occ;
            other_max = inter[i].S-other_max;
            other_max = max(0ll,other_max);

            mp_max[val]+= other_max ;

            int sz = inter[i].S-inter[i].F;

            mp_min[val]+=  min(other_max,sz) ;
        }
    }

    int ans = INF ;


    for (int val= mn ; val<=mx ; val++){
        if (!mp_max[val]) {cout << "0\n";return;}

        int subs = mx - val ;

        int pot = mp_max[val]-min(subs,mp_min[val]);

        ans = min(ans ,pot) ;
    }

    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}