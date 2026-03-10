#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
 
 
void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> adj[N + 1], ans(N + 1);
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++){
        bool good = false;
        for (int child : adj[i])
            if (child == i + 1) good = true;
        if (i == N) good = true;
        cout << (good ? 0 : 1) << " ";
    }
    cout << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}