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

void Solve(){
    map<int,int> mp;
    map<int, vector<int>> pos;
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) cin >> x;
    for (auto x : v)mp[x]++;

    for (int i = 0; i < n; i++) pos[v[i]].pb(i);

    if (!mp[0]) return void(cout << n << endl);
    for (auto& x : v) if (!x) x = INF;
    int ans = (n - mp[0]);
    v[pos[0].front()] = 0;

    int nxt = 0;
    for (int i = n - 1; i >= 0; i--){
        if (nxt == v[i]){
            while (true){
                nxt++;
                if (pos[nxt].empty()) return void(cout << ++ans << endl);
                if (pos[nxt].front() >= i) continue ;
                if (pos[nxt].size() == 1){ break; }
                return void(cout << ans << endl);
            }
        }
    }
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
