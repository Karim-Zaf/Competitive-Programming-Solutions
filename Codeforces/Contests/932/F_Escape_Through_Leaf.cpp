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

struct Line{
    mutable ll a, b, p;
    bool operator<(const Line& o) const{ return a < o.a; }
    bool operator<(ll x) const{ return p < x; }
};

struct CHT : multiset<Line, less<>>{
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = 2e18;

    ll div(ll a, ll b){ // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y){
        if (y == end()){
            x->p = inf;
            return false;
        }
        if (x->a == y->a) x->p = x->b > y->b ? inf : -inf;
        else x->p = div(y->b - x->b, x->a - y->a);
        return x->p >= y->p;
    }

    void add(ll k, ll m){
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    ll query(ll x){
        assert(!empty());
        auto l = *lower_bound(x);
        return l.a * x + l.b;
    }
};

int a[N], b[N];
int dp[N];
int n;
CHT Convex_Hull[N];
vector<int> graph[N], sz(N, 1);

void merge(CHT& a, CHT& b){
    if (a.size() < b.size()) swap(a, b);

    for (auto p : b){ a.add(p.a, p.b); }
}

void dfs(int curr, int parent = -1){
    for (auto& child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        merge(Convex_Hull[curr], Convex_Hull[child]);
    }

    if (graph[curr].size() > 1 || curr == 1){ dp[curr] = -Convex_Hull[curr].query(a[curr]); }
    Convex_Hull[curr].add(-b[curr], -dp[curr]);
}

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
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
