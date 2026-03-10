#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define int ll
#define pb(n) push_back(n)

const int N_Max = 2e5 + 5;

void solve(){
    int N, M;
    cin >> N >> M;
    array<int, 3> e;
    vector<int> best(N + 1);
    vector<pair<int, int>> adj[N + 1];
    for (int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) e = {u, v, w};
        else adj[v].push_back({w, u});
    }
    ll ans = 0;
    for (int i = 2; i <= N; i++){
        best[i] = 1e15;
        for (auto [w, p] : adj[i]) best[i] = min(best[i], w);
        ans += best[i];
    }
    auto [u, v, w] = e;
    if (v == 1){
        cout << ans << endl;
        return;
    }
    vector<int> dp(N + 1);
    for (int i = 2; i <= N; i++){
        dp[i] = 1e15;
        if (i == v) continue;
        for (auto [weight, p] : adj[i])
            dp[i] = min(dp[i], dp[p] + weight - best[i]);
    }
    cout << min(ans, ans + w - best[v] + dp[u]) << endl;
}

int32_t main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
