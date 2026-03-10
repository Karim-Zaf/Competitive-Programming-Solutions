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

int binpow(int a, int k, int res = 1,int Mod = mod){
    while (k){
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod){ return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod){
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod){ return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod){
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

vector<int> graph[N], dp(N), sz(N), leafs(N);
int n;

void dfs(int curr, int parent = 0){
    sz[curr] = leafs[curr] = 1;
    if (graph[curr].size() != 1)leafs[curr] = 0;
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        sz[curr] += sz[child];
        leafs[curr] += sz[child];
    }
}

void dfs2(int curr, int parent = 0){
    dp[curr] = add(dp[parent], add(1,mult(2, sz[curr]-1)));
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs2(child, curr);
    }
}

void prep(){
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        dp[i] = 0;
    }
    graph[0].push_back(1);
}

void Solve(){
    cin >> n;
    prep();

    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        if (l) graph[i].push_back(l);
        if (r) graph[i].push_back(r);
    }

    dfs(1);
    dfs2(1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
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
