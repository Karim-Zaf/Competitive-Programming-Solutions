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
	int N, K;
	string a, b;
	cin >> N >> K >> a >> b;
	array<string, 2> s = {a, b};
	array<pair<int, int>, 2> ans;
	for (int rep = 0; rep < 2; rep++){
		pair<int, int> p = {2e9, -1};
		for (int i = 0; i < N; i++){
			int mx = 0; 
			for (int j = 0; j < N; j++){
				if (s[rep][j] != '0') mx = max(mx, abs(i - j));
				if (s[rep ^ 1][j] != '0') mx = max(mx, K + i + 1 + j + 1);
			}
			if (mx < p.F) p = {mx, i};
		}
		ans[rep] = p;
	}
	if (ans[0].F < ans[1].F){
		cout << ans[0].F << endl;
		cout << 2 << " " << ans[0].S + 1 << endl;
	}
	else{
		cout << ans[1].F << endl;
		cout << 1 << " " << ans[1].S + 1 << endl;
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