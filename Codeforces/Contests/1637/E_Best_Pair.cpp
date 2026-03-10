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
    int n, m, ans = 0, cnt = 0;
    cin >> n >> m;

    vector<int> v(n), mp(n + 1), pos(n + 1), equiv(n + 4);
    map<int, int> comp;

    for (auto& x : v) cin >> x;
    for (auto& x : v) comp[x] = 1;

    for (auto [val , key] : comp) {
        comp[val] = ++cnt;
        equiv[cnt] = val;
    }

    auto get = [&](int x) { return comp[x]; };

    for (auto& x : v) mp[get(x)]++;
    set<int> s;
    for (int i = 1; i <= cnt; i++) if (mp[i]) s.insert(mp[i]);
    vector<int> occurences(all(s));

    vector<pair<int,int>> vp(m);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (v < u) swap(u, v);
        vp[i] = {u, v};
    }
    sort(rall(vp));


    vector<int> t[n + 1], occur[n + 4];

    for (auto [u,v] : vp) {
        t[get(v)].pb(get(u));
    }

    for (int i = 1; i <= cnt; i++) {

        for (auto& x : t[i]) {
            if (!occur[mp[x]].empty() && occur[mp[x]].back() == x) occur[mp[x]].pop_back();
        }

        for (auto& occ : occurences) {
            if (occur[occ].empty()) continue ;

            int one = i;
            int two = occur[occ].back();
            ans = max(ans, (mp[one] + mp[two]) * (equiv[one] + equiv[two]));
        }
        reverse(all(t[i]));
        for (auto& x : t[i]) {
            if (occur[mp[x]].empty() || x > occur[mp[x]].back()) occur[mp[x]].pb(x);
        }
        occur[mp[i]].pb(i);
    }

    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
