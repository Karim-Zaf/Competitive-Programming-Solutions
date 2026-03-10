#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define int ll
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> adj[N_Max];
int cntStoneHouses[N_Max];
int T[N_Max];
int a[N_Max];
int N, C;
 
array<int, 4> dfs(int Node){
    if (adj[Node].empty()){
        cntStoneHouses[Node] = T[Node] == 2;
        return T[Node] == 3 ? array<int, 4>{C - a[Node], 0, 0, 0} : array<int, 4>{0, a[Node], 0, 0};
    }
 
    int remSafePlaces = 0, maximumCnt = 0, safePlaces = 0, ret = 0;
    for (int child : adj[Node]){
        array<int, 4> res = dfs(child);
 
        int oldMax = maximumCnt;
        int diff = abs(maximumCnt - res[1]);
 
        remSafePlaces += res[0];
        maximumCnt = max(maximumCnt, res[1]);
        safePlaces += res[2];
        ret += res[3];
        
        if (oldMax >= res[1]) safePlaces += cntStoneHouses[child] * diff;
        else safePlaces += cntStoneHouses[Node] * diff;
        
        cntStoneHouses[Node] += cntStoneHouses[child];
    }
 
    int rabbitsToMove = min(a[Node], remSafePlaces);
    remSafePlaces -= rabbitsToMove;
    a[Node] -= rabbitsToMove;
 
    rabbitsToMove = min(a[Node], safePlaces);
    safePlaces -= rabbitsToMove;
    a[Node] -= rabbitsToMove;
 
    if (cntStoneHouses[Node] > 0){
        maximumCnt += (a[Node] + cntStoneHouses[Node] - 1) / cntStoneHouses[Node];
        safePlaces += (cntStoneHouses[Node] - a[Node] % cntStoneHouses[Node]) % cntStoneHouses[Node];
    }
    else ret += a[Node];
 
    return array<int, 4>{remSafePlaces, maximumCnt, safePlaces, ret};
}
 
void solve(){
    cin >> N >> C;
    for (int i = 1; i <= N; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> T[i];
    array<int, 4> ans = dfs(1);
    cout << ans[1] + ans[3] << endl;
}
 
int32_t main(){
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