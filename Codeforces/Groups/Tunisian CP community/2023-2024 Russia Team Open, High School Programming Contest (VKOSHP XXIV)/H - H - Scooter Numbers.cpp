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
const int N_Max = 1005;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

ll ways[N_Max][N_Max];
ll sum_wys[N_Max];
ll fact[N_Max];
int N;

ll C(int N, int K){
	if (K > N) return 0;
	return fact[N] * inv(fact[K] * fact[N - K] % mod) % mod;
}

void solve(){
	cin >> N;
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * 1LL * i % mod;
	sum_wys[0] = 1;
	for (int i = 1; i <= N; i++)
		for (int sum = i; sum <= N; sum++)
			sum_wys[sum] = (sum_wys[sum] + sum_wys[sum - i]) % mod;
	for (int i = 1; i <= N + 1; i++) ways[0][i] = 1;
	for (int sum = 1; sum <= N; sum++){
		for (int x = 1; x <= N + 1; x++){
			ways[sum][x] = sum_wys[sum];
			if (x <= sum) ways[sum][x] = (ways[sum][x] - sum_wys[sum - x] + mod) % mod;
		}
	}
	ll ans = 0;
	for (int mex = 1; mex <= N + 1; mex++){
		int rest = N - mex * (mex - 1) / 2;
		if (rest >= 0) ans = (ans + ways[rest][mex] * 1LL * mex % mod) % mod;
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