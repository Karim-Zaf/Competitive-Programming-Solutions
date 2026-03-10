#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
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
 
const int N = 1010 ; 
set<array<int, 3>> s;
int a[N][N] ;
bool vis[N] ; 
vector<pair<int, int>> res;
int n;
 
void solve(){
    cin >> n;
    priority_queue<array<int,3>> pq ; 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (i != j) pq.push({a[i][j], i, j});
        }
    }
 
    int ans = 0;
    int cnt = 0 ; 
    while (!pq.empty() && cnt<n){
        auto [val,r,c] = pq.top() ;
        pq.pop() ; 
        if(vis[r] || vis[c]) continue ; 
 
        cnt++ ; 
        ans += val;
        
        if (r > c) swap(r, c);
        
        res.push_back({r, c});
 
        vis[c] = true ; 
 
 
        for(int i=1 ; i<=n ; i++){
 
            a[r][i] = max(a[r][i] , a[c][i]) ;
            a[i][r] = a[r][i] ;
            
            if(vis[i] || i==r) continue ; 
 
            pq.push({a[r][i],r,i}) ; 
            pq.push({a[i][r],i,r}) ; 
        }
        
    }
    cout << ans << endl;
    for (auto [x, y] : res) cout << x << " " << y << endl;
}
 
int main(){
    FAST
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}