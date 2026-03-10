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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const int N_Max = 2e5 + 5;
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}


void solve(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    for (auto &x : v)
        cin >> x;
    ll ans = 0;
    for (ll mask = 0; mask < (1 << N); mask++){
        ll sum = 0;
        for (ll i = 0; i < N; i++){
            ll value = mask & (1 << i);
            if (value != 0)
                sum |= v[i];
        }
        ans += sum;
    }
    cout << ans << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
    FAST
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
 
/*
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/
