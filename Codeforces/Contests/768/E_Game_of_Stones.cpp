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

const int M = 65;
map<int,int> dp[M];
int work(int x, int mask = 0){
    if (x < 0) return INF;
    if (dp[x].count(mask)) return dp[x][mask];
    int& ret = dp[x][mask];

    set<int> s;

    for (int i = 1; i <= x; i++){
        if (mask & (1 << i)) continue;
        s.insert(work(x - i, mask ^ (1 << i)));
    }

    ret = s.size();

    int indx = 0;
    for (auto x : s){
        if (x != indx) return ret = indx;
        indx++;
    }

    return ret;
}

void Solve(){
    int ans = 0, n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    for (auto x : v) ans ^= work(x);

    cout << (ans == 0 ? "YES" : "NO");
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
