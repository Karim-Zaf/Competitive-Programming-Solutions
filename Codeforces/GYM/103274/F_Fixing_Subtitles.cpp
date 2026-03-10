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
 
pair<int, int> vec[5005];
vector<string> a[5005];
int N;
 
int get(int h, int m, int s, int ms){
	return h * 3600000 + m * 60000 + s * 1000 + ms;
}
 
string convert(int x){
	string ret = "";
	for (int d : {3600000, 60000, 1000}){
		int val = x / d;
		x %= d;
		string s = to_string(val);
		while (s.size() < 2) s = "0" + s;
		ret += s;
		ret += ":";
	}
	ret.pop_back();
	ret += ",";
	string s = to_string(x);
	while (s.size() < 3) s = "0" + s;
	ret += s;
	return ret;
}
 
void solve(){
	char c;
	int x, y;
	cin >> N >> x >> c >> y;
	int delay = x * 1000 + y;
	for (int i = 1; i <= N; i++){
		vector<int> v;
		string ss;
		cin >> ss;
		for (int j = 0; j < 2; j++){
			int h, m, s, ms;
			char c;
			cin >> h >> c >> m >> c >> s >> c >> ms;
			int x = get(h, m, s, ms);
			v.pb(x);
			if (j == 0) cin >> ss;
		}
		vec[i].F = v[0] + delay;
		vec[i].S = v[1] + delay;
		getline(cin, ss);
		int cnt = 0;
		while (true){
			getline(cin, ss);
			if (ss.empty()) break;
			a[i].pb(ss);
		}
	}
	for (int i = 1; i <= N; i++){
		cout << i << endl;
		cout << convert(vec[i].F) << " --> " << convert(vec[i].S) << endl;
		for (string s : a[i]) cout << s << endl;
		if (i < N) cout << endl;
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