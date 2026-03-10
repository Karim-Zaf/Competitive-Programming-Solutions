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
const int N_Max = 1e5 + 5;
const int Nax = 1e6 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


void solve(){
    ll N, B;
    cin >> N >> B;
    vector<pair<ll, ll>> a(N);
    vector<ll> ans(N), b(N);
    for (ll i = 0; i < N; i++){
        ll p;
        cin >> p;
        b[i] = p;
        a[i] = {p, i};
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < N; i++){
        if (a[i].F == 0) continue;
        ll l = (a[i].S == 0 ? N - 1 : a[i].S - 1);
        ll r = (a[i].S == N - 1 ? 0 : a[i].S + 1);
        if (a[i].F > b[l] && a[i].F > b[r]){
            ans[a[i].S] = max(ans[l], ans[r]) + B;
            continue;
        }
        if (a[i].F > b[l]) ans[a[i].S] = ans[l] + B;
        else if (a[i].F > b[r]) ans[a[i].S] = ans[r] + B;
        else ans[a[i].S] = B;
    }
    for (int i = 0; i < N - 1; i++)
        cout << ans[i] << " ";
    cout << ans[N - 1] << endl;
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