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

const int N = 2e5 + 30, MOD = 1e9 + 7, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> graph[N], depth(N);
set<int> s [N];
int up[N][30];

void dfs(int parent) {
    for (int i = 1; i < 28; i++)
        up[parent][i] = up[up[parent][i - 1]][i - 1];

    for (auto child: graph[parent]) {
        if (up[parent][0] == child)continue;
        depth[child] = depth[parent] + 1;
        up[child][0] = parent;
        dfs(child);
    }
}

int Binary_Lifting(int a, int k) {
    for (int i = 28; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    return a;
}

int Lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);

    int k = depth[a] - depth[b];
    a = Binary_Lifting(a, k);
    if (a == b) return a;

    for (int i = 28; i >= 0; i--) {
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}

void Solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        s[u].insert(v);
        s[v].insert(u);
    }
    dfs (1);
    while (q--){
        int k ;
        cin >> k ;
        vector<pair<int,int>> vp ;
        for (int i= 0,x ; i<k ;i++){
            cin >> x;
            vp.pb({depth[x],x});
        }
        sort (rall(vp));
        int curr = vp.front().S;

        bool flag = true;
        for (int i= 0 ; i<k ;i++){
            curr = Lca (curr,vp[i].S);
            if (curr==vp[i].S)continue;
            if (s[curr].find(vp[i].S)==s[curr].end()){
                flag = false ;
                break;
            }
        }
        cout << (flag ? "YES": "NO") << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt", "r", stdin);
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}