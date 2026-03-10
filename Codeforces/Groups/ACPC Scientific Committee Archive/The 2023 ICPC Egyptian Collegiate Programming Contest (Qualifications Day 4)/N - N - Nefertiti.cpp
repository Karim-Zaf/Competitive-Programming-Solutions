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
    int n, t, k;
    cin >> n >> t >> k;
    vector<int> time(n);
    vector<int> v(n);
    vector<int> w(n);
    for(auto &x : time) cin >> x;
    for(auto &x : v) cin >> x;
    for(auto &x : w) cin >> x;

    sort(time.begin(), time.end());

    vector<array<int, 2>> nw_vr;
    for(int i = 0; i < n; i++){
        int lo = 0, ro = n - 1, mx_t = -1; 
        while(lo <= ro) {
            int md = (lo + ro) /2;

            if(2 * time[md] + w[i] / k <= t) {
                mx_t = md;
                lo =  md + 1;
            }else 
                ro = md - 1;
        }
        
        if(mx_t == -1) continue;
        nw_vr.push_back({mx_t, v[i]});
    }
    sort(nw_vr.begin(), nw_vr.end());
    
    priority_queue<int, vector<int>, greater<>> pq;
    
    ll ans = 0;
    for(auto [r, value] : nw_vr) {
        if(pq.size() < r + 1) {
            pq.push(value);
            ans += value;
        }else if(!pq.empty() && pq.top() < value) {
            ans -= pq.top();
            pq.pop();
            pq.push(value);
            ans += value;
        }
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
    // cin >> tc;
    while (tc--) solve();
    return 0;
}