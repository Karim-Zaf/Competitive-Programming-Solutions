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
const int N_Max = 2e3 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
double a[N_Max], dp[N_Max][105], pref1[N_Max], pref2[N_Max], cost[N_Max][N_Max];
int vis[N_Max][105];
int N, M, K;
double S;
 
double work(int i, int rem){
	if (rem < 0) return 1e18;
	if (i > N + M) return 0;
	double &ret = dp[i][rem];
	if (vis[i][rem]) return ret;
	vis[i][rem]++;
	ret = 1e18;
	for (int x = 0; x <= N + M; x++){
		if (i + x > N + M) break;
		ret = min(ret, cost[i][i + x] + work(i + x + 1, rem - 1));
	}
	return ret;
}
 
double cnt(double mid, int l, int r){
	double ret = pref2[r] - pref2[l - 1] - 2 * mid * (pref1[r] - pref1[l - 1]) + (r - l + 1) * mid * mid;
	return ret;
}
 
double ts(int i, int j){
	double l = a[i], r = a[j];
	while (r - l > 0.0000001){
		double mid1 = l + (r - l) / 3.0;
		double mid2 = l + 2 * (r - l) / 3.0;
		double c1 = cnt(mid1, i, j), c2 = cnt(mid2, i, j);
		if (c1 < c2) r = mid2;
		else l = mid1;
	}
	return cnt(l, i, j);
}
 
void solve(){
	cin >> N >> M >> K >> S;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = N + 1; i <= N + M; i++) cin >> a[i];
	sort(a + 1, a + N + M + 1);
	for (int i = 1; i <= N + M; i++) pref1[i] = pref1[i - 1] + a[i];
	for (int i = 1; i <= N + M; i++) pref2[i] = pref2[i - 1] + a[i] * a[i];
	for (int l = 1; l <= N + M; l++){
		for (int r = l; r <= N + M; r++){
			cost[l][r] = ts(l, r);
		}
	}
	double ans = (N + M) * (S / 2.0) * (S / 2.0) + work(1, K);
	cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout << fixed << setprecision(10);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}