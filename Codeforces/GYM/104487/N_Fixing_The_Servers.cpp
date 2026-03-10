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
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 1e6 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
struct DSU{
    vector<int>  sz , parent ; 
    void init(int n){ for (int i = 0; i < n; i++){ parent.pb(i) ; sz.pb(1) ; } }
    int get(int a){return (parent[a] == a ? a : parent[a] = get(parent[a]));}
    bool unite(int a, int b){
        if ((a = get(a))==(b = get(b))) return false;
        if (sz[a]>sz[b]) swap (a,b) ; 
        parent[b] = a;
        sz[a] += sz[b]; 
        return true ; 
    }
    bool same_set(int a, int b){return get(a) == get(b);}
    int size(int a){ return sz[get(a)];}
};
 
vector<int> ind[N_Max], divisors[N_Max];
 
void solve(){
    int N, M;
    cin >> N >> M;
    DSU dsu; dsu.init(N + 5);
    vector<int> a(N + 1);
    for (int i = 1; i <= M; i++){
        ind[i].clear();
        divisors[i].clear();
    }
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= M; i++)
        for (int j = i; j <= M; j += i)
            divisors[j].pb(i);
    for (int i = 1; i <= N; i++)
        for (int d : divisors[a[i]]) ind[d].pb(i);
    ll ans = 0;
    for (int x = M; x >= 1; x--){
        if ((int)ind[x].size() == 0) continue;
        set<int> rep;
        for (int p : ind[x]) rep.insert(dsu.get(p));
        ans += (ll)(rep.size() - 1) * 1LL * x;
        for (int i = 1; i < (int)ind[x].size(); i++)
            dsu.unite(ind[x][0], ind[x][i]);
    }
    cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}