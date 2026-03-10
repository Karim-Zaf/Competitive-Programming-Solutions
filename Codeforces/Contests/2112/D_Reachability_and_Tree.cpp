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

vector<int> graph[N], depth(N);
vector<pair<int,int>> ans;
int leaf;

void dfs(int curr, int parent = 0, int indx = 0){
    depth[curr] = depth[parent] + 1;

    for (auto child : graph[curr]){
        if (child == parent) continue;
        if (!indx){ ans.pb({curr, child}); }
        else{ ans.pb({child, curr}); }
        dfs(child, curr, indx ^ 1);
    }

    if (depth[curr] > depth[leaf]) leaf = curr;
}

void Solve(){
    int n;
    cin >> n;
    leaf = -1;
    ans.clear();
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int ok = 0 ;
    for (int i = 1; i <= n; i++){
        if (graph[i].size() == 2){
            int one = graph[i][0];
            int two = graph[i][1];
            int west = i;

            ans.pb({one, west});
            ans.pb({west, two});
            dfs(one, west);
            dfs(two, west, 1);

            ok = 1 ;
            break;
        }
    }

    if (!ok) return void(cout << "NO\n");

    cout << "YES\n";
    for (auto [u,v] : ans)
        cout << u << " " << v << "\n";
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
