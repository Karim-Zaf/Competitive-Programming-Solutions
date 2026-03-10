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


void solve(){
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N + 1);
    vector<ll> pref(N), suff(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    pref[0] = a[0];
    for (int i = 1; i < N; i++) pref[i] = pref[i - 1] + a[i];
    suff[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--) suff[i] = suff[i + 1] + a[i];
    reverse(suff.begin(), suff.end());
    for (int i = 1; i <= Q; i++){
        ll s;
        cin >> s;
        int l = lower_bound(pref.begin(), pref.end(), s) - pref.begin();
        int k = lower_bound(suff.begin(), suff.end(), s) - suff.begin();
        int r = N - 1 - k;
        if (l > r) cout << 0 << endl;
        else if (l < r){
            int ans = r - l + 1;
            if (pref[l] == s) ans--;
            if (suff[k] == s) ans--;
            cout << ans << endl;
        }
        else{
            assert(l == r);
            ll p = (l == 0 ? 0 : pref[l - 1]);
            ll ss = (k == 0 ? 0 : suff[k - 1]);
            ll x = abs(p - ss);
            ll val = a[l] - x;
            s -= max(p, ss);
            if (val == s) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
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