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
 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int dist[N_Max][N_Max];
int vis[N_Max][N_Max];
char a[N_Max][N_Max];
int N, M;
 
bool in_bound(int r, int c){
	return r >= 1 && r <= N && c >= 1 && c <= M;
}
 
void bfs(){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) dist[i][j] = 1e9;
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (a[i][j] == 'E'){
				dist[i][j] = 0;
				q.push({i, j});
				vis[i][j]++;
			}
		}
	}
	while (!q.empty()){
		auto [r, c] = q.front();
		q.pop();
		for (int d = 0; d < 4; d++){
			int new_r = r + dx[d];
			int new_c = c + dy[d];
			if (!in_bound(new_r, new_c) || vis[new_r][new_c] || a[new_r][new_c] != '.') continue;
			dist[new_r][new_c] = dist[r][c] + 1;
			q.push({new_r, new_c});
			vis[new_r][new_c]++;
		}
	}
}
 
pair<int, int> get(int r, int c, char ch){
	if (ch == 'U') return make_pair(r - 1, c);
	if (ch == 'D') return make_pair(r + 1, c);
	if (ch == 'L') return make_pair(r, c - 1);
	return make_pair(r, c + 1);
}
 
void solve(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) cin >> a[i][j];
	bfs();
	int Q;
	cin >> Q;
	for (int q = 1; q <= Q; q++){
		int r, c;
		cin >> r >> c;
		if (a[r][c] != '.'){
			cout << (a[r][c] == '#' ? 'W' : a[r][c]) << endl;
			continue;
		}
		if (dist[r][c] == 1e9){
			cout << '?' << endl;
			continue;
		}
		char ans = '.';
		int mn = 2e9;
		for (auto ch: {'L', 'D', 'R', 'U'}){
			auto [new_r, new_c] = get(r, c, ch);
			if (!in_bound(new_r, new_c)) continue;
			if (dist[new_r][new_c] < mn){
				mn = dist[new_r][new_c];
				ans = ch;
			}
		}
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