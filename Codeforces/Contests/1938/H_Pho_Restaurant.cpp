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
    vector<ll> pref(N + 1);
    vector<ll> one(N + 1), zero(N + 1);
    ll mn0 = 2e9, mn1 = 2e9;
    bool good0 = false, good1 = false;
    for (int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for (char c : s){
            one[i] += (c == '1');
            zero[i] += (c == '0');
        }
        if (!one[i]) good0 = true, mn0 = min(mn0, zero[i]);
        if (!zero[i]) good1 = true, mn1 = min(mn1, one[i]);
    }
    for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] + min(zero[i], one[i]);
    if (good0 && good1){
        cout << pref[N] << endl;
        return;
    }
    if (good0){
        bool good = false;
        ll ans = 1e15;
        for (int i = 1; i <= N; i++){
            if (!one[i] || !zero[i]) continue;
            good = true;
            ll curr = min(zero[i], one[i] + mn0) + pref[i - 1] + pref[N] - pref[i];
            ans = min(ans, curr);
        }
        cout << (good ? ans : 0) << endl;
        return;
    }
    if (good1){
        bool good = false;
        ll ans = 1e15;
        for (int i = 1; i <= N; i++){
            if (!one[i] || !zero[i]) continue;
            good = true;
            ll curr = min(one[i], zero[i] + mn1) + pref[i - 1] + pref[N] - pref[i];
            ans = min(ans, curr);
        }
        cout << (good ? ans : 0) << endl;
        return;
    }
    ll ans = 2e9;
    int ind0 = 1, ind1 = 1;
    mn0 = zero[1], mn1 = one[1];
    for (int i = 1; i <= N; i++){
        ans = min(ans, zero[i] + mn1 + pref[N] - pref[i] + pref[ind1 - 1] + pref[i - 1] - pref[ind1]);
        ans = min(ans, one[i] + mn0 + pref[N] - pref[i] + pref[ind0 - 1] + pref[i - 1] - pref[ind0]);
        if (zero[i] < mn0) ind0 = i;
        if (one[i] < mn1) ind1 = i;
        mn0 = min(mn0, zero[i]);
        mn1 = min(mn1, one[i]);
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