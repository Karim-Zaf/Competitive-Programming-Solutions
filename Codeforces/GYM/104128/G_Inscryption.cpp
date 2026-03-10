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
    int N;
    cin >> N;
    vector<ll> a(N + 1), pref(N + 1), suff(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    ll cnt = 1;
    pref[0] = 1;
    for (int i = 1; i <= N; i++){
        if (a[i] == 1) cnt++;
        pref[i] += pref[i - 1];
        if (a[i] > 0) pref[i]++;
        else pref[i]--;
    }
    suff[N] = pref[N];
    for (int i = N - 1; i >= 0; i--)
        suff[i] = min(suff[i + 1], pref[i]);
    pair<ll, ll> ans = {-1, -1};
    if (suff[0] >= 1){
        ll g = gcd(cnt, pref[N]);
        ans = {cnt / g, pref[N] / g};
    }
    ll zero = 0;
    for (int i = 1; i <= N; i++){
        if (a[i] == 0) zero++, cnt++;
        if (pref[i] + 2 * zero <= 0){
            cout << -1 << endl;
            return;
        }
        if (suff[i] + 2 * zero >= 1){
            ll x = cnt, y = pref[N] + 2 * zero;
            ll g = gcd(x, y);
            x /= g, y /= g;
            if (ans.F == -1 || x * ans.S > y * ans.F){
                ans = {x, y};
            }
        }
    }
    if (ans.F == -1) cout << -1 << endl;
    else cout << ans.F << " " << ans.S << endl;
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