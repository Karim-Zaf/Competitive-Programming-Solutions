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
int dp[N][3];
string ans;

int work(int u, int nxt){
    int& ret = dp[u][nxt];
    if (ret == 0) return 0;
    if (ans[u] != 'z')return ret;

    ans[u] = char(nxt + 'a');
    ret = 1;
    for (int j = 0; j < 3; j++)if (j != nxt) dp[u][j] = 0;

    for (auto child : graph[u]){
        int cnt = 0, val = 0;

        dp[child][nxt] = 0;
        for (int i = 0; i < 3; i++){
            cnt += dp[child][i];
            if (dp[child][i]) val = i;
        }
        if (cnt == 1) work(child, val);
    }

    return ret;
}

void Solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i++) ans += "z";

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = 1;

    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int i = 1; i <= n; i++){ for (int j = 0; j < 3; j++){ if (work(i, j)){ break; } } }

    reverse(all(ans));
    ans.pop_back();
    reverse(all(ans));
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
