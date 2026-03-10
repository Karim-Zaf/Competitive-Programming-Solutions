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

ll a[N_Max], pref[2][N_Max];
int l[N_Max], r[N_Max];
int N;

void prep_nxt(){
    vector<int> stack;
    for (int i = 1; i <= N; i++) r[i] = N;
    for (int i = 1; i <= N; i++){
        while (!stack.empty() && a[stack.back()] < a[i]){
            r[stack.back()] = i - 1;
            stack.pop_back();
        }
        stack.pb(i);
    }
}
 
void prep_prev(){
    vector<int> stack;
    for (int i = 1; i <= N; i++) l[i] = 1;
    for (int i = N; i >= 1; i--){
        while (!stack.empty() && a[stack.back()] < a[i]){
            l[stack.back()] = i + 1;
            stack.pop_back();
        }
        stack.pb(i);
    }
}

void solve(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++)
		pref[0][i] = (pref[0][i - 1] + (a[i] + mod) % mod) % mod;
	for (int i = 1; i <= N; i++){
		ll x = (a[i] + mod) % mod * 1LL * i % mod;
		pref[1][i] = (pref[1][i - 1] + x) % mod;
	}
	prep_nxt();
	prep_prev();
	ll ans = 0;
	for (int i = 1; i <= N; i++){
		ll left = 0, right = 0;
		if (i - 1 >= l[i]){
			ll sum = (pref[0][i - 1] - pref[0][l[i] - 1] + mod) % mod;
			left = (pref[1][i - 1] - pref[1][l[i] - 1] + mod) % mod;
			left = (left - sum * 1LL * (l[i] - 1) % mod + mod) % mod;
			left = left * 1LL * (r[i] - i + 1) % mod;
		}
		if (i + 1 <= r[i]){
			ll sum = (pref[1][r[i]] - pref[1][i] + mod) % mod;
			right = (pref[0][r[i]] - pref[0][i] + mod) % mod * 1LL * (r[i] + 1) % mod;
			right = (right - sum + mod) % mod;
			right = right * 1LL * (i - l[i] + 1) % mod;
		}
		ll x = a[i] * 1LL * (r[i] - i + 1) % mod * 1LL * (i - l[i] + 1) % mod;
		ll curr = (left + right + x) % mod;
		ans = (ans + curr) % mod;
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