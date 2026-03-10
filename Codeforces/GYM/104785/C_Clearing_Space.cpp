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

double dp[205][105];
bool vis[205][105];
double a[205];
int N, P;
double PI = 3.14159265;

double get(int i, int j){
	double x = abs(a[i] - a[j]);
	if (x >= 180) x = 360 - x;
	double tri = sin((x / 180) * PI) / 2;
	return 1000000 * tri;
}

double work(int i, int rem){
	if (rem == 0) return get(i, 1);
	if (i > N) return 0;
	if (vis[i][rem]) return dp[i][rem];
	vis[i][rem] = true;
	dp[i][rem] = 0;
	for (int j = i + 1; j <= N; j++){
		double curr = get(i, j);
		dp[i][rem] = max(dp[i][rem], curr + work(j, rem - 1));
	}
	return dp[i][rem];
}

void solve(){
	cin >> N >> P;
	for (int i = 1; i <= N; i++) cin >> a[i];
	double ans = 0;
	for (int i = 1; i <= N; i++){
		double val = a[1];
		for (int j = 2; j <= N; j++) a[j - 1] = a[j];
		a[N] = val;
		memset(vis, 0, sizeof(vis));
		double curr = work(1, P - 1);
		ans = max(ans, curr);
	}
	cout << ans << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout << fixed << setprecision(6);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}