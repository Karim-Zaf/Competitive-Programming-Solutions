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
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<ll> pref[N_Max];
ll sub[N_Max];

void solve(){
    int N, Q;
    cin >> N;
    vector<int> a(N + 1), c(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++){
        cin >> c[i];
        if (pref[c[i]].size() == 0) pref[c[i]].pb(a[i]);
        else pref[c[i]].pb(pref[c[i]].back() + a[i]);
    }
    cin >> Q;
    ll tot = 0;
    for (int i = 1; i <= Q; i++){
        int t, col;
        ll val;
        cin >> t >> col >> val;
        if (t == 1){
            tot += val;
            sub[col] += val;
            continue;
        }
        int l = 0, r = pref[col].size() - 1, ans = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            ll add = (mid + 1) * (tot - sub[col]) + pref[col][mid];
            if (add > val) r = mid - 1;
            else{
                ans = mid + 1;
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
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