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
	bitset<300005> bs;
	vector<ll> dp(N + 1);
	vector<ll> pref(N + 1);
	vector<ll> suff(N + 2);
	vector<array<ll, 3>> a(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> a[i][2] >> a[i][1] >> a[i][0];
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] + a[i][2];
	for (int i = N; i >= 1; i--) suff[i] = max(suff[i + 1], a[i][1]);
	bs[0] = 1;
	for (int i = 1; i <= N; i++){
		bs |= (bs << a[i][2]);
		ll l = 1, r = 3e5; dp[i] = 1e15;
		while (l <= r){
			ll L = l + (r - l) / 2;
			ll lo = 0, ro = L, val = 1e15;
			while (lo <= ro){
				ll x = lo + (ro - lo) / 2;
				ll ind = bs._Find_next(x);
				if (ind > L) ro = x - 1;
				else{
					val = ind;
					lo = x + 1;
				}
			}
			if (val <= L && pref[i] - val <= L){
				dp[i] = L;
				r = L - 1;
			}
			else l = L + 1;
		}
	}
	for (int q = 1; q <= Q; q++){
		ll L;
		cin >> L;
		ll l = 1, r = 1e15, ans = -1;
		while (l <= r){
			ll mid = l + (r - l) / 2;
			array<ll, 3> p = {mid, (ll)1e15, (ll)1e15};
			ll ind = upper_bound(a.begin() + 1, a.end(), p) - a.begin();
			ll rem = L - (ind > N ? 0 : pref[N] - pref[ind - 1]);
			if (dp[ind - 1] <= rem && suff[ind] <= mid){
				ans = mid;
				r = mid - 1;	
			}
			else l = mid + 1;
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