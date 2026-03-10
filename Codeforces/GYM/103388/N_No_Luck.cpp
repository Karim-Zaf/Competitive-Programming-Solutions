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
const int N_Max = 3e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
vector<int> st[4 * N_Max];
int a[N_Max];
int N, Q;
 
void merge(int id, int l, int r){
	int i = 0, j = 0;
	while (i < (int)st[l].size() && j < (int)st[r].size()){
		if (st[l][i] < st[r][j]) st[id].pb(st[l][i++]);
		else st[id].pb(st[r][j++]);
	}
	while (i < (int)st[l].size()) st[id].pb(st[l][i++]);
	while (j < (int)st[r].size()) st[id].pb(st[r][j++]);
}
 
void build(int id, int ns, int ne){
	if (ns == ne){
		st[id].pb(a[ns]);
		return;
	}
	int mid = ns + (ne - ns) / 2;
	int lc = 2 * id;
	int rc = 2 * id + 1;
	build(lc, ns, mid);
	build(rc, mid + 1, ne);
	merge(id, lc, rc);
}
 
int query(int id, int ns, int ne, int l, int r, int x){
	if (ns > r || ne < l) return 0;
	if (ns >= l && ne <= r){
		int ind = lower_bound(st[id].begin(), st[id].end(), x) - st[id].begin();
		return (int)st[id].size() - ind;
	}
	int mid = ns + (ne - ns) / 2;
	int lc = 2 * id;
	int rc = 2 * id + 1;
	return query(lc, ns, mid, l, r, x) + query(rc, mid + 1, ne, l, r, x);
}
 
void solve(){
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];
	build(1, 1, N);
	for (int i = 1; i <= Q; i++){
		int l, x, len;
		cin >> l >> x >> len;
		if (a[l] >= x){
			cout << 0 << endl;
			continue;
		}
		cout << query(1, 1, N, l, l + len, x) << endl;
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