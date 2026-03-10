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
const double eps = 0.000001;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
void solve(){
	int N;
	double T;
	cin >> N >> T;
	vector<double> p, np;
	for (int i = 0; i < N; i++){
		char c;
		double x;
		cin >> c >> x;
		if (c == 'P') p.pb(x);
		else np.pb(x);
	}
	double ans = 0;
	while (!p.empty() || !np.empty()){
		if (!p.empty()){
			vector<double> new_p;
			double speed = T / (double)p.size();
			double mn = 1e18;
			for (double x : p) mn = min(mn, x / speed);
			ans += mn;
			for (double x : p){
				double curr = x - speed * mn;
				if (curr > eps) new_p.pb(curr);
			}
			swap(p, new_p);
			continue;
		}
		if (!np.empty()){
			vector<double> new_np;
			double speed = T / (double)np.size();
			double mn = 1e18;
			for (double x : np) mn = min(mn, x / speed);
			ans += mn;
			for (double x : np){
				double curr = x - speed * mn;
				if (curr > eps) new_np.pb(curr);
			}
			swap(np, new_np);
			continue;
		}
		vector<double> new_p, new_np;
		double speedp = (T * 0.75) / (double)p.size();
		double speednp = (T * 0.75) / (double)np.size();
		double mn = 1e18;
		for (double x : p) mn = min(mn, x / speedp);
		for (double x : np) mn = min(mn, x / speednp);
		ans += mn;
		for (double x : p){
			double curr = x - speedp * mn;
			if (curr > eps) new_p.pb(curr);
		}
		swap(p, new_p);
		for (double x : np){
			double curr = x - speednp * mn;
			if (curr > eps) new_np.pb(curr);
		}
		swap(np, new_np);
	}
	cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout << fixed << setprecision(4);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}