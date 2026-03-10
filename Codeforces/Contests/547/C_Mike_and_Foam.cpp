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

const int N = 5e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int mp[N];

vector<int> factors(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        if (n % i)continue;
        ret.pb(i);
        while (n % i == 0)n /= i;
    }
    if (n > 1) ret.pb(n);
    return ret;
}

void Solve() {

    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    set<int> s;

    while (q--) {
        int x;
        cin >> x;
        vector<int> f = factors(v[x]);
        int sz = f.size();

        if (s.find(x) != s.end()) {
            for (int mask = 1; mask < (1 << sz); mask++) {
                int prd = 1;
                for (int j = 0; j < sz; j++)
                    if (mask >> j & 1)
                        prd *= f[j];
                mp[prd]--;
            }
        }

        int cnt = 0;

        for (int mask = 1; mask < (1 << sz); mask++) {
            int prd = 1;
            for (int j = 0; j < sz; j++)
                if (mask >> j & 1)
                    prd *= f[j];
            int p = __builtin_popcount(mask);
            if (p % 2) cnt += mp[prd];
            else cnt -= mp[prd];
        }


        cnt = s.size() - cnt;

        if (s.find(x) == s.end()) ans += cnt;
        else ans -= cnt - 1;

        if (s.find(x) == s.end()) {
            for (int mask = 1; mask < (1 << sz); mask++) {
                int prd = 1;
                for (int j = 0; j < sz; j++)
                    if (mask >> j & 1)
                        prd *= f[j];

                mp[prd]++;
            }
        }

        cout << ans << endl;

        if (s.find(x) == s.end())s.insert(x);
        else s.erase(x);
    }

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}