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
 
vector<int> graph[N];
vector<int> a(N);
map<int,int> mp[N];
int ans = 0;
 
void merge(map<int, int>& a, map<int, int>& b){
    if (a.size() < b.size())a.swap(b);
    for (auto [val, occ] : b)a[val] += occ;
}
 
void factors(int n, map<int,int>& mp){
    int sum = 0;
    for (int i = 2; i * i <= n; i++){
        if (n % i) continue;
        while (n % i == 0){
            n /= i;
            mp[i]++;
        }
    }
    if (n > 1)mp[n]++;
}
 
void dfs(int curr = 1, int parent = 0){
    for (auto child : graph[curr]){
        if (child == parent)continue;
        dfs(child, curr);
        merge(mp[curr], mp[child]);
    }
    factors(a[curr], mp[curr]);
    ans += mp[curr].size() % 2;
    kar(mp[curr]);
}
 
void Solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
 
    dfs(1);
 
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