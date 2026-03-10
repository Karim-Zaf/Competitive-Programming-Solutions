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
const int N_Max = 2e6 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a, b); }
    void init(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

Seg<ll> st;
bool have[N_Max];
ll ans[N_Max];
multiset<ll> val[N_Max];

void update(int u){
	while (u > 0 && have[u]){
		ans[u] = *val[u].rbegin();
		if (have[2 * u]) ans[u] = max(ans[u], ans[2 * u] + *val[u].rbegin());
		if (have[2 * u + 1]) ans[u] = max(ans[u], ans[2 * u + 1] + *val[u].rbegin());
		ans[u] = max(0LL, ans[u]);
		st.upd(u, ans[u]);
		u /= 2;
	}
}

void solve(){
	int N;
	cin >> N;
	st.init(1e6 + 5);
	for (int q = 1; q <= N; q++){
		int t, Node;
		ll b;
		cin >> t >> Node >> b;
		if (t == 1){
			val[Node].insert(b);
			have[Node] = true;
			update(Node);
		}
		else{
			val[Node].erase(val[Node].find(b));
			if (val[Node].empty()){
				ans[Node] = 0;
				st.upd(Node, 0);
				have[Node] = false;
				Node /= 2;
			}
			update(Node);
		}
		cout << st.query(1, 1e6) << endl;
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