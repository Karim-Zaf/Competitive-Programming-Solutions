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
#define int __int128
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> v(n);
    for (auto& x : v) cin >> x;

    int l = 1, r = n * k, ans = 0;

    while (l <= r){
        int md = l + (r - l) / 2;

        int curr = (md) / n;

        int sum = 0;
        sum += curr * (ll)accumulate(all(v), 0ll);

        int indx = md - n * curr;
        for (int i = 0; i < indx; i++)sum += v[i];
        if (k * (ll)accumulate(all(v), 0ll) - sum + v[((indx - 1) + n) % n] >= x){
            l = md + 1;
            ans = md;
        }
        else r = md - 1;
    }

    cout << (ll)ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    ll Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
