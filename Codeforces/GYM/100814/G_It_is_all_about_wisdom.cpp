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

vector<pair<int, int>> adj[N_Max];
int N, M, K;

int dijkstra(){
	vector<int> dist(N + 1, 2e9);
	set<pair<int, int>> s;
	s.insert({0, 1});
	dist[1] = 0;
	while (!s.empty()){
		auto [d, Node] = *s.begin();
		s.erase(s.begin());
		if (dist[Node] < d) continue;
		for (auto [child, cost] : adj[Node]){
			if (d + cost < dist[child]){
				dist[child] = d + cost;
				s.insert({dist[child], child});
			}
		}
	}
	return dist[N];
}

void solve(){
	cin >> N >> M >> K;
	set<int> s;
	vector<int> wisdom;
	vector<array<int, 4>> edges;
	for (int i = 1; i <= M; i++){
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		edges.push_back({u, v, c, w});
		if (s.find(w) == s.end()) wisdom.pb(w);
		s.insert(w);
	}
	sort(wisdom.begin(), wisdom.end());
	int l = 0, r = (int)wisdom.size() - 1, ans = -1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (auto [u, v, c, w] : edges){
			if (w <= wisdom[mid]){
				adj[u].push_back({v, c});
				adj[v].push_back({u, c});
			}
		}
		if (dijkstra() < K){
			ans = wisdom[mid];
			r = mid - 1;
		}
		else l = mid + 1;
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
    cin >> tc;
    while (tc--) solve();
    return 0;
}