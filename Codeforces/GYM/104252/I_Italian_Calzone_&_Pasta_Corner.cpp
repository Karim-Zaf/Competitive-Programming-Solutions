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
const int N_Max = 105;
const int Nax = 1e6 + 7;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
int a[N_Max][N_Max];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M;
 
bool in_bound(int r, int c){
    return r >= 1 && r <= N && c >= 1 && c <= M;
}
 
int work(int r, int c){
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
    vector<vector<bool>> vis(N + 1, vector<bool>(M + 1));
    q.push({a[r][c], r, c});
    vis[r][c] = true;
    int ret = 0;
    while (!q.empty()){
        array<int, 3> Node = q.top();
        // dbg(Node[0]);
        q.pop();
        ret++;
        for (int i = 0; i < 4; i++){
            int new_r = Node[1] + dx[i];
            int new_c = Node[2] + dy[i];
            // cout << new_r << " " << new_c << " " << a[new_r][new_c] << endl;
            if (!in_bound(new_r, new_c) || vis[new_r][new_c]) continue;
            if (a[new_r][new_c] > Node[0]){
                // cout << a[new_r][new_c] << " ";
                vis[new_r][new_c] = true;
                q.push({a[new_r][new_c], new_r, new_c});
            }
        }
        // cout << endl;
    }
    return ret;
}
 
void solve(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            ans = max(ans, work(i, j));
        }
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