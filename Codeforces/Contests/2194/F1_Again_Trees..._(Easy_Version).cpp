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

int n, k;
vector<int> graph[N];
map<int,int> dp[N];
vector<int> pref(N), a(N);
vector<int> b;
int ans = 0;

bool appartien(int msk){
    for (auto x : b){ if (msk == x) return true; }
    return false;
}

void dfs(int curr, int parent = -1){
    pref[curr] = a[curr];
    for (auto child : graph[curr]){
        if (child == parent) continue;
        dfs(child, curr);
        pref[curr] ^= pref[child];
    }

    // leave
    for (auto child : graph[curr]){
        if (child == parent) continue;
        for (auto [msk1,value1] : map(dp[curr])){
            for (auto& [msk2 , value2] : dp[child]){
                dp[curr][msk1 ^ msk2] = add(dp[curr][msk1 ^ msk2], mult(value1, value2));
            }
        }
        for (auto& [msk2 , value2] : dp[child]){ dp[curr][msk2] = add(dp[curr][msk2], value2); }
    }

    // take ;
    int take_it = 0;
    for (auto [msk,value] : dp[curr]){
        if (appartien(msk ^ pref[curr]))
            take_it = add(take_it, value);
    }
    if (appartien(pref[curr]))take_it = add(take_it, 1);

    if (take_it) dp[curr][pref[curr]] = add(dp[curr][pref[curr]], take_it);
    ans = take_it;
}

void Solve(){
    cin >> n >> k;
    b.resize(k);
    for (int i = 1; i <= n; i++) dp[i].clear();
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (auto& x : b) cin >> x;

    dfs(1);

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
