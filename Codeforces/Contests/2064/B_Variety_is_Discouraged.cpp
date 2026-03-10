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
//hello everyonnee !!!
void Solve(){
    int n;
    cin >> n;
    vector<int> v(n + 1);
    map<int,int> mp;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) mp[v[i]]++;

    vector<pair<int,int>> pos;
    for (int i = 1; i <= n; i++){
        if (mp[v[i]] == 1){
            if (!pos.empty() && pos.back().S == i - 1) pos[pos.size() - 1].S = i;
            else pos.pb({i, i});
        }
    }
    if (pos.empty()) return void(cout << 0 << endl);
    pair<int,int> ans = pos[0];
    for (auto [u,v] : pos){ if (v - u > ans.S - ans.F) ans = {u, v}; }

    cout << ans.F << " " << ans.S << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
