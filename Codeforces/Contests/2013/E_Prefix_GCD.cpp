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
vector<int> divi[N], mp[N];

void sieve() {
    for (int i = 2; i < N; i++) for (int j = i; j < N; j += i) divi[j].pb(i);
}

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    if (n == 1) return void(cout << v.front() << endl);

    sort(all(v));


    int ans = v[0], g = v[0];

    for (auto& x : v) x = __gcd(x, v[0]);
    reverse(all(v));
    v.pop_back();
    reverse(all(v));


    map<int,int> mp;
    multiset<pair<int,int>> s;
    for (auto x : v) mp[x]++;
    for (auto x : mp) s.insert(x);


    while (!s.empty()) {
        if (g == 1) {
            auto [curr, occ] = *s.begin();
            assert(curr==1);
            ans++;
            s.erase(s.begin());
            if (occ > 1) s.insert({curr, occ - 1});
            continue ;
        }


        auto [curr, occ] = *s.begin();
        s.erase(s.begin());
        if (occ > 1) s.insert({curr, occ - 1});
        g = __gcd(g, curr);

        ans += g;

        map<int,int> mpp;
        for (auto x : s) mpp[__gcd(x.F, g)] += x.S;
        s.clear();
        for (auto x : mpp) s.insert(x);
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
    sieve();
    while (Test_case--) Solve();
}
