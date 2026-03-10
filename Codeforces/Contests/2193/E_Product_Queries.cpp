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

vector<int> divi[N];

void sieve(){
    vector<int> visited(N);
    for (int i = 2; i < N; i++){
        for (int j = i; j < N; j += i)
            divi[j].pb(i);;
    }
}

void Solve(){
    int n;
    cin >> n;
    vector<int> dp(n + 2, INF), v(n);
    for (auto& x : v)cin >> x;
    for (auto& x : v)dp[x] = 1;

    set<int> s;
    for (int i = 2; i <= n; i++){ for (auto d : divi[i]){ dp[i] = min(dp[i], dp[d] + dp[i / d]); } }
    for (int i = 1; i <= n; i++) cout << (dp[i] == INF ? -1 : dp[i]) << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}
