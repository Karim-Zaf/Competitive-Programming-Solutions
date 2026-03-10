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
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

ll pa[N_Max], pb[N_Max];
int a[N_Max], b[N_Max];
int nxt[N_Max][LOG];
ll res[N_Max][LOG];
int N, Q;

void solve(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	for (int i = 1; i <= N; i++) pa[i] = pa[i - 1] + a[i];
	for (int i = 1; i <= N; i++) pb[i] = pb[i - 1] + b[i];
	for (int i = 1; i <= N + 1; i++)
		for (int j = 0; j < LOG; j++) nxt[i][j] = N + 1;
	set<pair<ll, int>> st;
	for (int i = 1; i < N; i++){
		st.insert({pb[i - 1] - pa[i], i});
		ll l = pb[i] - pa[i + 1], r = pb[i] - pa[i];
		vector<pair<ll, int>> e;
		for (auto it = st.upper_bound({l, -1}); it != st.end(); it++){
			if ((*it).F > r) break;
			e.push_back(*it);
			int ind = (*it).S;
			nxt[ind][0] = i + 1;
			ll p2 = pa[i + 1] - pa[ind];
			res[ind][0] = p2;
		}
		for (auto x : e) st.erase(x);
	}
	for (int i = N - 1; i >= 1; i--){
		for (int j = 1; j < LOG; j++){
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			res[i][j] = res[i][j - 1] + res[nxt[i][j - 1]][j - 1];
		}
	}
	cin >> Q;
	for (int q = 1; q <= Q; q++){
		int l, r;
		cin >> l >> r;
		ll ans = a[l] - (pa[r] - pa[l - 1]);
		for (int i = 19; i >= 0; i--){
			if (nxt[l][i] > r) continue;
			ans += res[l][i];
			l = nxt[l][i];
		}
		ans += pb[r] - pb[l - 1];
		assert(ans >= 0);
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