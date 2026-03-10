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
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int sum = accumulate(v.begin(), v.end(), 0ll);

    int tours = h / sum;
    if (h % sum == 0){
        cout << tours * n + (tours - 1) * k << endl;
        return;
    }
    int ans = tours * (n + k);
    h -= tours * sum;

    multiset<int> lef, righ(all(v));

    int pref = 0;
    int i = 0;
    for (auto x : v){
        lef.insert(x);
        righ.erase(righ.find(x));
        i++;
        pref += x;
        int mn = *lef.begin();
        int mx = mn;
        if (!righ.empty()) mx = max(*prev(righ.end()), mx);

        int nw_pref = pref;
        nw_pref -= mn;
        nw_pref += mx;
        if (nw_pref >= h) return void(cout << ans + i << endl);
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
