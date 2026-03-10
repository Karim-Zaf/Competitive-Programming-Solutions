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

void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n), suff(n + 2), pref(n + 3);

    for (auto& i : v) cin >> i;
    sort(all(v));

    for (int i = n - 1; i >= 0; i--)suff[i] = v[i] + suff[i + 1];
    pref[0] = v[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + v[i];

    auto ok = [&](int md){
        for (int i = 0; i < n; i++){
            int req = v[i] * (i + 1) - pref[i];
            int pos = upper_bound(v.begin(), v.end(), v[i] + md) - v.begin();
            req += suff[pos] - (n - pos) * (v[i] + md);
            if (req <= k) return true;
        }

        for (int i = n - 1; i >= 0; i--){
            int req = suff[i] - v[i] * (n - i);
            int pos = lower_bound(v.begin(), v.end(), v[i] - md) - v.begin();
            if (pos >= 1){
                pos--;
                req += (pos + 1) * (v[i] - md) - pref[pos];
            }
            if (req <= k) return true;
        }

        return false;
    };
    int l = 0, r = INF, ans = -1;

    while (l <= r){
        int md = l + (r - l) / 2;

        if (ok(md)){
            r = md - 1;
            ans = md;
        }
        else l = md + 1;
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
