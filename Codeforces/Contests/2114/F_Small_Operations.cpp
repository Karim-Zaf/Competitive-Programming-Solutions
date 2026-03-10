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

const int N = 1e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> dv[N], dp(N);

void sieve(){
    for (int i = 2; i < N; i++){
        for (int j = i; j < N; j += i)
            dv[j].pb(i);
        reverse(all(dv[i]));
    }
}

int a, b, k;
int work(int x){
    dp[1] = INF;
    for (auto d : dv[x]){ dp[d] = INF; }

    dp[x] = 0;
    for (auto d : dv[x]){ for (auto z : dv[d]){ if (z <= k){ dp[d / z] = min(dp[d / z], dp[d] + 1); } } }
    return dp[1];
}

void Solve(){
    cin >> a >> b >> k;
    int g = __gcd(a, b);
    a /= g;
    b /= g;

    int ans = work(a) + work(b);
    cout << (ans >= INF ? -1 : ans) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
