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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

/*
 * 1st step: elimanate doubles
 * 2nd step:
 *      every undirected edge is unique
 *      check if every component is cyclic and simple ( every node has 2 edges )
 *      if not answer -1
 *      if yes just run dfs
 */

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    multiset<pair<int, int>> ans, ans_dfs;

    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++){
        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        pair p = {mn, mx};
        if (mp[p]){
            ans.insert({mx, mn});
            ans.insert({mn, mx});
            mp[p] = 0;
        }
        else mp[p] = 1;
    }
    vector<vector<int>> graph(n + 1);

    for (auto [p , occ] : mp){
        if (!occ) continue;
        auto [u,v] = p;

        if (u == v){
            ans.insert({u, v});
            continue;
        }

        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int i = 1; i <= n; i++){
        int sz = graph[i].size();
        if (sz % 2) return void(cout << -1 << endl);
    }

    vector<int> vis(n + 1);
    auto dfs = [&](auto& self, int curr)-> void{
        vis[curr] = 1;
        while (graph[curr].size()){
            int child = graph[curr].back();
            pair p1 = {child, curr};
            pair p2 = {curr, child};
            graph[curr].pop_back();
            if (ans_dfs.find(p1) != ans_dfs.end() || ans_dfs.find(p2) != ans_dfs.end()) continue;
            ans_dfs.insert({curr, child});
            self(self, child);
        }
    };
    for (int i = 1; i <= n; i++){ if (!vis[i])dfs(dfs, i); }

    vector<int> ret;
    for (auto x : ans_dfs) ans.insert(x);
    for (int i = 0; i < n; i++){
        auto it = ans.find({a[i], b[i]});
        if (it != ans.end()){ ans.erase(ans.find({a[i], b[i]})); }
        else{
            ans.erase(ans.find({b[i], a[i]}));
            ret.push_back(i);
            swap(a[i], b[i]);
        }
    }

    cout << ret.size() << endl;
    for (auto& x : ret) cout << ++x << " ";
    cout << endl;
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
