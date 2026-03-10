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
const int N_Max = 5e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

ll a[N_Max];
int N;

bool good(ll x){
	vector<int> vis(N), v;
	for (int i = 0; i < N; i++)
		if (a[i] <= x) v.pb(i);
	for (int ind : v){
		if (vis[ind]) continue;
		vis[ind]++;
		ll s = x + a[ind];
		int l = (ind - 1 + N) % N, r = (ind + 1) % N;
		while (l != r){
			if (s < min(a[l], a[r])) break;
			if (a[l] < a[r]){
				s += a[l];
				vis[l]++;
				l = (l - 1 + N) % N;
			}
			else{
				s += a[r];
				vis[r]++;
				r = (r + 1) % N;
			}
		}
		if (l == r && s >= a[l]) vis[l]++;
	}
	for (int i = 0; i < N; i++)
		if (!vis[i]) return false;
	return true;
}

void solve(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	ll l = 0, r = 1e13, ans = 1e13;
	while (l <= r){
		ll mid = l + (r - l) / 2;
		if (good(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
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