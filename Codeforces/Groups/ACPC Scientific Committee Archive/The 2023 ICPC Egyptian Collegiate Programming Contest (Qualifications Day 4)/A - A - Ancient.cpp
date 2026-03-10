#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
const ll mod = 998244353;
const int N_Max = 2e5 + 5;
const int Nax = 15;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
void solve() {  
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    vector<ll> pref(n + 1);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n; i++) 
        pref[i + 1] = pref[i] + a[i];
    ll ans = 0;
    for(int l = 1; l <= n; l++){
        int r = upper_bound(pref.begin(), pref.end(), pref[l - 1] + w) - pref.begin();
        r--;
        if(r >= l)
            ans = max(ans, pref[r] - pref[l - 1]);
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