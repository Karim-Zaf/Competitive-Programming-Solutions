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

const int LG = 22;

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    int q;
    cin >> q;
    vector<int> ans(q);
    vector<pair<int,int>> queries[n + 1];
    vector<pair<int,int>> base(LG);
    for (int i = 0, l, r; i < q; i++){
        cin >> l >> r;
        queries[r].pb({l, i});
    }

    auto insert = [&](vector<int>& base, int x){
        for (int bit = LG - 1; bit >= 0; bit--){
            if ((x & 1 << bit) == 0) continue;
            if (!base[bit])return void(base[bit] = x);
            x ^= base[bit];
        }
    };

    auto get_max = [&](vector<pair<int,int>>& base,int lef){
        int ans = 0;
        for (int bit = LG - 1; bit >= 0; bit--){
            if (ans & 1 << bit) continue ;
            auto [val, indx] = base[bit];
            if (indx >= lef)ans ^= val;
        }
        return ans;
    };

    for (int i = 1; i <= n; i++){
        queue<pair<int,int>> q;
        q.push({v[i], i});

        while (!q.empty()){
            auto [val, indx] = q.front();
            q.pop();
            for (int bit = LG - 1; bit >= 0; bit--){
                if (((1 << bit) & val) == 0) continue;
                if (base[bit].F == 0){
                    base[bit] = {val, indx};
                    break;
                }
                if (indx > base[bit].S){
                    q.push(base[bit]);
                    base[bit] = {val, indx};
                    break;
                }
                val ^= base[bit].F;
            }
        }

        for (auto [lef, indx] : queries[i])
            ans[indx] = get_max(base, lef);
    }
    for (auto x : ans) cout << x << endl;
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
