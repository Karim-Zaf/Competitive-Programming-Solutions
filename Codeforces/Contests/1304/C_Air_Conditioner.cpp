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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e9;
const ll inf = -1e9;
const int N_Max = 1e9;
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}


void solve(){
    ll N, start;
    cin >> N >> start;
    vector<tuple<ll, ll, ll>> v(N);
    for (ll i = 0; i < N; i++){
        ll t, l, r;
        cin >> t >> l >> r;;
        v[i] = {t, l, r};
    }
    sort(v.begin(), v.end());
    pair<ll, ll> prev = {start, start};
    ll time = 0 , translation = 0 ;
    for (ll i = 0; i < N; i++){
        ll t = get<0>(v[i]), l = get<1>(v[i]), r = get<2>(v[i]);
        pair<ll, ll> big = {prev.F - (t - time), prev.S + (t - time)};
        // translation += t-time ; 
        pair<ll, ll> inter = {max(inf, max(big.F, l)), min(sup, min(big.S, r))};
        if (inter.F > inter.S){
            no
            return;
        }
        prev = inter;
        time = t;
    }
    yes
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
 
/*
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused and organized
*/