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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(x);
    map<int, int> mp;
    for (auto &xx: v) {
        cin >> xx;
        mp[xx] = 1;
    }
    sort(all(v));

    int ans = x + y - 2, add = 0;
    for (int i = 0; i < x; i++) {
        int nxt1 = (v[i]) % n + 1;
        int nxt2 = (v[i] + 1) % n + 1;
        ans += (!mp[nxt1] && mp[nxt2]);
    }

    vector<int> pair, impair;
    for(int i= 1 ;i<x ; i++){
        int dist = abs(v[i] - v[i-1]) - 1;
        if (dist % 2 && dist > 1) impair.pb(dist);
        else if (dist > 1)pair.pb(dist);
    kar (dist);
    }

    int dist_lst = n- v.back() + v.front()-1 ;
    kar (dist_lst);
    if (dist_lst % 2 && dist_lst > 1) impair.pb(dist_lst);
    else if (dist_lst > 1)pair.pb(dist_lst);

    sort (all(pair));
    sort (all(impair));

    for (auto d: impair){
        if (y<=0) continue;
        if (d/2<=y){
            y -= d/2 ;
            ans += (d+1)/2 ;
        }else {
            ans+= y ;
            y= 0 ;
        }

    }
    kar (pair);
    for (auto d: pair){
            kar(y);
        if (y<=0) continue;
        if (d/2<=y){
            y -= d/2;
            ans += (d+1)/2 ;
        }else {
            ans+= y ;
            y= 0 ;
        }

    }
    cout << min(n - 2, ans) << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}