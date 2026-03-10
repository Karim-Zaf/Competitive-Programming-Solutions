/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> dv[N];

void sieve(){
    for (int i = 2; i < N; i++){
        for (int j = i; j < N; j += i)
            dv[j].pb(i);
    }
}

vector<int> mp[N];

void Solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (auto x : v) mp[x].clear();
    for (int i = 1; i <= n; i++) mp[v[i]].pb(i);

    auto exist = [&](int x, int l, int r)-> int{
        auto pos = lower_bound(mp[x].begin(), mp[x].end(), l);
        if (pos != mp[x].end() && *pos <= r) return *pos;
        return -1ll;
    };
    while (q--){
        int k, l, r;
        cin >> k >> l >> r;

        vector<int> pos;

        for (auto d : dv[k]){
            auto x = exist(d, l, r);
            if (x != -1) pos.pb(x);
        }

        sort(all(pos));
        int prev = l, ans = 0;

        for (auto p : pos){
            ans += (p - prev) * k;

            while (k % v[p] == 0){ k /= v[p]; }

            prev = p;
        }
        ans += (r - prev+1) * k;

        cout << ans << endl;
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    sieve();
    while (Test_case--) Solve();
}
