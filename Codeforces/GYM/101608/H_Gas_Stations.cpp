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

string s;
int N;

bool work(int x){
	vector<int> l(N + 1), r(N + 1), vis(N + 1);
	int lst = 0;
	for (int i = 1; i <= N; i++){
		if (s[i] == '.') continue;
		l[i] = max(lst + 1, i - x);
		assert(l[i] <= i);
		for (int j = l[i]; j <= i; j++) vis[j]++;
		int j = i + 1, cnt = 0;
		while (j <= N && cnt < x && s[j] != '+'){
			vis[j]++;
			j++;
			cnt++;
		}
		r[i] = lst = j - 1;
		i = j - 1;
	}
	int cnt = 0;
	pair<int, int> p;
	for (int i = 1; i <= N; i++){
		if (vis[i]) continue;
		cnt++;
		int j = i;
		while (j <= N && !vis[j]) j++;
		p = {i, j - 1};
		i = j - 1;
	}
	if (!cnt) return true;
	if (cnt > 1) return false;
	if (p.S - p.F > 2 * x) return false;
	set<int> st;
	for (int i = 1; i <= N; i++)
		if (s[i] == '+') st.insert(i);
	for (int i = 1; i <= N; i++){
		if (s[i] == '.') continue;
		st.erase(i);
		auto it = st.lower_bound(p.S);
		int new_pos;
		if (p.S < l[i]){
			int nxt = N + 1;
			if (it != st.end()) nxt = *it;
			new_pos = min(p.F + x, nxt - 1);
		}
		else{
			int pre = 0;
			if (it != st.begin()) pre = *prev(it);
			new_pos = max(p.S - x, pre + 1);
		}
		assert(s[new_pos] == '.');
		st.insert(new_pos);
		bool good = true;
		for (int j = l[i]; j <= r[i]; j++){
			it = st.lower_bound(j);
			int best = 2e9;
			if (it != st.end()) best = min(best, *it - j);
			if (it != st.begin()) best = min(best, j - *prev(it));
			if (best > x){
				good = false;
				break;
			}
		}
		st.erase(new_pos);
		st.insert(i);
		if (good) return true;
	}
	return false;
}

void solve(){
	cin >> N >> s;	
	s = "#" + s;
	int l = 0, r = N, ans = N;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (work(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}

int main(){
    FAST
    freopen("stations.in","r",stdin);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}